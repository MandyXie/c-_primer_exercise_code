#include<fstream>
#include<iostream>
#include"Exercise_12.32.h"
using namespace std;

void runQueries(ifstream &infile)
{
   TextQuery tq(infile);
   while(true) {
      cout << "enter word to look for, or q to quit: ";
      string s;
      if(!(cin >> s) || s == "q") break;
      print(cout, tq.Query(s)) << endl;
   }
}

int main()
{
   ifstream infile("./data/storyDataFile.txt");
   runQueries(infile);
   return 0;
}

