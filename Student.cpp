#include "Student.h"

using namespace std;

Student::Student()
{
  this->id = "";
  this->name = "";
  this->isUsingComputer = false;
  this->idComputer = "";
}

Student::Student(string id, string name, bool isUsing, string idComputer)
{
  this->id = id;
  this->name = name;
  this->isUsingComputer = isUsing;
  this->idComputer = idComputer;
}

Student::~Student()
{
}

string Student::getId()
{
  return id;
}

string Student::getName()
{
  return name;
}

bool Student::getIsUsingComputer()
{
  return isUsingComputer;
}

string Student::getIdComputer()
{
  return idComputer;
}

ostream &operator<<(ostream &cout, const Student &student)
{
  return cout << "id = " << student.id << "\nname = " << student.name << "\nComputer = " << student.isUsingComputer << endl;
}