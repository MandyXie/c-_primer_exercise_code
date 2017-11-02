#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, string::size_type sz)
{
   return s.size() >= sz;
}

int main()
{
   vector<string> sentence = {"the", "libarary", "defines", "an", "algorithm", "named", "partition"};
   partition(sentence.begin(), sentence.end(), bind(check_size,_1,5));
   for(auto v:sentence) cout << v << endl;
   return 0;
}
