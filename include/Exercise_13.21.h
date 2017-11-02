#ifndef Exercise_13_21_h
#define Exercise_13_21_h
#include<memory>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<fstream>
#include<iostream>
#include<sstream>
#include"Exercise_12.22.h"
using namespace std;

class QueryResult;
class TextQuery {
public: 
   using lineNo = vector<string>::size_type;
   TextQuery(ifstream &infile){
      string text;
      while(getline(infile,text)) {
         inputText.push_back(text);
         istringstream line(text);
         string word;
         while(line >> word) {
            auto &nos = result[word];
            if(!nos) nos.reset(new set<lineNo>);           
            nos->insert(inputText.size()-1);
         }  
      }
   }
QueryResult Query(string& str) const;
private:
   StrBlob inputText;
   map<string,shared_ptr<set<lineNo>>> result;
};

class QueryResult {
public:
   using resultIter = set<TextQuery::lineNo>::iterator;
   QueryResult(const string &s, shared_ptr<set<TextQuery::lineNo>> set, StrBlob v):word(s), nos(set), input(v) {}
   friend ostream& print(ostream& out, const QueryResult& qr);
   resultIter begin() const {return nos->begin();}
   resultIter end() const {return nos->end();}
   shared_ptr<StrBlob> get_file() const {return make_shared<StrBlob>(input);}
private:
   string word;
   shared_ptr<set<TextQuery::lineNo>> nos;
   StrBlob input;
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
   for(auto i:*qr.nos) {
      ConstStrBlobPtr sbp(qr.input,i);
      out << "\t(line " << i+1 << ") " << sbp.deref() << endl;
   }
   return out;
}

#endif
