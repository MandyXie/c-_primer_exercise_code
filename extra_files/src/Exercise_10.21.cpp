#include<algorithm>
#include<iostream>
using namespace std;

void func()
{
   int v = 10;
   auto f = [&v] () {return --v? false:true;};
   while(!f())
   {
       cout << v << endl;
   }
}

int main()
{
   func();
   return 0;
}
