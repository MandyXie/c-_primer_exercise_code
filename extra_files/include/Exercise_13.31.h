#ifndef Exercise_13_31_h
#define Exercise_13_31_h

#include<string>
#include<memory>
#include<iostream>

using std::string;
using std::shared_ptr;
using std::make_shared;

class HasPtr {
public:
   friend void swap(HasPtr& lhs, HasPtr& rhs);
   friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
   HasPtr() {}
   HasPtr(const string &str=string()):hp(0),sp(new string(str)){}
   HasPtr(const HasPtr& hsp);
   HasPtr& operator=(const HasPtr& hsp);
   int gethp() const {return hp;}
   shared_ptr<string> getsp() const {return sp;}
   void swap(HasPtr &rhs)
   {
      using std::swap;
      swap(hp,rhs.hp);
      swap(sp,rhs.sp);
      std::cout << "swap it!!!!!!!!!!" << std::endl;
   }
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

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
  return *lhs.sp < *rhs.sp;
}

void swap(HasPtr& lhs, HasPtr& rhs)
{ 
  lhs.swap(rhs);
}
#endif
