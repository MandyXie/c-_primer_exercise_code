#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

bool isShorter(const string& s1, const string& s2)
{
   return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
   stable_sort(words.begin(),words.end(),isShorter);
   auto end_unique = unique(words.begin(),words.end());
   words.erase(end_unique, words.end());
}

int main()
{
   vector<string> story = {"fox","jumps","over","quick","red","red","slow","the","the", "turtle"};
   elimDups(story);
   for(auto s:story)
   {
      cout << s << " ";
   }
   cout << endl;
   return 0;
}
