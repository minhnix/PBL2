#include "Manage.h"
#include <ctime>
using namespace std;
using namespace rapidjson;

int main()
{
  Manage ql;
  // ql.listRegister.show();
  // ql.Create();
  // ql.Update();
  // ql.Delete(g);
  ql.Register();
  ql.Unregister();
  return 0;
}