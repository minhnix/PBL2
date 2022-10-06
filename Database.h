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
using namespace rapidjson;
using namespace std;

class Database
{
private:
  const char *path;

public:
  Database(const char *, Document &);
  ~Database();
  int getTotalCol(Document &);
  void writer(Document &);
  void CreateStudent(const char *id, const char *name, Document &);
  void CreateComputer(const char *id, const char *name, Document &);
  string GetStringDB(int index, const char *field, Document &);
  bool GetBoolDB(int index, const char *field, Document &);
  long long GetLLDB(int index, const char *field, Document &);
  void Update(int index, const char *name, bool isUsingComputer, const char *idComputer, Document &);
  void Update(int index, const char *name, long long timeUsed, bool beingUsed, const char *idStudent, long long registeredAt, Document &);
  void Delete(int index, Document &);
};
