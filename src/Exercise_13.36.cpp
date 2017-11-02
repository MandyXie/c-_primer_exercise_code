#include "Exercise_13.37.h"
#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::endl;

int main()
{
   Message msg("readme");
   Message msg1("home");
   Message msg2("mandy");
   Folder f;
   Folder f1;
   msg.save(f);
   msg1.save(f);
   msg1.save(f1);
   msg2.save(f1);
   msg2.save(f);
   msg.print_debug();
   msg1.print_debug();
   msg2.print_debug();
   f.print_debug();
   f1.print_debug();
   swap(msg,msg1);
   msg.print_debug();
   msg1.print_debug();
   f.print_debug();
   f1.print_debug();
   swap(f,f1);
   f.print_debug();
   f1.print_debug();
   
   return 0;   
}
