#include <iostream>
#include "ListComputer.h"
using namespace std;

int main()
{
  Location location(2, 4);
  ListComputer list;
  Computer lenovo("1", false, location, "0");
  list.add(lenovo);
  list.show();
  return 0;
}