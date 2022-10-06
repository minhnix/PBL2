#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class List
{
private:
  vector<T> list;

public:
  List(/* args */);
  ~List();
  int length();
  void add(const T &);
  void insert(const T &, int);
  int indexOf(string id);
  T at(int index);
  void removeAt(int index);
  void remove(T &);
  void update(int, T);
  void show();
};
template <class T>
List<T>::List(/* args */)
{
}
template <class T>
List<T>::~List()
{
}
template <class T>
void List<T>::add(const T &t)
{
  this->list.push_back(t);
}
template <class T>
int List<T>::length()
{
  return this->list.size();
}
template <class T>
void List<T>::insert(const T &t, int index)
{
  this->list.insert(list.begin() + index, t);
}
template <class T>
int List<T>::indexOf(string id)
{
  for (int i = 0; i < list.size(); i++)
  {
    if (list[i].getId() == id)
    {
      return i;
    }
  }
  return -1;
}
template <class T>
T List<T>::at(int index)
{
  return list[index];
}
template <class T>
void List<T>::removeAt(int index)
{
  list.erase(list.begin() + index);
}
template <class T>
void List<T>::remove(T &t)
{
  int index = this->indexOf(t);
  if (index == -1)
    return;
  this->removeAt(index);
}

template <class T>
void List<T>::show()
{
  cout << endl;
  for (int i = 0; i < list.size(); i++)
  {
    cout << list[i] << endl;
  }
}
template <class T>
void List<T>::update(int index, T t)
{
  list[index] = t;
}