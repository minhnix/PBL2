#include "Record.h"

using namespace std;
Record::Record()
{
  id = "";
  idComputer = "";
  idStudent = "";
  registeredAt = 0;
  unRegisteredAt = 0;
}
Record::Record(string id, string idComputer, string idStudent, long long registeredAt, long long unRegisteredAt)
{
  this->id = id;
  this->idComputer = idComputer;
  this->idStudent = idStudent;
  this->registeredAt = registeredAt;
  this->unRegisteredAt = unRegisteredAt;
}

Record::~Record()
{
}
map<string, string> Record::getAll()
{
  map<string, string> data;
  data["id"] = id;
  data["idComputer"] = idComputer;
  data["idStudent"] = idStudent;
  data["registeredAt"] = to_string(registeredAt);
  data["unRegisteredAt"] = to_string(unRegisteredAt);
  return data;
}
string Record::getId()
{
  return id;
};
string Record::getIdComputer()
{
  return idComputer;
};
string Record::getIdStudent()
{
  return idStudent;
};
long long Record::getRegisteredAt()
{
  return registeredAt;
};
long long Record::getUnRegisteredAt()
{
  return unRegisteredAt;
};
void Record::setIdComputer(string idComputer)
{
  this->idComputer = idComputer;
};
void Record::setIdStudent(string idStudent)
{
  this->idStudent = idStudent;
};
void Record::setRegisterAt(long long registeredAt)
{
  this->registeredAt = registeredAt;
};
void Record::setUnRegisterAt(long long unRegisteredAt)
{
  this->unRegisteredAt = unRegisteredAt;
};
bool Record::operator==(const Record &r)
{
  return (id == r.id);
}
ostream &operator<<(ostream &cout, const Record &r)
{
  return cout << "id = " << r.id << "\nidComputer = " << r.idComputer << "\nidStudent = " << r.idStudent << "\nRegister at = " << r.registeredAt << "\nUnregistered at = " << r.unRegisteredAt << endl;
}