#include "Manage.h"
#include <ctime>

using namespace std;
using namespace rapidjson;

int main()
{
  Manage ql;
  ql.Register();
  ql.Unregister();
  cout << "\nSUCCESS";
  return 0;
}