// #include "ListComputer.h"
#include "Computer.h"
#include "List.h"
#include "Student.h"
using namespace std;

int main()
{
  Location location(2, 4);
  Computer lenovo("1", false, location, "0", "102210116");
  Computer lenovo2("1", false, location, "0", "2");
  List<Computer> list;
  List<Student> listStudent;
  bool kq = (lenovo2 == lenovo);
  list.add(lenovo);
  list.show();
  cout << kq;
  return 0;
}