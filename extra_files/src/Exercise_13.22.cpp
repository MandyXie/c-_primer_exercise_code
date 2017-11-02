#include "Exercise_13.22.h"
#include<string>
#include<iostream>
using namespace std;

int main()
{
   HasPtr hsp(0,"hsp");
   HasPtr hsp1(hsp);
   hsp = hsp;
   cout << hsp.gethp() << " " << *hsp.getsp() << " " << hsp.getsp()  << endl;
   cout << hsp1.gethp() << " " << *hsp1.getsp() << " " << hsp1.getsp()  << endl;
   cout << hsp.gethp() << " " << *hsp.getsp() << " " << hsp.getsp()  << endl;
   return 0;
}
