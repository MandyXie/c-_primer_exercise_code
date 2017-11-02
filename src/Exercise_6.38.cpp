#include<iostream>

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

using arrStr = int[5];

arrStr &arrPtr(int i)
{
   return(i % 2) ? odd : even;
}

int main()
{
   for(int i = 0; i != 5; ++i)
   {
      std::cout << arrPtr(i) << std::endl;
   }
   return 0;
}
