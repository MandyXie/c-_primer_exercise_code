#include "Exercise_13.31.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;

int main()
{
   HasPtr hsp1("hsp1");
   HasPtr hsp2("hsp2");
   HasPtr hsp3("hsp3");
   HasPtr hsp4("hsp4");
   std::vector<HasPtr> hpVec{hsp3,hsp2,hsp4,hsp1};
   std::sort(hpVec.begin(),hpVec.end());
   for(auto const& hv:hpVec) cout << hv.gethp() << " " << *hv.getsp() << endl;
   return 0;
}
