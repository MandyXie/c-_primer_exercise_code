#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include"Sales_item.h"
using namespace std;

bool CompareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    vector<Sales_item> vecs= {Sales_item("Great Gasby"), Sales_item("Pride and Prejudice"), Sales_item("Good Earth")};
    sort(vecs.begin(),vecs.end(),CompareIsbn);
    for(auto v:vecs) cout << v.isbn() << endl;
    return 0;
}

