#include "Manage.h"

using namespace std;
using namespace rapidjson;

const char *PATH_DB_STUDENT = "db_student.json";
const char *PATH_DB_COMPUTER = "db_computer.json";
const char *PATH_DB_REGISTER = "db_register.json";

Manage::Manage()
    : dbStudent(Database<Student>(PATH_DB_STUDENT)), dbComputer(Database<Computer>(PATH_DB_COMPUTER)), dbRegister(Database<Record>(PATH_DB_REGISTER))
{
    for (int i = 0; i < dbRegister.getTotalCol(); i++)
        listRegister.add(Record(dbRegister.GetStringDB(i, "id"), dbRegister.GetStringDB(i, "idComputer"), dbRegister.GetStringDB(i, "idStudent"), dbRegister.GetLLDB(i, "registeredAt"), dbRegister.GetLLDB(i, "unRegisteredAt")));
    for (int i = 0; i < dbComputer.getTotalCol(); i++)
        listComputer.add(Computer(dbComputer.GetStringDB(i, "id"), dbComputer.GetStringDB(i, "name"), dbComputer.GetLLDB(i, "timeUsed")));
    for (int i = 0; i < dbStudent.getTotalCol(); i++)
        listStudent.add(Student(dbStudent.GetStringDB(i, "id"), dbStudent.GetStringDB(i, "name")));
}

Manage::~Manage()
{
}
