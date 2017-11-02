#include<string>
#include<memory>
#include<vector>
#include<exception>

using namespace std;
typedef vector<string>::size_type size_type;
class ConstStrBlobPtr;

class StrBlob {
public:
   friend class ConstStrBlobPtr;
   StrBlob():data(make_shared<vector<string>>()) {}
   ConstStrBlobPtr begin() const;
   ConstStrBlobPtr end() const;
   StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)) {}
   size_type size() const {return data->size();}
   bool empty() const {return data->empty();}
   void push_back(const string& t) {data->push_back(t);}
   string& front() {check(0,"front on empty StrBlob"); return data->front();}
   string& back() {check(0,"back on empty StrBlob"); return data->back();}
   const string& front() const {check(0,"front on empty StrBlob"); return data->front();};
   const string& back() const {check(0,"back on empty StrBlob"); return data->back();}

private:
   shared_ptr<vector<string>> data;
   void check(size_type i, const string& msg) const {if(i>=data->size()) throw out_of_range(msg);}
};           

class ConstStrBlobPtr {
public:
   ConstStrBlobPtr(): curr(0) {}
   ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
   bool operator!=(const ConstStrBlobPtr& p) {return p.curr!=curr;}
   string& deref() const {
      auto p = check(curr, "dereference pase end");
      return (*p) [curr];
   }
   ConstStrBlobPtr& incr() {
      check(curr,"increment past end of StrBlobPtr");
      ++curr;
      return *this;
   }

private:
   shared_ptr<vector<string>> check(size_t i, const string& msg) const {
      auto ret = wptr.lock();
      if(!ret)
          throw runtime_error("unbound StrBlobPtr");
      if(i >= ret->size())
          throw out_of_range(msg);
      return ret;
   } 
   weak_ptr<vector<string>> wptr;
   size_t curr;
};

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr(*this, data->size());
}
