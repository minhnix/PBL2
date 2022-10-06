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
  cout << "Danh sach cac may chua duoc dang ky" << endl;
  for (int i = 0; i < listComputer.length(); i++)
  {
    if (!listComputer.at(i).getBeingUsed())
      cout << listComputer.at(i).getId() << " " << listComputer.at(i).getName() << endl;
  }
  string mssv, name, idComputer;
  cout << "nhap mssv = ";
  cin >> mssv;
  int indexComputer, indexStudent = listStudent.indexOf(mssv);
  cin.ignore(32767, '\n');

  if (indexStudent == -1)
  {
    cout << "Ban chua dang ky. Vui long nhap ten cua ban de dang ky" << endl;
    getline(cin, name);
    indexStudent = dbStudent.getTotalCol(docStudent);
    listStudent.add(Student(mssv, name, false, ""));
    dbStudent.CreateStudent(mssv.c_str(), name.c_str(), docStudent);
  }
  if (listStudent.at(indexStudent).getIsUsingComputer())
  {
    cout << "Ban da dang ky may so " << listStudent.at(indexStudent).getIdComputer() << endl;
    return;
  }
  while (1)
  {
    cout << "nhap may can dang ky = ";
    cin >> idComputer;
    indexComputer = listComputer.indexOf(idComputer);
    if (listComputer.at(indexComputer).getBeingUsed())
      cout << "may nay da dang ky. Vui long dang ky lai" << endl;
    else
      break;
  }

  time_t now = time(0);
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
                   "-1",
                   true,
                   idComputer.c_str(),
                   docStudent);
  cout << "ban da dang ky thanh cong" << endl;
}

void Manage::Unregister()
{
  string mssv;
  cout << "nhap ma so sinh vien = ";
  cin >> mssv;
  int indexStudent = listStudent.indexOf(mssv);
  if (indexStudent == -1)
  {
    cout << "Ma so sinh vien khong ton tai!" << endl;
    return;
  }
  if (!listStudent.at(indexStudent).getIsUsingComputer())
  {
    cout << "Ban chua dang ky su dung may nao" << endl;
    return;
  }
  int indexComputer = listComputer.indexOf(listStudent.at(indexStudent).getIdComputer());
  time_t now = time(0);
  long long time = now - listComputer.at(indexComputer).getRegisteredAt() + listComputer.at(indexComputer).getTimeUsed();
  listComputer.update(indexComputer, Computer(
                                         listComputer.at(indexComputer).getId(),
                                         listComputer.at(indexComputer).getName(),
                                         0,
                                         false,
                                         "",
                                         time));
  listStudent.update(indexStudent, Student(
                                       mssv,
                                       listStudent.at(indexStudent).getName(),
                                       false,
                                       ""));
  dbComputer.Update(indexComputer,
                    "-1",
                    time,
                    false,
                    "",
                    0,
                    docComputer);
  dbStudent.Update(indexStudent,
                   "-1",
                   false,
                   "",
                   docStudent);
  cout << "Ban da huy thanh cong" << endl;
}