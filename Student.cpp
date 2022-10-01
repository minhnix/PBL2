#include "Student.h"

using namespace std;

Student::Student()
{
  this->id = "";
  this->name = "";
  this->isUsingComputer = "";
}

Student::Student(string id, string name, string idComputer)
{
  this->id = id;
  this->name = name;
  this->isUsingComputer = idComputer;
}

Student::~Student()
{
}

ostream &operator<<(ostream &cout, const Student &student)
{
  return cout << "id = " << student.id << "\nname = " << student.name << "\nComputer = " << student.isUsingComputer << endl;
}