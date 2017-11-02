#include<string>
#include<iostream>

#ifndef Excercise_7_15_h
#define Excercise_7_15_h

class Person
{
   Person() = default;
   Person(const std::string sname, const std::string saddr):name(sname),address(saddr) {}
   Person(std::istream &is);
   std::string name;
   std::string address;
 public:
   auto get_name() const {return name;}
   auto get_address() const {return address;}
};

std::istream& read(std::istream &is, Person person)
{
   is >> person.name >> person.address;
   return is;
}

std::ostream& print(std::ostream &os, const Person person)
{
   os << person.name << " " << person.address;
   return os;
}

Person::Person(std::istream is)
{
   read(is, *this);
}

#endif
