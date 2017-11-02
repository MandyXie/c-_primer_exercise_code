#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
   vector<string> vecs = {"explain", "the", "the", "difference", "among", "the", "three", "three", "kinds"};
   list<string> lst;
   
   unique_copy(vecs.begin(),vecs.end(),back_inserter(lst));
   for(auto i:lst) cout << i << " ";
   cout << endl;
   return 0;
}
