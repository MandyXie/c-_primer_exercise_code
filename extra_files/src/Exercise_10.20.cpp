#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
   vector<string> vecs = {"a", "predicate", "that", "it", "applies", "to"};
   int count = count_if(vecs.begin(),vecs.end(),
                       [] (const string& s){return s.size() > 6;});
   cout << count << endl;
   return 0;
}
