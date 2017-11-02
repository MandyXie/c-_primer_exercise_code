#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

void elimDups(vector<string> &words)
{
   sort(words.begin(),words.end());
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
