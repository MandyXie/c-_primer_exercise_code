#include "Exercise_13.22.test.h"
#include<string>
#include<iostream>
using namespace std;

int main()
{
   HasPtr hsp("hsp");
   HasPtr hsp1(hsp);
   HasPtr hsp2 = hsp;
   cout << hsp.gethp() << " " << *hsp.getsp() << " " << hsp.getsp()  << endl;
   cout << hsp1.gethp() << " " << *hsp1.getsp() << " " << hsp1.getsp()  << endl;
   cout << hsp2.gethp() << " " << *hsp2.getsp() << " " << hsp2.getsp()  << endl;
   return 0;
}
