/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：此代码段是为了演示错误继承，并非是正确完整的程序
 */
class Base    //父类
{
private:
    int private_b;
protected:
    int proteced_b;
public:
    int public_b;
};

class D : public Base    //子类，继承自base,继承类型为公有继承
{
private:
    int private_d;
protected:
    int proteced_d;
public:
    void function() {
        int d;
        d = private_b;       //error：基类中私有成员在派生类中是不可见的
        d = proteced_b;       //ok： 基类的保护成员在派生类中为保护成员
        d = public_b;       //ok： 基类的公共成员在派生类中为公共成员
    }

    int _d_pub;
};

/*总结：
 * （1）. public继承是一个接口继承，保持is-a原则，每个父类可用的成员对子类也可用， 因为每个子类对象也都是一个父类对象。
 */

class C : private Base    //基类Base的派生类C（私有继承）
{
public:
    void function() {
        int c;
        c = private_b;      //error：基类中私有成员在派生类中是不可见的
        c = proteced_b;      //ok：基类的保护成员在派生类中为私有成员
        c = public_b;      //ok：基类的公共成员在派生类中为私有成员
    }
};

class E : protected Base   //基类Base的派生类E（保护继承）
{
public:
    void function() {
        int e;
        e = private_b;    //error：基类中私有成员在派生类中是不可见的
        e = proteced_b;    //ok：基类的保护成员在派生类中为保护成员
        e = public_b;    //ok：基类的公共成员在派生类中为保护成员
    }
};

/*总结：
 *（2）. 基类的private成员 在派生类中是不能被访问的， 如果基类成员 不想在类外直接被访问，但需要 在派生类中能访问，
 * 就定义为protected。 可以看出保护成员 限定符是因继承才出现的。
 *（3）. protected/private继承是一个实现继承， 基类的部分成员 并非完全成为子类接口 的一部分，
 * 是 has-a 的关系原则， 所以非特殊情况下不会使用这两种继承关系， 在绝大多数的场景下使用的 都是公有继承。
 * 私有继承以为这is-implemented-in-terms-of(是根据……实现的) 。 通常比组合(composition) 更低级， 但当一个派生类需要访问
 * 基类保护成员 或需要重定义基类的虚函数时它就是合理的。
 */


int main() {
    int a;
    D d;
    a = d.private_b;     //error：公有继承基类中私有成员在派生类中是不可见的,对对象不可见
    a = d.proteced_b;     //error：公有继承基类的保护成员在派生类中为保护成员，对对象不可见
    a = d.public_b;     //ok：公有继承基类的公共成员在派生类中为公共成员，对对象可见
    C c;
    a = c.private_b;    //error：私有继承基类中私有成员在派生类中是不可见的, 对对象不可见
    a = c.proteced_b;    //error：私有继承基类的保护成员在派生类中为私有成员，对对象不可见
    a = c.public_b;    //error：私有继承基类的公共成员在派生类中为私有成员，对对象不可见
    E e;
    a = e.private_b;    //error：保护继承基类中私有成员在派生类中是不可见的, 对对象不可见
    a = e.proteced_b;    //error：保护继承基类的保护成员在派生类中为保护成员，对对象不可见
    a = e.public_b;    //error：保护继承基类的公共成员在派生类中为保护成员，对对象不可见

    return 0;
}
/*总结：
 *（4）. 不管是哪种继承方式， 在派生类内部都可以访问基类的公有成员和保护成员 ， 基类的私有成员存在但是在子类中不可见（ 不能访问） 。
 *（5）. 使用关键字class时默认的继承方式是private， 使用struct时默认的继承方式是public， 不过最好显式的写出继承方式。
 *（6）. 在实际运用中一般使用都是public继承， 极少场景下才会使用protetced/private继承。
 */
