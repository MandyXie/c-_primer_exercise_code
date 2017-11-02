#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

int main()
{
   multimap<string, string> authors = {
        { "alan", "DMA" },
        { "pezy", "LeetCode" },
        { "alan", "CLRS" },
        { "wang", "FTP" },
        { "pezy", "CP5" },
        { "wang", "CPP-Concurrency" }
        };

   map<string, set<string>> order_authors;
   for(const auto author:authors)
      order_authors[author.first].insert(author.second);
   for (const auto &author : order_authors) {  
      std::cout << author.first << ": ";
      for (const auto &work : author.second)
          std::cout << work << " ";
      std::cout << std::endl;
    }
   return 0;
}
