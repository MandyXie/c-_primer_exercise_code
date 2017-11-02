#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
   vector<string> vecstri = {"12","22","32"};
   vector<string> vecstrf = {"12.5", "22.5", "32.0"};

   int sumi = 0;
   int sumf = 0.0;

   for(auto vi : vecstri)
       sumi += stoi(vi);

   for(auto vf : vecstrf)
       sumf += stof(vf);
   
   cout << "sum of int = " << sumi << endl;
   cout << "sun of float = " << sumf << endl;

   return 0;
}
