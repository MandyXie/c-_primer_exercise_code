#include<string>
#include<iostream>
using namespace std;

int main()
{
    string name = "Brooks";
    string prefix = "Mr.";
    name.insert(0, prefix);
    name.append("Jr.");
    cout << name << endl;
    return 0;
}
