#ifndef Exercise_13_37_h
#define Exercise_13_37_h

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
#endif
