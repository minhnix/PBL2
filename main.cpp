#include "Computer.h"
#include "List.h"
#include "Student.h"
#include "DB.h"

using namespace std;
using namespace rapidjson;

int main()
{
  List<Student> listStudent;
  DB dbStudent("db_student.json");
  Document d;
  d.Parse(dbStudent.getDB());
  const Value &db = d.GetArray();

  for (int i = 0; i < db.Size(); i++)
  {
    listStudent.add(Student(db[i]["id"].GetString(), db[i]["name"].GetString(), db[i]["idComputer"].GetString()));
  }
  listStudent.show();
  return 0;
}