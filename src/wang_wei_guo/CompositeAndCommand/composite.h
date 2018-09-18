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

class FirstCommand:public Command{
public:
    FirstCommand(char* name):Command(name){}
    virtual void attach(Command* cpn);
    virtual void detach(Command* cpn);
    virtual void display(string str);
};

class SecondCommand:public Command{
public:
    SecondCommand(char* name):Command(name){}
    virtual void attach(Command* cpn);
    virtual void display(string str);
};

class ThirdCommand:public Command{
public:
    ThirdCommand(char* name):Command(name){}
    virtual void detach(Command* cpn);
    virtual void display(string str);

};

#endif //COMPOSITE_COMPOSITE_H
