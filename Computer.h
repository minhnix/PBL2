#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Computer
{
protected:
  string id;
  string name;
  long long timeUsed;
  bool beingUsed;
  string idStudent;
  long long registeredAt;

public:
  Computer(/* args */);
  Computer(string id, string name, long long timeUsed, bool beingUsed, string idStudent, long long registeredAt);
  ~Computer();
  bool getBeingUsed();
  string getId();
  string getName();
  bool operator==(const Computer &);
  friend ostream &operator<<(ostream &, const Computer &);
};
