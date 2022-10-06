#include "Computer.h"

using namespace std;

Computer::Computer(/* args */)
{
  id = "";
  name = "";
  timeUsed = 0;
  beingUsed = false;
  idStudent = "";
}
Computer::Computer(string id, string name, long long timeUsed, bool beingUsed, string idStudent, long long registeredAt)
{

  this->id = id;
  this->name = name;
  this->timeUsed = timeUsed;
  this->beingUsed = beingUsed;
  this->idStudent = idStudent;
  this->registeredAt = registeredAt;
}

Computer::~Computer()
{
}

bool Computer::getBeingUsed()
{
  return beingUsed;
}
string Computer::getId()
{
  return id;
}
string Computer::getName()
{
  return name;
}
string Computer::getIdStudent()
{
  return idStudent;
}
long long Computer::getTimeUsed()
{
  return timeUsed;
}
long long Computer::getRegisteredAt()
{
  return registeredAt;
}
bool Computer::operator==(const Computer &computer)
{
  return (id == computer.id);
}
ostream &operator<<(ostream &cout, const Computer &computer)
{
  return cout << "id = " << computer.id << "\nname = " << computer.name << "\ntime used = " << computer.timeUsed << "\nstudent = " << computer.idStudent << "\nregistered at = " << computer.registeredAt << endl;
}