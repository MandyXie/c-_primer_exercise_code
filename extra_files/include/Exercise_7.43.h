#include<iostream>
#include<vector>
using namespace std;

class NoDefault
{
   public:
      NoDefault(int i) {}
};

class C 
{
   public:
      C():def(0) {}
   private:
      NoDefault def;
}

int main()
{
   C c;
   std::vector<C> vec(10)

   return 0;
}

