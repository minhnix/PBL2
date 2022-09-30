#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
  string name;
  string id;
  bool isUsingComputer;
  string idComputer;

public:
  Student(/* args */);
  ~Student();
};
