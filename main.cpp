#include <iostream>
#include "ListComputer.h"
using namespace std;

int main()
{
  Location location(2, 4);
  ListComputer list;
  Computer lenovo("1", false, location, "0", "102210116");
  Computer lenovo2("1", false, location, "0", "2");
  bool kq = (lenovo2 == lenovo);
  list.add(lenovo);
  // list.show();
  cout << kq;
  return 0;
}