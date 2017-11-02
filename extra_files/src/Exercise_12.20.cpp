#include "Exercise_12.19.h"
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
   return 0;
}
