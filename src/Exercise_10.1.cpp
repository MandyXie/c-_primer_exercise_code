#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
   vector<int> veci = {1,2,3,4,5,5,6,1,3};
   int val = 3;
   int count_num = count(veci.cbegin(),veci.cend(),val);
   cout << val << " appeared for " << count_num << " times" << endl;
   return 0;
}
