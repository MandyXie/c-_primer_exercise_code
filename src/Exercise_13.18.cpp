#include<string>

using namespace std;

Employee {
public:
   Employee() {ID=incrementer++;}
   Employee(string str) name(str) {ID = incrementer++;}
private:
   string name;
   int ID;
   static int incrementer;
};

int Employee::incrementer = 0;
