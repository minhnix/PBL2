#include <iostream>
#include <string>
#include <ctime>
#include <map>

using namespace std;

class Computer
{
private:
  string id;
  string name;
  long long timeUsed;

public:
  Computer(/* args */);
  Computer(string id, string name, long long timeUsed);
  ~Computer();
  map<string, string> getAll();
  string getId();
  string getName();
  long long getTimeUsed();
  void setId(string id);
  void setName(string name);
  void setTimeUsed(long long timeUsed);
  bool operator==(const Computer &);
  friend ostream &operator<<(ostream &, const Computer &);
};
