#include <iostream>
#include <string>

using namespace std;

class Computer
{
protected:
  string id;
  string name;
  string timeUsed;
  string beingUsedByStudent;

public:
  Computer(/* args */);
  Computer(string, string, string);
  ~Computer();
  bool operator==(const Computer &);
  friend ostream &operator<<(ostream &, const Computer &);
};
