#include<iostream>
#include<vector>
using namespace std;

int main()
{
   vector<string> vec;
   string word;
   for(word; cin >> word; vec.push_back(word))
   for(auto &c : word)
   {
      c = toupper(c);
   }
   for(auto c : word)
   {
      cout << c;
   }
   cout << endl;
   return 0;
}
