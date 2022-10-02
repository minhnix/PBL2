#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/pointer.h"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
using namespace rapidjson;
using namespace std;

class Database
{
private:
public:
  Database(const char *, Document &);
  ~Database();
  int getTotalCol(Document &);
  void writer(const char *, Document &);
  void Create(const char *__id, const char *__name, const char *__idComputer, const char *__path, Document &);
  void Create(const char *__id, const char *__name, const char *__timeUsed, const char *__idStudent, const char *__path, Document &);
  string Read(int __index, const char *__field, Document &);
  void Update(int __index, const char *__name, const char *__idComputer, const char *__path, Document &);
  void Update(int __index, const char *__name, const char *__timeUsed, const char *__idStudent, const char *__path, Document &);
  void Delete(int __index, const char *__path, Document &);
};
