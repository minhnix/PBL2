#include "Computer.h"
#include "List.h"
#include "Student.h"
#include "Database.h"

using namespace std;
using namespace rapidjson;

const char *PATH_DB_STUDENT = "db_student.json";
const char *PATH_DB_COMPUTER = "db_student.json";

int main()
{
  List<Student> listStudent;
  List<Computer> listComputer;
  Document docStudent, docComputer;
  Database dbStudent(PATH_DB_STUDENT, docStudent); // lấy database
  Database dbComputer(PATH_DB_COMPUTER, docComputer);
  char id[] = "102210140";
  char name[] = "Vinh";
  char idComputer[] = "2";
  dbStudent.Create(id, name, idComputer, PATH_DB_STUDENT, docStudent);
  cout << dbStudent.Read(2, "name", docStudent); // đọc database, số 2, key "name", trả về string
  dbStudent.Update(5, name, idComputer, PATH_DB_STUDENT, docStudent);
  dbStudent.Delete(9, PATH_DB_STUDENT, docStudent);
  cout << "\nSUCCESS";
  return 0;
}