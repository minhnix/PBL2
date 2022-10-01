#include "DB.h"
using namespace rapidjson;
using namespace std;

DB::DB(string path)
{
  ifstream file(path, ios::binary);
  file.read(db, 100000);
}
DB::~DB()
{
}
char *DB::getDB()
{
  return db;
}