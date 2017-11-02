#ifndef Exercise_12_27_h
#define Exercise_12_27.h
#include<memory>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

class QueryResult;
class TextQuery {
public: 
   using lineNo = vector<string>::size_type;
   TextQuery(ifstream &infile): inputText(new vector<string>) {
      string text;
      while(getline(infile,text)) {
         inputText->push_back(text);
         istringstream line(text);
         string word;
         while(line >> word) {
            auto &nos = result[word];
            if(!nos) nos.reset(new set<lineNo>);           
            nos->insert(inputText->size()-1);
         }  
      }
   }
QueryResult Query(string& str) const;
private:
   shared_ptr<vector<string>> inputText;
   map<string,shared_ptr<set<lineNo>>> result;
};

class QueryResult {
public:
   QueryResult(const string &s, shared_ptr<set<TextQuery::lineNo>> set, shared_ptr<vector<string>> v):word(s), nos(set), input(v) {}
   friend ostream& print(ostream& out, const QueryResult& qr);
private:
   string word;
   shared_ptr<set<TextQuery::lineNo>> nos;
   shared_ptr<vector<string>> input;
};

QueryResult TextQuery::Query(string& str) const {
   static shared_ptr<set<lineNo>> nodata(new set<TextQuery::lineNo>);
   auto found = result.find(str);
   if(found == result.end()) return QueryResult(str, nodata, inputText);
   else return QueryResult(str,found->second, inputText);
}

ostream& print(ostream& out, const QueryResult& qr)
{
   out << qr.word << " occurs " << qr.nos->size() << " times" << endl;
   for(auto i:*qr.nos)
      out << "\t(line " << i+1 << ") " << qr.input->at(i) << endl;
   return out;
}

#endif
