#include<string>
#include<memory>
#include<iostream>
using namespace std;

class HasPtr {
public:
   HasPtr() {}
   HasPtr(int hp_, string str):hp(hp_),sp(new string(str)){}
   HasPtr(const HasPtr& hsp);
   HasPtr& operator=(const HasPtr& hsp);
   int gethp() const {return hp;}
   shared_ptr<string> getsp() const {return sp;}
   friend void swap(HasPtr& lhs, HasPtr& rhs);
private:
   int hp;
   shared_ptr<string> sp;
};

HasPtr::HasPtr(const HasPtr& hasp)
{
  hp = hasp.hp;
  sp = make_shared<string>(*hasp.sp);
}

HasPtr& HasPtr::operator=(const HasPtr& hsp)
{
  hp = hsp.hp;
  sp = make_shared<string>(*hsp.sp);
  return *this;
}

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
  using std::swap;
  swap(lhs.hp,rhs.hp);
  swap(lhs.sp,rhs.sp);
  std::cout << "swap it!!!!!!!!!!" << std::endl;
}
