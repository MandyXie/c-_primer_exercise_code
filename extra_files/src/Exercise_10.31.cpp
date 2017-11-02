#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
   istream_iterator<int> in(cin), eof;
   vector<int> vec;
   copy(in, eof, back_inserter(vec));
   sort(vec.begin(),vec.end());
   unique_copy(vec.cbegin(),vec.cend(),ostream_iterator<int>(cout, " "));
   return 0;
}
