#include<iostream>
#include<string>
using namespace std;

int main()
{
   string rsp;
   do{
     cout << "Input two strings: ";
     string str1;
     string str2;
     cin >> str1 >> str2;
     cout << (str1 < str2 ? str1 : str2)
          << " is less than the other." << endl << endl
          << "More? Enter yes or no: ";
     cin >> rsp;
   }while(!rsp.empty() && tolower(rsp[0] == 'y'));

   return 0;
}
