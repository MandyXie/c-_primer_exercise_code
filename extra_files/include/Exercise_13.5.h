#include<string>
#include<memory>
using namespace std;

class HasPtr{
public:
   HasPtr(const string &s = string()):ps(new string(s),i(0)) {}
   HasPtr(const HasPtr& hp):ps(new string(*hp.hs),i(hp.i)) {}
private:
   string *ps;
   int i;
};
