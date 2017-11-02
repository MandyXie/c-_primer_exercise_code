#ifndef Exercise_13_12_h
#define Exercise_13_12_h
#include<iostream>

using namespace std;

struct X{
public:
   X() {cout << "X()" << endl;}
   X(const X&) {cout << "X(const X&)" << endl;}
   X& operator=(const X& x) {cout << "X& operator=(const X&)"<<endl; return *this;}
   ~X() {cout << "~X()" << endl;}
};

#endif
