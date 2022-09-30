#include <vector>
#include <algorithm>
#include "Computer.h"

using namespace std;

class ListComputer
{
private:
  vector<Computer> list;

public:
  ListComputer(/* args */);
  ~ListComputer();
  int length();
  void add(const Computer &);
  void insert(const Computer &, int);
  int indexOf(Computer &);
  Computer at(int index);
  void removeAt(int index);
  void remove(Computer &);
  void update(int);
  void show();
};
