/*
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-15
 * 功能描述：
 */
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Element;

/*
 * 类名：Visitor
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-15
 * 功能描述：Visitor的抽象类;
 */
class Visitor{
public:
    virtual void visit(Element *element){};
};

/*
 * 类名：Element
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-15
 * 功能描述：Element的抽象类;
 */
class Element{
public:
    virtual void accept(Visitor *visitor){};
};

/*
 * 类名：Employee
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-15
 * 功能描述：Element的具体类;
 */
class Employee : public Element{
public:
    string name;
    double income;
    int vacationDays;

    Employee(string name, double income,int vacationDays){
        this->name = name;
        this->income = income;
        this->vacationDays = vacationDays;
    }

    void accept(Visitor *vistor){
        vistor->visit(this);
    };
};

/*
 * 类名：IncomeVisitor
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-15
 * 功能描述：Visitor的具体类;
 */
class IncomeVisitor :public Visitor{
public:
    void visit(Element *element){
        Employee *employee = ((Employee*)element);
        employee->income *= 1.10;
        cout<<employee->name<<"'s new income:"<<employee->income<<endl;
    }
};

/*
 * 类名：VacationVisitor
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-15
 * 功能描述：Visitor的具体类;
 */
class VacationVisitor : public Visitor{
public:
    void visit(Element *element){
        Employee *employee = ((Employee*)element);
        employee->vacationDays += 3;
        cout<<employee->name<<"'s new vacation days :"<<employee->vacationDays<<endl;
    }
};

/*
 * 类名：Employees
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-15
 * 功能描述：Employee的迭代器
 */
class Employees{
private:
    list<Employee *> employees;
public:
    void attach(Employee *employee){
        employees.push_back(employee);
    }

    void detach(Employee *employee){
        employees.remove(employee);
    }

    void accept(Visitor *visitor){
        list<Employee*>::iterator it;
        it = employees.begin();
        while(it != employees.end()){
            (*it)->accept(visitor);
            it++;
        }
    }
};

int main() {
    Employees *employees = new Employees();
    employees->attach(new Employee("Tom" , 25000.0 , 14));
    employees->attach(new Employee("Thomas" , 35000.0 , 16));
    employees->attach(new Employee("Roy" , 45000.0 , 21));

    IncomeVisitor *visitor1 = new IncomeVisitor();
    VacationVisitor *visitor2 = new VacationVisitor();

    employees->accept(visitor1);
    employees->accept(visitor2);

    return 0;
}