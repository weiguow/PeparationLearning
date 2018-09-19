//
// Created by wwg on 18-9-8.
//

#ifndef COMPOSITE_COMPOSITE_H
#define COMPOSITE_COMPOSITE_H

#include <list>
using std::list;

#include <string>
using std::string;

class Command
{
public:
    Command(char* name):mName(name){}
    virtual void attach(Command* cpn){}
    virtual void detach(Command* cpn){}
    virtual void display(string str){}
protected:
    char *mName;
    list<Command*> mList;
};

class ConcreteCommandA:public Command{
public:
    ConcreteCommandA(char* name):Command(name){}
    virtual void attach(Command* cpn);
    virtual void detach(Command* cpn);
    virtual void display(string str);
};

class ConcreteCommandB:public Command{
public:
    ConcreteCommandB(char* name):Command(name){}
    virtual void attach(Command* cpn);
    virtual void display(string str);
};

class ConcreteCommandC:public Command{
public:
    ConcreteCommandC(char* name):Command(name){}
    virtual void detach(Command* cpn);
    virtual void display(string str);

};

#endif //COMPOSITE_COMPOSITE_H
