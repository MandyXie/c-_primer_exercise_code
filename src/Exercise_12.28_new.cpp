#include<memory>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<fstream>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

using lineNo = vector<string>::size_type;

void textQuery(ifstream &infile, vector<string> &input, map<string,set<lineNo>> &result)
{
    string text;
    while(getline(infile,text)) {
    input.push_back(text);
    istringstream line(text);
    string word;
       while(line >> word) 
       {
          result[word].insert(input.size()-1);
       }
    }
}

void query(string &str, set<lineNo> &nos, map<string,set<lineNo>> &result) 
{
   static set<lineNo> nodata = {};
   auto found = result.find(str);
   if(found == result.end()) {
      nos = nodata;
   }
   else {
      nos = found->second;
   }
}

ostream& print(ostream& out, string &str, set<lineNo> &nos, vector<string> input, map<string, set<lineNo>> &result)
{
   query(str, nos, result);
   out << str << " occurs " << nos.size() << " times " << endl;
   for(auto i:nos)
      out <<  "\t(line " << i+1 << ") " << input.at(i) << endl;
   return out;
}

void runQueries(ifstream &infile, vector<string> &input, set<lineNo> nos, map<string,set<lineNo>> &result)
{
   textQuery(infile, input, result);
   while(true) {
      cout << "enter word to look for, or q to quit: ";
      string s;
      if(!(cin >> s) || s == "q") break;
      print(cout, s, nos, input, result) << endl;
   }
}

int main()
{
   ifstream infile("./data/storyDataFile.txt");
   vector<string> input;
   map<string,set<lineNo>> result;
   set<lineNo> nos;
   runQueries(infile,input,nos,result);
   return 0;
}

