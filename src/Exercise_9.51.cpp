#include<string>
#include<iostream>
using namespace std;

class DATE
{
public:
   DATE(string const& s)
   {
      unsigned tag = 0;
      unsigned format = 0;
      // 1/1/1900
      if(s.find_first_of("/")!=string::npos)
         format = 0x01;
      
      // January 1, 1900 or Jan 1 1900
      if((s.find_first_of(",") >= 4) && s.find_first_of(",")!=string::npos)
         format = 0x10;
      else // Jan 1 1900
      {
         if((s.find_first_of(" ") >= 3) && s.find_first_of(" ")!=string::npos)
         {    
             format = 0x10;
             tag = 1;
         }
      }
      
      switch(format)
      {
      case 0x01:
         day = stoi(s.substr(0, s.find_first_of("/")));
         month = stoi(s.substr(s.find_first_of("/") + 1, s.find_last_of("/")-s.find_first_of("/")));
         year = stoi(s.substr(s.find_last_of("/") + 1, 4));
         break;

      case 0x10:
         if( s.find("Jan") < s.size() )  month = 1;
         if( s.find("Feb") < s.size() )  month = 2;
         if( s.find("Mar") < s.size() )  month = 3;
         if( s.find("Apr") < s.size() )  month = 4;
         if( s.find("May") < s.size() )  month = 5;
         if( s.find("Jun") < s.size() )  month = 6;
         if( s.find("Jul") < s.size() )  month = 7;
         if( s.find("Aug") < s.size() )  month = 8;
         if( s.find("Sep") < s.size() )  month = 9;
         if( s.find("Oct") < s.size() )  month =10;
         if( s.find("Nov") < s.size() )  month =11;
         if( s.find("Dec") < s.size() )  month =12;       

         string chr = ",";
         if(tag == 1) chr = " ";
         day = stoi(s.substr(s.find_first_of("0123456789"), s.find_first_of(chr) - s.find_first_of("0123456789")));
         year = stoi(s.substr(s.find_first_of(chr)+1, 4));
         break;
      }
   }
   
   void print()
   {
      cout << "day: " << day << " " << "month: " << month << " " << "year: " << year << endl;
   }

private:   
   unsigned year, month, day;
};

int main()
{
   DATE d("Jan 1 1900");
   d.print();
   DATE d1("January 1,1900");
   d1.print();
   DATE d2("1/1/1900");
   d2.print();
   return 0;
}
