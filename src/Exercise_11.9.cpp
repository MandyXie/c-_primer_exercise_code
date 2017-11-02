#include<map>
#include<list>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
   map<string,list<size_t>> m;
   
   map<vector<int>::iterator, int> mv;
   map<list<int>::iterator, int> ml;
   
   vector<int> vi;
   mv.insert(pair<vector<int>::iterator,int>(vi.begin(),0));

   list<int> li;
   ml.insert(pari<list<int>::iterator,int>(li.begin(),0));

   return 0;
}
