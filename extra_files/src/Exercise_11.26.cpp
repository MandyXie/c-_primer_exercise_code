#include<map>
#include<string>
#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
   map<int, string> m = {{1,"ss"},{2,"sz"}};
   using KeyType = map<int, string>::key_type;
   
   cout << "type to subsript: " << typeid(KeyType).name() << endl;
   cout << "returned from the subsript operator: " << typeid(decltype(m[1])).name() << endl;

   return 0;
}
