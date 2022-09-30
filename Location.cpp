#include "Location.h"

Location::Location(/* args */)
{
  x = 0;
  y = 0;
}
Location::Location(int x, int y)
{
  this->x = x;
  this->y = y;
}

Location::~Location()
{
}
int Location::getLocationX()
{
  return this->x;
}
int Location::getLocationY()
{
  return this->y;
}
void Location::setLocation(int x, int y)
{
  this->x = x;
  this->y = y;
}
bool Location::operator==(const Location &location)
{
  return (x == location.x) && (y == location.y);
}
ostream &operator<<(ostream &cout, const Location &location)
{
  return cout << "x = " << location.x << ", y = " << location.y << endl;
}