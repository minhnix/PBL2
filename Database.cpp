#include "Database.h"
using namespace rapidjson;
using namespace std;

const char *NO_UPDATE = "-1";

Database::Database(const char *path, Document &db)
    : path(path)
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
void Database::writer(Document &db)
{
  FILE *fo = fopen(path, "wb");
  char writeBuffer[1000000];
  FileWriteStream os(fo, writeBuffer, size(writeBuffer));
  Writer<FileWriteStream> writer(os);
  db.Accept(writer);
  fclose(fo);
}
void Database::CreateStudent(const char *id, const char *name, Document &db)
{
  string col = "/" + to_string(getTotalCol(db));
  Pointer((col + "/id").c_str()).Set(db, id);
  Pointer((col + "/name").c_str()).Set(db, name);
  Pointer((col + "/isUsingComputer").c_str()).Set(db, false);
  Pointer((col + "/idComputer").c_str()).Set(db, "");
  writer(db);
}
void Database::CreateComputer(const char *id, const char *name, Document &db)
{
  string col = "/" + to_string(getTotalCol(db));
  Pointer((col + "/id").c_str()).Set(db, id);
  Pointer((col + "/name").c_str()).Set(db, name);
  Pointer((col + "/timeUsed").c_str()).Set(db, 0);
  Pointer((col + "/beingUsed").c_str()).Set(db, false);
  Pointer((col + "/idStudent").c_str()).Set(db, "");
  Pointer((col + "/registeredAt").c_str()).Set(db, 0);
  writer(db);
}
string Database::GetStringDB(int index, const char *field, Document &db)
{
  return db.GetArray()[index][field].GetString();
}
bool Database::GetBoolDB(int index, const char *field, Document &db)
{
  return db.GetArray()[index][field].GetBool();
}
long long Database::GetLLDB(int index, const char *field, Document &db)
{
  return db.GetArray()[index][field].GetInt64();
}
void Database::Update(int index, const char *name, bool isUsingComputer, const char *idComputer, Document &db)
{
  if (index >= getTotalCol(db))
  {
    cout << "index too large";
    return;
  }
  if (0 != strcmp(name, NO_UPDATE))
    Pointer(("/" + to_string(index) + "/name").c_str()).Set(db, name);
  Pointer(("/" + to_string(index) + "/isUsingComputer").c_str()).Set(db, isUsingComputer);
  if (0 != strcmp(idComputer, NO_UPDATE))
    Pointer(("/" + to_string(index) + "/idComputer").c_str()).Set(db, idComputer);
  writer(db);
}
void Database::Update(int index, const char *name, long long timeUsed, bool beingUsed, const char *idStudent, long long registeredAt, Document &db)
{
  if (index >= getTotalCol(db))
  {
    cout << "index too large\n";
    return;
  }
  if (0 != strcmp(name, NO_UPDATE))
    Pointer(("/" + to_string(index) + "/name").c_str()).Set(db, name);
  if (timeUsed != -1)
    Pointer(("/" + to_string(index) + "/timeUsed").c_str()).Set(db, timeUsed);
  Pointer(("/" + to_string(index) + "/beingUsed").c_str()).Set(db, beingUsed);
  if (0 != strcmp(idStudent, NO_UPDATE))
    Pointer(("/" + to_string(index) + "/idStudent").c_str()).Set(db, idStudent);
  if (registeredAt != -1)
    Pointer(("/" + to_string(index) + "/registeredAt").c_str()).Set(db, registeredAt);
  writer(db);
}
void Database::Delete(int index, Document &db)
{
  if (index >= getTotalCol(db))
  {
    cout << "index too large\n";
    return;
  }
  Pointer(("/" + to_string(index)).c_str()).Erase(db);
  writer(db);
}
