//
// Created by mandy on 17-11-2.
//

#include "Exercise_13.37.h"

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folders(const Message& m)
{
    for(auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_folders()
{
    for(auto f : folders)
        f->remMsg(this);
}

Message::Message(const Message& m):
        contents(m.contents), folders(m.folders)
{
    add_to_folders(m);
}

Message::~Message()
{
    std::cout << "~Message()" << std::endl;
    remove_from_folders();
}

Message& Message::operator=(const Message& m)
{
    remove_from_folders();
    contents = m.contents;
    folders = m.folders;
    add_to_folders(m);
    return *this;
}

void Message::print_debug()
{
    std::cout << contents << std::endl;
}

void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    for(auto f : lhs.folders) f->remMsg(&lhs);
    for(auto f : rhs.folders) f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f : lhs.folders) f->addMsg(&lhs);
    for(auto f : rhs.folders) f->addMsg(&rhs);
}

void Folder::add_to_messages(const Folder& f)
{
    for(auto m : f.messages) m->addFolder(this);
}

void Folder::remove_from_messages()
{
    for(auto m : messages) m->remFolder(this);
}

Folder::~Folder()
{
    std::cout << "~Folder()" << std::endl;
    remove_from_messages();
}

Folder& Folder::operator=(Folder& f)
{
    remove_from_messages();
    messages = f.messages;
    add_to_messages(f);
    return *this;
}

void Folder::print_debug()
{
    for(auto m : messages)
    {
        std::cout << m->contents << " ";
    }
    std::cout << std::endl;
}

void swap(Folder& lhs, Folder& rhs)
{
    using std::swap;
    lhs.remove_from_messages();
    rhs.remove_from_messages();
    swap(lhs.messages, rhs.messages);
    lhs.add_to_messages(lhs);
    rhs.add_to_messages(rhs);
}