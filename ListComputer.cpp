#include "ListComputer.h"
using namespace std;

ListComputer::ListComputer(/* args */)
{
}

ListComputer::~ListComputer()
{
}

void ListComputer::add(const Computer &computer)
{
  this->list.push_back(computer);
}
int ListComputer::length()
{
  return this->list.size();
}
void ListComputer::insert(const Computer &computer, int index)
{
  this->list.insert(list.begin() + index, computer);
}
int ListComputer::indexOf(Computer &computer)
{
  for (int i = 0; i < list.size(); i++)
  {
    if (list[i] == computer)
    {
      return i;
    }
  }
  return -1;
}
Computer ListComputer::at(int index)
{
  return list[index];
}
void ListComputer::removeAt(int index)
{
  list.erase(list.begin() + index);
}
void ListComputer::remove(Computer &computer)
{
  int index = this->indexOf(computer);
  if (index == -1)
    return;
  this->removeAt(index);
}
void ListComputer::show()
{
  cout << endl;
  for (int i = 0; i < list.size(); i++)
  {
    cout << list[i] << endl;
  }
}