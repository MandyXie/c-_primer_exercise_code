#include <iostream>
using namespace std;

class numbered {
public:
    numbered() {
        cout << "defulat constructor"<<endl;
        mysn = unique++;
    }

    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(numbered s) {
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}
