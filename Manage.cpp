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
void Manage::Create()
{
    string id, name;
    cout << "Nhap thong tin may tinh moi\n";
    cout << "ID may tinh: ";
    getline(cin, id);
    if (listComputer.indexOf(id) != -1)
    {
        cout << "ID may da ton tai\n";
        return;
    }
    cout << "Ten may: ";
    getline(cin, name);
    Computer computer(id, name, 0);
    listComputer.add(computer);
    dbComputer.Create(computer);
    cout << "Da tao thanh cong\n";
}
void Manage::Update()
{
    string id, name;
    cout << "Nhap thong tin can sua\n";
    cout << "ID may tinh can sua: ";
    getline(cin, id);
    int index = listComputer.indexOf(id);
    if (index == -1)
    {
        cout << "May nay khong ton tai\n";
        return;
    }
    cout << "Nhap ten moi: ";
    getline(cin, name);
    listComputer.at(index).setName(name);
    dbComputer.Update(index, "name", name.c_str());
    cout << "Da sua thanh cong\n";
}
void Manage::Delete()
{
    string id;
    cout << "Nhap id may muon xoa: ";
    getline(cin, id);
    int index = listComputer.indexOf(id);
    if (index == -1)
    {
        cout << "May nay khong ton tai\n";
        return;
    }
    listComputer.removeAt(index);
    dbComputer.Delete(index);
    int i = 0;
    while (i < listRegister.length())
    {
        if (listRegister.at(i).getIdComputer() == id)
        {
            listRegister.removeAt(i);
            dbRegister.Delete(i);
        }
        else
            i++;
    }
}
void Manage::Register()
{
    cout << "Danh sach cac may tinh chua dang ky\n";
    vector<string> listId;
    for (int i = 0; i < listRegister.length(); i++)
    {
        if (listRegister.at(i).getUnRegisteredAt() == 0)
            listId.push_back(listRegister.at(i).getIdComputer());
    }
    for (int i = 0; i < listComputer.length(); i++)
    {
        bool oke = true;
        for (int j = 0; j < listId.size(); j++)
            if (listComputer.at(i).getId() == listId[j])
            {
                oke = false;
                break;
            }
        if (oke)
            cout << listComputer.at(i);
    }
}