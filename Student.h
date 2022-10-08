#include <iostream>
#include <string>
#include <map>
using namespace std;

class Student
{
private:
  string id;
  string name;

public:
  Student(/* args */);
  Student(string id, string name);
  ~Student();
  map<string, string> getAll();
  string getId();
  string getName();
  void setId(string id);
  void setName(string name);
  bool operator==(const Student &);
  friend ostream &operator<<(ostream &, const Student &);
};
