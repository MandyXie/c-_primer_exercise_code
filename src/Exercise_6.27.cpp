#include<iostream>
#include<initializer_list>

int summary(std::initializer_list<int> const &list)
{
   int sum = 0;
   for(auto i: list) sum += i;
   return sum;
}

int main()
{
   auto il = {1, 2, 3, 4, 5, 6};
   std::cout << summary(il) << std::endl;
   return 0;
}
