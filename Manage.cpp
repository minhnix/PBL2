#include "Manage.h"

using namespace std;
using namespace rapidjson;

const char *PATH_DB_STUDENT = "db_student.json";
const char *PATH_DB_COMPUTER = "db_computer.json";

Document docStudent, docComputer;

Manage::Manage()
    : dbComputer(Database(PATH_DB_COMPUTER, docComputer)), dbStudent(Database(PATH_DB_STUDENT, docStudent))
{
  for (int i = 0; i < dbStudent.getTotalCol(docStudent); i++)
  {
    listStudent.add(Student(dbStudent.GetStringDB(i, "id", docStudent), dbStudent.GetStringDB(i, "name", docStudent), dbStudent.GetBoolDB(i, "isUsingComputer", docStudent), dbStudent.GetStringDB(i, "idComputer", docStudent)));
  }
  for (int i = 0; i < dbComputer.getTotalCol(docComputer); i++)
  {
    listComputer.add(Computer(dbComputer.GetStringDB(i, "id", docComputer), dbComputer.GetStringDB(i, "name", docComputer), dbComputer.GetLLDB(i, "timeUsed", docComputer), dbComputer.GetBoolDB(i, "beingUsed", docComputer), dbComputer.GetStringDB(i, "idStudent", docComputer), dbComputer.GetLLDB(i, "registeredAt", docComputer)));
  }
}

Manage::~Manage()
{
}

void Manage::Register()
{
  cout << "Danh sach cac may chua dc dang ky" << endl;
  for (int i = 0; i < listComputer.length(); i++)
  {
    if (!listComputer.at(i).getBeingUsed())
      cout << listComputer.at(i).getId() << " " << listComputer.at(i).getName() << endl;
  }
  string mssv, idComputer;
  cout << "nhap mssv = ";
  cin >> mssv;
  cout << "nhap may can dang ky = ";
  cin >> idComputer;

  int indexComputer = listComputer.indexOf(idComputer);
  if (listComputer.at(indexComputer).getBeingUsed())
    cout << "may nay da dang ky, dang ky lai";
  // fix
  time_t now = time(0);

  int indexStudent = listStudent.indexOf(mssv);
  listComputer.update(indexComputer, Computer(
                                         listComputer.at(indexComputer).getId(),
                                         listComputer.at(indexComputer).getName(),
                                         0,
                                         true,
                                         mssv,
                                         now));
  listStudent.update(indexStudent, Student(
                                       mssv,
                                       listStudent.at(indexStudent).getName(),
                                       true,
                                       idComputer));
  dbComputer.Update(indexComputer,
                    listComputer.at(indexComputer).getName().c_str(),
                    0,
                    true,
                    mssv.c_str(),
                    now,
                    docComputer);
  dbStudent.Update(indexStudent,
                   listStudent.at(indexComputer).getName().c_str(),
                   true,
                   idComputer.c_str(),
                   docStudent);
  cout << "ban da dang ky thanh cong";
}

void Manage::Unregister()
{
}