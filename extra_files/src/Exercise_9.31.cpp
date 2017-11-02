#include<list>
#include<iostream>
using namespace std;

int main()
{
    list<int> li = {0,1,2,3,4,5,6,7,8,9};
    auto curr = li.begin();
    while(curr != li.end())
    {
        if(*curr%2)
        {
            curr = li.insert(curr, *curr);
            ++curr;
            ++curr; 
        }
        else
            curr = li.erase(curr);
    }
    for(auto l:li) cout << l << endl;
    return 0;
}
