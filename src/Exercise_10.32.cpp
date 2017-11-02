#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<numeric>
#include"Sales_item.h"
using namespace std;

int main()
{
   istream_iter<Sales_item> in_iter(cin), in_eof;
   vector<Sales_item> vec;
   
   while(in_iter!=in_eof)
      vec.push_back(*in_iter++);
   sort(vec.begin(),vec.end(),compareIsbn);
   for(auto beg=vec.cbegin(),end=beg; beg!=vec.cend; beg = end)
   {
      end = find_if(beg,vec.cend(), [beg](const Sales_item &item){return item.isbn()!=beg->isbn();});
      cout << accumulate(beg,end,Sales_item(beg->isbn())) << endl;
   }
}
