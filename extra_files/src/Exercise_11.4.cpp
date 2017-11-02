#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

auto strip(string& str) -> string const&
{
    for (auto& ch : str) ch = tolower(ch);
    str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
    return str;
}

int main()
{
   map<string, size_t> word_count;
   string word;
   while(cin >> word)
       ++word_count[strip(word)];

   for(auto &w:word_count)
       cout << w.first << " occers " << w.second << " times" << endl;

   return 0;
}
