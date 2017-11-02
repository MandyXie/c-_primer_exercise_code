//
// Created by mandy on 17-11-2.
//

#ifndef EXERCISE_CODE_CLION_EXERCISE_13_39_H
#define EXERCISE_CODE_CLION_EXERCISE_13_39_H

#include<string>
#include<iostream>
#include<utility>
using std::string

class StrVec{
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec&operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    string *begin() const {return elements;}
    string *end() const {return first_free;}

private:
    std::allocator<string> alloc;
    void check_n_alloc()_{if(size() == capacity()) reallocate();}
    std::pair<string*,string*> alloc_n_copy(const string*,const string*);
    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;

};

#endif //EXERCISE_CODE_CLION_EXERCISE_13_39_H
