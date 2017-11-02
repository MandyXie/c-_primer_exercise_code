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
   return s.size() >= sz;
}

bool isShorter(const string &s1, const string &s2)
{
   return s1.size() < s2.size();
}

int main()
{
   vector<string> words = {"use", "first", "element", "in", "vector"};
   stable_sort(words.begin(),words.end(),isShorter);
   auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, 6));
   auto count = words.end() - wc;
   cout << count << endl;
   return 0;
}
