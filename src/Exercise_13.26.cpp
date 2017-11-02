#include "Exercise_13.26.h"
#include<fstream>
#include<iostream>
using namespace std;

int main()
{
   StrBlob sb;
   ifstream ifs("./data/book.txt");
   for(string str; getline(ifs,str); )
      sb.push_back(str);
   for(StrBlobPtr pbeg(sb.begin()),pend(sb.end()); pbeg!=pend; pbeg.incr())
      cout << pbeg.deref() << endl;
   cout << endl;
   StrBlob sb1(sb);
   StrBlob sb2 = sb;
   for(StrBlobPtr pbeg(sb1.begin()),pend(sb1.end()); pbeg!=pend; pbeg.incr())
      cout << pbeg.deref() << endl;
   cout << endl;
   for(StrBlobPtr pbeg(sb2.begin()),pend(sb2.end()); pbeg!=pend; pbeg.incr())
      cout << pbeg.deref() << endl;
   return 0;
}
