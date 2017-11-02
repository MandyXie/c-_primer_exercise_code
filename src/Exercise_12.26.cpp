#include<string>
#include<memory>
#include<iostream>

using namespace std;

int main()
{
   int n = 5;
   allocator<string> alloc;
   auto const p = alloc.allocate(n);
   string s;
   auto q = p;
   while(q!=p+n && cin >> s)
      alloc.construct(q++,s);

   while(q != p)
   {
      cout << *--q << " ";
      alloc.destroy(q);
   }
   alloc.deallocate(p,n);
   return 0;
}
