#ifndef Exercise_7.2.h
#define Exercise_7.2.h

#include<string>
struct Sales_data
{
   std::string isbn() const {return bookNo;};
   Sales_data& combine(const Sales_data&);
   
   std::string bookNo;
   unsigned units_sold = 0;
   double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
   units_sold += rhs.units_sold;
   revenue += rhs.units_sold;
   return *this;
}

#endif
