#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>
using namespace std;
using std::placeholders::_1;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
   return s.size() < sz;
}

int main()
{
   vector<int> veci = {1,2,3,4,5,6,7,8,9};
   string s = "string";
   auto wc = find_if(veci.begin(), veci.end(), bind(check_size, s, _1));
   cout << *wc << endl;
   return 0;
}
