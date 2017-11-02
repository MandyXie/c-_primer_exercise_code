#include<vector>
#include<iterator>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
   ifstream ifs("./data/input.txt");
   ofstream ofs_odd("./data/odd.txt"), ofs_even("./data/even.txt");
   istream_iterator<int> in(ifs),eof;
   ostream_iterator<int> out_odd(ofs_odd," "), out_even(ofs_even, "\n");
   for_each(in,eof,[&out_odd, &out_even](const int i){*(i%2?out_odd:out_even)++=i;});
   return 0;
}
