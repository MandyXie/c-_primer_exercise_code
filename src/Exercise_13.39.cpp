//
// Created by mandy on 17-11-2.
//

#include "../include/Exercise_13.39.h"
#include <iostream>
using std::string;

void StrVec::push_back(const string & s)
{
    check_n_alloc();
    alloc.construct(first_free,s);
}

std::pair<string*,string*> StrVec::alloc_n_copy(const string *, const string *) {}