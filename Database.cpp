#include "Database.h"
using namespace rapidjson;
using namespace std;

const char *NO_UPDATE = "-1";

Database::Database(const char *path, Document &db)
{
  FILE *fi = fopen(path, "rb");
  char DB[1000000];
  FileReadStream input(fi, DB, sizeof(DB));
  db.ParseStream(input);
  fclose(fi);
}
Database::~Database()
{
}
int Database::getTotalCol(Document &db)
{
  return db.GetArray().Size();
}
void Database::writer(const char *path, Document &db)
{
  FILE *fo = fopen(path, "wb");
  char writeBuffer[1000000];
  FileWriteStream os(fo, writeBuffer, size(writeBuffer));
  Writer<FileWriteStream> writer(os);
  db.Accept(writer);
  fclose(fo);
}
void Database::Create(const char *id, const char *name, const char *idComputer, const char *path, Document &db)
{
  string col = "/" + to_string(getTotalCol(db));
  Pointer((col + "/id").c_str()).Set(db, id);
  Pointer((col + "/name").c_str()).Set(db, name);
  Pointer((col + "/idComputer").c_str()).Set(db, idComputer);
  writer(path, db);
}
void Database::Create(const char *id, const char *name, const char *timeUsed, const char *idStudent, const char *path, Document &db)
{
  string col = "/" + to_string(getTotalCol(db));
  Pointer((col + "/id").c_str()).Set(db, id);
  Pointer((col + "/name").c_str()).Set(db, name);
  Pointer((col + "/timeUsed").c_str()).Set(db, timeUsed);
  Pointer((col + "/idStudent").c_str()).Set(db, idStudent);
  writer(path, db);
}
string Database::Read(int index, const char *field, Document &db)
{
  return db.GetArray()[index][field].GetString();
}
void Database::Update(int index, const char *name, const char *idComputer, const char *path, Document &db)
{
  if (index >= getTotalCol(db))
  {
    cout << "index too large";
    return;
  }
  if (0 != strcmp(name, NO_UPDATE))
    Pointer(("/" + to_string(index) + "/name").c_str()).Set(db, name);
  if (0 != strcmp(idComputer, NO_UPDATE))
    Pointer(("/" + to_string(index) + "/idComputer").c_str()).Set(db, idComputer);
  writer(path, db);
}
void Database::Update(int index, const char *name, const char *timeUsed, const char *idStudent, const char *path, Document &db)
{
  if (index >= getTotalCol(db))
  {
    cout << "index too large\n";
    return;
  }
  if (0 != strcmp(name, NO_UPDATE))
    Pointer(("/" + to_string(index) + "/name").c_str()).Set(db, name);
  if (0 != strcmp(timeUsed, NO_UPDATE))
    Pointer(("/" + to_string(index) + "/timeUsed").c_str()).Set(db, timeUsed);
  if (0 != strcmp(idStudent, NO_UPDATE))
    Pointer(("/" + to_string(index) + "/idStudent").c_str()).Set(db, idStudent);
  writer(path, db);
}
void Database::Delete(int index, const char *path, Document &db)
{
  if (index >= getTotalCol(db))
  {
    cout << "index too large\n";
    return;
  }
  Pointer(("/" + to_string(index)).c_str()).Erase(db);
  writer(path, db);
}
