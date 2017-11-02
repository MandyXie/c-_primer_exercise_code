#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<iterator>
using namespace std;

int main()
{
   ifstream in("./data/storyDataFile.txt");
   istream_iterator<string> str_iter(in), eof;
   vector<string> vecs(str_iter, eof);
   
   copy(vecs.begin(),vecs.end(),ostream_iterator<string>(cout," "));
   return 0;
}
