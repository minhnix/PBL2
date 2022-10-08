#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/pointer.h"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>

using namespace rapidjson;
using namespace std;

template <class T>
class Database
{
private:
  const char *path;
  Document db;

public:
  Database(const char *);
  ~Database();
  int getTotalCol();
  void writer();
  void Create(T);                                   // Thêm 1 đối tượng T vào database. Ví dụ: dbStudent.Create(Student(id, name)); dbComputer.Create(Computer(id, name, timeUsed))
  string GetStringDB(int index, const char *field); // lấy ra 1 chuỗi trong database, tại {} thứ index, trường field. dbStudent.GetStringDB(0, "id");
  long long GetLLDB(int index, const char *field);
  void Update(int index, const char *field, const char *value); // sửa thằng {} thứ index, trường field, với giá trị mới là value (string) hoặc (long long)
  void Update(int index, const char *field, long long value);
  void Delete(int index); // xoá thằng {} thứ index
};
template <class T>
Database<T>::Database(const char *path)
    : path(path)
{
  FILE *fi = fopen(path, "rb");
  char DB[1000000];
  FileReadStream input(fi, DB, sizeof(DB));
  db.ParseStream(input);
  fclose(fi);
}
template <class T>
Database<T>::~Database()
{
}
template <class T>
int Database<T>::getTotalCol()
{
  return db.GetArray().Size();
}
template <class T>
void Database<T>::writer()
{
  FILE *fo = fopen(path, "wb");
  char writeBuffer[1000000];
  FileWriteStream os(fo, writeBuffer, size(writeBuffer));
  Writer<FileWriteStream> writer(os);
  db.Accept(writer);
  fclose(fo);
}
template <class T>
void Database<T>::Create(T t)
{
  string col = "/" + to_string(getTotalCol());
  map<string, string> data = t.getAll();
  int count = data.size();
  int length = count;
  for (auto &x : data)
  {
    string key = x.first;
    string value = x.second;
    long long valueLL = atoll(value.c_str());
    if ((length > 2) && ((count == 1) || ((count == 2) && valueLL != 0)))
    {
      // set long long
      Pointer((col + "/" + key).c_str()).Set(db, valueLL);
    }
    else
    {
      // set string
      Pointer((col + "/" + key).c_str()).Set(db, value.c_str());
    }
    count--;
  }
  writer();
}
template <class T>
string Database<T>::GetStringDB(int index, const char *field)
{
  return db.GetArray()[index][field].GetString();
}
template <class T>
long long Database<T>::GetLLDB(int index, const char *field)
{
  return db.GetArray()[index][field].GetInt64();
}
template <class T>
void Database<T>::Update(int index, const char *field, const char *value)
{
  if (index >= getTotalCol())
  {
    cout << "index too large";
    return;
  }
  Pointer(("/" + to_string(index) + "/" + string(field)).c_str()).Set(db, value);
  writer();
}
template <class T>
void Database<T>::Update(int index, const char *field, long long value)
{
  if (index >= getTotalCol())
  {
    cout << "index too large";
    return;
  }
  Pointer(("/" + to_string(index) + "/" + string(field)).c_str()).Set(db, value);
  writer();
}
template <class T>
void Database<T>::Delete(int index)
{
  if (index >= getTotalCol())
  {
    cout << "index too large\n";
    return;
  }
  Pointer(("/" + to_string(index)).c_str()).Erase(db);
  writer();
}