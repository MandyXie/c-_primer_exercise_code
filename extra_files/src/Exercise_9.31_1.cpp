#include<forward_list>
#include<iostream>
using namespace std;

int main()
{
    forward_list<int> li = {0,1,2,3,4,5,6,7,8,9};
    auto prev = li.before_begin();
    auto curr = li.begin();
    while(curr != li.end())
    {
        if(*curr%2)
        {
            curr = li.insert_after(prev, *curr);
            ++curr;
            prev = curr;
            ++curr;
        }
        else
        {
            curr = li.erase_after(prev);
        }
    }
    for(auto l:li) cout << l << endl;
    return 0;
}
