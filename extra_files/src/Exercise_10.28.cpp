#include<list>
#include<iterator>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
   list<int> vec = {1,2,3,4,5,6,7,8,9};
   list<int> vec1;
   list<int> vec2;
   list<int> vec3;

   copy(vec.cbegin(), vec.cend(), inserter(vec1,vec1.begin()));
   copy(vec.cbegin(), vec.cend(), back_inserter(vec2));
   copy(vec.cbegin(), vec.cend(), front_inserter(vec3));

   for(auto v:vec1) cout << v << " ";
   cout << endl;
   for(auto v:vec2) cout << v << " ";
   cout << endl;
   for(auto v:vec3) cout << v << " ";
   cout << endl;
}
