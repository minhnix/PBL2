#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
  string id;
  string name;
  bool isUsingComputer;
  string idComputer;

public:
  Student(/* args */);
  Student(string id, string name, bool isUsingComputer, string idComputer);
  ~Student();
  string getId();
  string getName();
  bool operator==(const Student &);
  friend ostream &operator<<(ostream &, const Student &);
};
