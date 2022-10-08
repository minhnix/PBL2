#include "Student.h"

using namespace std;

Student::Student()
{
  this->id = "";
  this->name = "";
}

Student::Student(string id, string name)
{
  this->id = id;
  this->name = name;
}

Student::~Student()
{
}
map<string, string> Student::getAll()
{
  map<string, string> data;
  data["id"] = id;
  data["name"] = name;
  return data;
}
string Student::getId()
{
  return id;
}
string Student::getName()
{
  return name;
}
void Student::setId(string id)
{
  this->id = id;
};
void Student::setName(string name)
{
  this->name = name;
}
ostream &operator<<(ostream &cout, const Student &student)
{
  return cout << "id = " << student.id << "\nname = " << student.name << endl;
}