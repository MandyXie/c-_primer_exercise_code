#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

int main()
{
   map<string,size_t> word_count;
   vector<string> exclude = {"the","but","and","or"};
   string word;
   while(cin >> word)
      if(find(exclude.begin(),exclude.end(),word) == exclude.end())
         ++word_count[word];
   return 0;
}
