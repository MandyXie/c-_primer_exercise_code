#include <string>
using namespace std;

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) , use(new size_t(1)){ }
    HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) {++*use; }
    HasPtr& operator=(const HasPtr &hp) {
        ++*hp.use;
        if(--*use == 0)
        {
           delete ps;
           delete use;
        }
        ps = hp.ps;
        i = hp.i;
        use = hp.use;
        return *this;
    }
    ~HasPtr() {
        if(--*use == 0)
        {
           delete ps;
           delete use;
        }
    }
    int gethp() {return i;}
    string* getsp() {return ps;} 
private:
    std::string *ps;
    int i;
    size_t *use;
};
