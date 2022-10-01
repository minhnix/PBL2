#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
  string id;
  string name;
  string isUsingComputer;

public:
  Student(/* args */);
  Student(string, string, string);
  ~Student();
  bool operator==(const Student &);
  friend ostream &operator<<(ostream &, const Student &);
};
