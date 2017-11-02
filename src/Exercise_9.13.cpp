#include<vector>
#include<list>
#include<iostream>
using namespace std;

int main()
{
list<int> li(10,1);
vector<int> veci(10,2);

vector<double> vecd(li.begin(), li.end());
for(auto i : li) cout << i << " ";
cout << endl;
for(auto i : vecd) cout << i << " ";
cout << endl;

vector<double> vecd1(veci.begin(),veci.end());
for(auto i : veci) cout << i << " ";
cout << endl;
for(auto i : vecd1) cout << i << " ";
cout << endl;

return 0;
}
