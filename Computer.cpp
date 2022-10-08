#include "Computer.h"

using namespace std;

Computer::Computer(/* args */)
{
  id = "";
  name = "";
  timeUsed = 0;
}
Computer::Computer(string id, string name, long long timeUsed)
{

  this->id = id;
  this->name = name;
  this->timeUsed = timeUsed;
}

Computer::~Computer()
{
}
map<string, string> Computer::getAll()
{
  map<string, string> data;
  data["id"] = id;
  data["name"] = name;
  data["timeUsed"] = to_string(timeUsed);
  return data;
}
string Computer::getId()
{
  return id;
}
string Computer::getName()
{
  return name;
}
long long Computer::getTimeUsed()
{
  return timeUsed;
}
void Computer::setId(string id)
{
  this->id = id;
};
void Computer::setName(string name)
{
  this->name = name;
}
void Computer::setTimeUsed(long long timeUsed)
{
  this->timeUsed = timeUsed;
}
bool Computer::operator==(const Computer &computer)
{
  return (id == computer.id);
}
ostream &operator<<(ostream &cout, const Computer &computer)
{
  return cout << "id = " << computer.id << "\nname = " << computer.name << "\ntime used = " << computer.timeUsed << "\nstudent = " << endl;
}