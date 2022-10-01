#include "rapidjson/document.h"
#include <fstream>
#include <string>
using namespace rapidjson;
using namespace std;

class DB
{
private:
  char db[1000000];

public:
  DB(string);
  ~DB();
  char *getDB();
  void Create();
  void Read();
  void Update();
  void Delete();
};

// DB db_computer("db_computer.json");
