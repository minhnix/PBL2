#include "Computer.h"

using namespace std;

Computer::Computer(/* args */)
{
  id = "";
  beingUsed = false;
  location = Location();
  timeUsed = "0";
}
Computer::Computer(string id, bool beingUsed, Location location, string timeUsed)
{

  this->id = id;
  this->beingUsed = beingUsed;
  this->location = location;
  this->timeUsed = timeUsed;
}

Computer::~Computer()
{
}

bool Computer::operator==(const Computer &computer)
{
  return (id == computer.id) && (beingUsed == computer.beingUsed) && (location == computer.location) && (timeUsed == computer.timeUsed);
}
ostream &operator<<(ostream &cout, const Computer &computer)
{
  return cout << "id = " << computer.id << "\nbeing used = " << computer.beingUsed << "\nlocation: " << computer.location << "time used = " << computer.timeUsed << endl;
}