#include<string>

using namespace std;

Employee {
public:
   Employee() {ID=incrementer++;}
   Employee(const string str) name(str) {ID = incrementer++;}
   Employee(const Employee&) = delete;
   Employee& operator=(const Employee&) = delete;
   const int id() const {return ID;}
private:
   string name;
   int ID;
   static int incrementer;
};

int Employee::incrementer = 0;
