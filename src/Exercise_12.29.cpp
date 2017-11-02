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

void textQuery(ifstream &infile, shared_ptr<vector<string>> input, map<string,shared_ptr<set<lineNo>>> &result)
{
    string text;
    while(getline(infile,text)) {
    input->push_back(text);
    istringstream line(text);
    string word;
       while(line >> word) {
          auto &nos = result[word];
          if(!nos) nos.reset(new set<lineNo>);
          nos->insert(input->size()-1);
       }
    }
}

void query(string &str, shared_ptr<set<lineNo>> nos, map<string,shared_ptr<set<lineNo>>> &result) 
{
   static shared_ptr<set<lineNo>> nodata(new set<lineNo>);
   auto found = result.find(str);
   if(found == result.end()) {
      *nos = *nodata;
   }
   else {
      *nos = *found->second;
   }
}

ostream& print(ostream& out, string &str, shared_ptr<set<lineNo>> nos,  shared_ptr<vector<string>> input, map<string,shared_ptr<set<lineNo>>> &result)
{
   query(str, nos, result);
   for(auto n:*nos)
         cout << n << endl;
   cout << "nos size = " << nos->size() << endl;
   out << str << " occurs " << nos->size() << " times " << endl;
   for(auto i:*nos)
      out <<  "\t(line " << i+1 << ") " << input->at(i) << endl;
   return out;
}

void runQueries(ifstream &infile, shared_ptr<vector<string>> input, shared_ptr<set<lineNo>> nos, map<string,shared_ptr<set<lineNo>>> &result)
{
   textQuery(infile, input, result);
   string s;
   do{
      cout << "enter word to look for, or q to quit: ";
      if(!(cin >> s) || s == "q") break;
      print(cout, s, nos, input, result) << endl;
   } while(true);
}

int main()
{
   ifstream infile("./data/storyDataFile.txt");
   shared_ptr<vector<string>> input = make_shared<vector<string>>();
   map<string,shared_ptr<set<lineNo>>> result;
   shared_ptr<set<lineNo>> nos = make_shared<set<lineNo>>();
   runQueries(infile,input,nos,result);
   return 0;
}

