#ifndef Exercise_13_11_h
#define Exercise_13_11_h
#include<string>
#include<memory>
using namespace std;

class HasPtr{
public:
   HasPtr(const string &s = string()):ps(new string(s),i(0)) {}
   HasPtr(const HasPtr& hp):ps(new string(*hp.hs),i(hp.i)) {}
   ~HasPtr() {delete ps;}
   HasPtr& operator=(const HasPtr& hp);
private:
   string *ps;
   int i;
};

HasPtr& HasPtr::operator=(const HasPtr& hp)
{
   if(this != &hp)
   {
      string *temp_ps = new string(*hp.ps);
      delete ps;
      ps = temp_ps;
      i = hp.i
   }
   return *this;
}
#endif
