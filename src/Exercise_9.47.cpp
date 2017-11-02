#include<string>
#include<iostream>
using namespace std;

void find_num(string const& str, string const& str_num)
{
   string::size_type pos = 0;
   while((pos = str.find_first_of(str_num, pos)) != string::npos)
   {
       cout << "found number at index: " << pos
            << " element is " << str[pos] << endl;
       ++pos;
   }
}

void find_char(string const& str, string const& str_num)
{
   string::size_type pos = 0;
   while((pos = str.find_first_not_of(str_num, pos)) != string::npos)
   {
       cout << "found char at index: " << pos
            << " element is " << str[pos] << endl;
       ++pos;
   }
}

int main()
{
   string str = "ab2c3d7R4E6";
   string str_num = "0123456789";
   find_num(str, str_num);
   find_char(str, str_num);
   return 0;
}
