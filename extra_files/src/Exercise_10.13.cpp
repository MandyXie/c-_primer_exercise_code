#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

bool fiveOrMoreChar(const string& s)
{
   return s.size() >= 5;
}

int main()
{
   vector<string> sentence = {"the", "libarary", "defines", "an", "algorithm", "named", "partition"};
   partition(sentence.begin(), sentence.end(), fiveOrMoreChar);
   for(auto v:sentence) cout << v << endl;
   return 0;
}
