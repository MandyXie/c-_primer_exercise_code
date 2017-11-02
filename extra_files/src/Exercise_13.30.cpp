#include "Exercise_13.30.h"
#include<string>
#include<iostream>
using std::cout;
using std::endl;

int main()
{
   HasPtr hsp1(1,"hsp1");
   HasPtr hsp2(2,"hsp2");
   cout << hsp1.gethp() << " " << *hsp1.getsp() << " " << hsp1.getsp()  << endl;
   cout << hsp2.gethp() << " " << *hsp2.getsp() << " " << hsp2.getsp()  << endl;
   swap(hsp1,hsp2);
   cout << hsp1.gethp() << " " << *hsp1.getsp() << " " << hsp1.getsp()  << endl;
   cout << hsp2.gethp() << " " << *hsp2.getsp() << " " << hsp2.getsp()  << endl;
   return 0;
}
