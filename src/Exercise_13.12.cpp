#include"Exercise_13.12.h"
#include<iostream>
#include<vector>

using namespace std;

void ref(X& x)
{
   cout << "pass X as reference parameters" << endl;
}

void nonref(X x)
{
   cout << "pass X as non reference parameters" << endl;
}

int main()
{
   cout << "define x:" << endl;
   X x;
   ref(x);
   nonref(x);

   cout << "dynamiclly allocate x: " << endl;
   X *xx = new X;

   cout << "put 10 X in vector:" << endl;
   vector<X> vecX(1,x);

   cout << "push back X in vector: " << endl;
   vector<X> vecX1;
   vecX1.push_back(x);

   cout << "assign:" << endl;
   X x1 = x;

   cout << "delete X: " << endl;
   delete xx;
   return 0;
}
