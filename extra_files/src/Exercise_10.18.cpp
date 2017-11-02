#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

void elimDups(vector<string> &words)
{
   sort(words.begin(),words.end());
   auto end_unique = unique(words.begin(),words.end());
   words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
   elimDups(words);
   stable_sort(words.begin(),words.end(), 
               [](const string& a, const string&b)
                 {return a.size() < b.size();});
   auto wc = partition(words.begin(),words.end(),[sz](const string& a)
                                               {return a.size() > sz;});

   for_each(words.begin(), wc,[] (const string& s) {cout << s << " ";});
   cout << endl;
}

int main()
{
   vector<string> story = {"fox","jumps","over","quick","red","red","slow","the","the", "turtle"};
   biggies(story,4);
   return 0;
}
