#include "Computer.h"
#include "List.h"
#include "Student.h"
#include "Database.h"

using namespace std;
using namespace rapidjson;

class Manage
{
private:
  List<Computer> listComputer;
  List<Student> listStudent;
  Database dbStudent;
  Database dbComputer;

public:
  Manage();
  ~Manage();
  void Create();
  void Update();
  void Delete();
  void Register();
  void Unregister();
  void Show();
};
