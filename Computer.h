#include <string>
#include "Location.h"

using namespace std;

class Computer
{
protected:
  string id;
  bool beingUsed;
  Location location;
  string timeUsed;

public:
  Computer(/* args */);
  Computer(string, bool, Location, string);
  ~Computer();
  bool operator==(const Computer &);
  friend ostream &operator<<(ostream &, const Computer &);
};
