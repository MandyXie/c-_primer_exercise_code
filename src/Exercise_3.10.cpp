#include<iostream>
#include<string>
using namespace std;

int main()
{
   cout << "Enter a string of charaters including punctuation."<<endl;
   for(string s; getline(cin,s);cout<<endl)
      for(auto c : s)
      {
         if(!ispunct(c))
            cout << c;
      }
   return 0;
}
