#include "Computer.h"

using namespace std;

Computer::Computer(/* args */)
{
  id = "";
  timeUsed = "0";
  beingUsedByStudent = "";
}
Computer::Computer(string id, string timeUsed, string idStudent)
{

  this->id = id;
  this->timeUsed = timeUsed;
  this->beingUsedByStudent = idStudent;
}

Computer::~Computer()
{
}

bool Computer::operator==(const Computer &computer)
{
  return (id == computer.id);
}
ostream &operator<<(ostream &cout, const Computer &computer)
{
  return cout << "id = " << computer.id << "time used = " << computer.timeUsed << "\nstudent = " << computer.beingUsedByStudent << endl;
}