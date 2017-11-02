#include<string>
#include<iostream>

#ifndef Excercise_7.4.h
#define Excercise_7.4.h

class Person
{
   std::string name;
   std::string address;
 public:
   auto get_name() const {return name;}
   auto get_address() const {return address;}
};

istream& read(istream &is, Person person)
{
   is >> person.name >> person.address;
   return is;
}

ostream& print(ostream &os, const Person person)
{
   os << person.name << " " << person.address;
   return os;
}

#endif
