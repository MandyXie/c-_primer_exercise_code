#include<iostream>
#include<vector>
using namespace std;

int main()
{
   vector<int> vecint;
   for(int i; cin >> i; vecint.push_back(i));
   cout << endl;
   auto size = vecint.size();
   if(size%2 !=0) size = size/2 + 1;
   else size /= 2; 
   for(int i = 0; i < size; i++)
   {
      cout << vecint[i] + vecint[vecint.size()-1-i] << " " ;
   }
   cout << endl;
}
