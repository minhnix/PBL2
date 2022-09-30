#include <iostream>

using namespace std;

class Location
{
private:
  int x, y;
  // x is row
  // y is col
public:
  Location(/* args */);
  Location(int, int);
  int getLocationX();
  int getLocationY();
  void setLocation(int, int);
  ~Location();
  bool operator==(const Location &);
  friend ostream &operator<<(ostream &, const Location &);
};
