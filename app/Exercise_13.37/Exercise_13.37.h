//
// Created by mandy on 17-11-2.
//

#ifndef EXERCISE_CODE_CLION_EXERCISE_13_37_H
#define EXERCISE_CODE_CLION_EXERCISE_13_37_H

#include<string>
#include<set>
#include<iostream>
#include<algorithm>

class Folder;
class Message{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str= ""):contents(str) {};
    Message(const Message&);
    Message& operator=(const Message&);
    void save(Folder &f);
    void remove(Folder &f);
    ~Message();
    void print_debug();

private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_folders(const Message&);
    void remove_from_folders();
    void addFolder(Folder* f) {folders.insert(f);}
    void remFolder(Folder* f) {folders.erase(f);}
};

class Folder{
    friend class Message;
    friend void swap(Folder&, Folder&);
    friend void swap(Message &lhs, Message &rhs);
public:
    Folder() = default;
    Folder(const Folder& f):messages(f.messages) {}
    Folder& operator=(Folder& f);
    ~Folder();
    void print_debug();
private:
    std::set<Message*> messages;
    void addMsg(Message* msg) {messages.insert(msg);}
    void remMsg(Message* msg) {messages.erase(msg);}
    void add_to_messages(const Folder& f);
    void remove_from_messages();
};

#endif //EXERCISE_CODE_CLION_EXERCISE_13_37_H
