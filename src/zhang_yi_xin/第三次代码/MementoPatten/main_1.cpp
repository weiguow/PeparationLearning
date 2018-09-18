#include <iostream>
#include <string>
using namespace std;
class Prototype
{
public:
    virtual Prototype *Clone() = 0;
    virtual void display() = 0;
};

class Prototype1:public Prototype
{
protected:
    string name;
    int id;
public:
    Prototype1(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
    Prototype1(const Prototype1 &type)
    {
        this->name = type.name;
        this->id = type.id;
    }
    virtual void display()
    {
        cout<< "my name and id are :" << this->id << " "<<this->name <<endl;
    }

    Prototype *Clone()
    {
        return new Prototype1(*this);
    }

};
class Prototype2:public Prototype
{
protected:
    string name;
public:
    Prototype2(string name)
    {
        this->name = name;
    }
    Prototype2(const Prototype2 &type)
    {
        this->name = type.name;
    }
    virtual void display()
    {
        cout << "my name is :" << this->name << endl;
    }
    Prototype *Clone()
    {
        return new Prototype2(*this);
    }

};

int main()
{
    Prototype *obj1 = new Prototype1("mafuli",1);
    Prototype *obj2 = obj1->Clone();
    Prototype *obj3 = obj2->Clone();

    obj2->display();
    obj3->display();

    Prototype *obj4 = new Prototype2("cxue");
    Prototype *obj5 = obj4->Clone();
    Prototype *obj6 = obj5->Clone();

    obj4->display();
    obj5->display();
    obj6->display();


    getchar();
    return 0;
}
