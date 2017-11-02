#include"Exercise_12.27.h"
#include<algorithm>

QueryResult TestQuery::Query(string& str) const {
      static shared_ptr<set<lineNo>> nodata(new set<TestQuery::lineNo>);
      auto found = result.find(str);
      if(found == result.end()) return QueryResult(str, nodata, inputText);
      else return QueryResult(str,found->second, inputText);
}

ostream& print(ostream& out, const QueryResult& qr)
{
   out << qr.word << " occurs " << qr.nos->size() << "times" << endl;
   for(auto i:*qr.nos)
      out << "\t(line " << i+1 << ") " << qr.input->at(i) << endl;
   return out;
}

