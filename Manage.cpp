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
    string idComputer, idStudent;
    cout << "Nhap mssv: ";
    getline(cin, idStudent);
    int indexStudent = listStudent.indexOf(idStudent);
    if (indexStudent == -1)
    {
        cout << "Ban chua dang ky. Vui long nhap ten de dang ky: ";
        string name;
        getline(cin, name);
        listStudent.add(Student(idStudent, name));
        dbStudent.Create(listStudent.at(listStudent.length() - 1));
        cout << "Ban da dang ky mssv thanh cong\n";
    }
    for (int i = 0; i < listRegister.length(); i++)
    {
        if (idStudent == listRegister.at(i).getIdStudent() && listRegister.at(i).getUnRegisteredAt() == 0)
        {
            cout << "Ban da dang ky may so " << listRegister.at(i).getIdComputer() << endl;
            return;
        }
    }
    bool oke = true;
    while (oke)
    {
        oke = false;
        cout << "Nhap id may tinh can dang ky: ";
        getline(cin, idComputer);
        for (int i = 0; i < listId.size(); i++)
        {
            if (idComputer == listId[i])
            {
                cout << "May nay da dang ky\n";
                oke = true;
                break;
            }
        }
    }
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string id = idStudent + idComputer + to_string(now);
    listRegister.add(Record(id, idComputer, idStudent, now, 0));
    dbRegister.Create(listRegister.at(listRegister.length() - 1));
    cout << "Ban da dang ky thanh cong vao luc " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
}
void Manage::Unregister()
{
    cout << "Nhap mssv cua ban: ";
    string idStudent, idComputer;
    int indexRegister;
    getline(cin, idStudent);
    bool oke = true;
    for (int i = 0; i < listRegister.length(); i++)
    {
        if (idStudent == listRegister.at(i).getIdStudent() && listRegister.at(i).getUnRegisteredAt() == 0)
        {
            oke = false;
            indexRegister = i;
            idComputer = listRegister.at(i).getIdComputer();
            break;
        }
    }
    if (oke)
    {
        cout << "Ban chua dang ky may nao\n";
        return;
    }
    time_t now = time(0);
    int indexComputer = listComputer.indexOf(idComputer);
    long long timeUsed = listComputer.at(indexComputer).getTimeUsed() + (now - listRegister.at(indexRegister).getRegisteredAt());
    listComputer.at(indexComputer).setTimeUsed(timeUsed);    // update timeUsed Computer
    listRegister.at(indexRegister).setUnRegisterAt(now);     // update unRegistered time
    dbComputer.Update(indexComputer, "timeUsed", timeUsed);  // save database
    dbRegister.Update(indexRegister, "unRegisteredAt", now); // save database
    cout << "Ban da huy dang ky thanh cong\n";
}