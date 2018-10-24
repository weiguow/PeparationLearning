/*
 *作者:heldon 764165887@qq.com
 *编写日期：18-9-14
 *功能描述：
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

class subject;
/*
 * 类名：ShapeObserver
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：Shape观察者的抽象类
 * 版本：
 */
class ShapeObserver {
protected:
    string m_name;
    subject *m_subject;
public:
    ShapeObserver(string m_name, subject *m_subject) {
        this->m_name = m_name;
        this->m_subject = m_subject;
    }
    virtual void draw() = 0;
};

/*
 * 类名：TwoDimensional
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：二维图形的观察者
 * 版本：
 */
class TwoDimensional : public ShapeObserver{
public:
    TwoDimensional(std::string m_name, subject *m_subject) : ShapeObserver(m_name, m_subject) {}
    void add_shape(TwoDimensional* twoDimensional);
    void remove_shape(TwoDimensional* twoDimensional);
    void draw();
protected:
    list<TwoDimensional *> m_two_dimensional;
};

/*
 * 类名：Circle
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：二维图形中的圆形
 * 版本：
 */
class Circle : public TwoDimensional{
public:
    Circle(string m_name, subject *m_subject) : TwoDimensional(m_name, m_subject) {}
    virtual void draw();
};

/*
 * 类名：Triangle
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：二维图形中的三角形
 * 版本：
 */
class Triangle : public TwoDimensional{
public:
    Triangle(string m_name, subject *m_subject) : TwoDimensional(m_name, m_subject) {}
    virtual void draw();
};

/*
 * 类名：Rectangle
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：二维图形中的矩形
 * 版本：
 */
class Rectangle : public TwoDimensional{
public:
    Rectangle(string m_name, subject *m_subject) : TwoDimensional(m_name, m_subject) {}
    virtual void draw();
};

/*
 * 类名：ThreeDimensional
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：三维图形的观察者
 * 版本：
 */
class ThreeDimensional : public ShapeObserver{
public:
    ThreeDimensional(string m_name, subject *m_subject) : ShapeObserver(m_name, m_subject) {}
    void add_shape(ThreeDimensional* threeDimensional);
    void remove_shape(ThreeDimensional* threeDimensional);
    void draw();
protected:
    list<ThreeDimensional *> m_three_dimensional;
};

/*
 * 类名：Sphere
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：三维图形中的球体
 * 版本：
 */
class Sphere : public ThreeDimensional{
public:
    Sphere(string m_name, subject *m_subject) : ThreeDimensional(m_name, m_subject) {}
    virtual void draw();
};

/*
 * 类名：Pyramid
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：三维图形中的锥体
 * 版本：
 */
class Pyramid : public ThreeDimensional{
public:
    Pyramid(string m_name, subject *m_subject) : ThreeDimensional(m_name, m_subject) {}
    virtual void draw();
};

/*
 * 类名：Cuboid
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：三维图形中的长方体
 * 版本：
 */
class Cuboid : public ThreeDimensional{
public:
    Cuboid(string m_name, subject *m_subject) : ThreeDimensional(m_name, m_subject) {}
    virtual void draw();
};

/*
 * 类名：subject
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：目标类的抽象类
 * 版本：
 */
class subject {
protected:
    list<ShapeObserver *> m_observers;
public:
    virtual void attach(ShapeObserver *) = 0;
    virtual void detach(ShapeObserver *) = 0;
    virtual void notify() = 0;
    virtual void operation() = 0;
};

/*
 * 类名：Pencil
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 功能描述：具体目标类：画笔
 * 版本：
 */
class Pencil : public subject {
    /*
     * 函数名：attach
     * 作者：heldon 764165887@qq.com
     * 编写日期：18-9-14
     * 输入参数：Observer *observer
     * 返回值：无
     * 功能描述：添加一个观察者
     */
    void attach(ShapeObserver *observer){
        m_observers.push_back(observer);
    }

    /*
     * 函数名：detach
     * 作者：heldon 764165887@qq.com
     * 编写日期：18-9-14
     * 输入参数：Observer *observer
     * 返回值：无
     * 功能描述：删除一个观察者
     */
    void detach(ShapeObserver *observer){
        m_observers.remove(observer);
    }

    /*
     * 函数名：notify
     * 作者：heldon 764165887@qq.com
     * 编写日期：18-9-14
     * 输入参数：Observer *observer
     * 返回值：无
     * 功能描述：遍历观察者,每个观察者执行update()函数。
     */
    void notify(){
        list<ShapeObserver *> :: iterator it = m_observers.begin();
        while(it != m_observers.end()){
            (*it)->draw();
            ++it;
        }
    }
    void operation(){
        cout<<"拿起了画笔"<<endl;

    }
};

/*
 * 函数名：draw
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 输入参数：无
 * 返回值：无
 * 功能描述：遍历观察者,每个观察者执行draw()函数。
 */
void TwoDimensional::draw(){
    cout<<"画出"<<m_name<<":"<<endl;
    list<TwoDimensional *>::iterator beg = m_two_dimensional.begin();
    for( ; beg != m_two_dimensional.end() ; beg++){
        (*beg)->draw();
    }
}

void Circle::draw() {
    cout<<"画了一个"<<m_name<<endl;
}

void Triangle::draw(){
    cout<<"画了一个"<<m_name<<endl;
}

void Rectangle::draw(){
    cout<<"画了一个"<<m_name<<endl;
}

/*
 * 函数名：add_shape
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 输入参数：TwoDimensional *twoDimensional
 * 返回值：无
 * 功能描述：为二维图形添加一个子图形
 */
void TwoDimensional::add_shape(TwoDimensional *twoDimensional) {
    if(nullptr != twoDimensional){
        m_two_dimensional.push_back(twoDimensional);
    }
}

/*
 * 函数名：remove_shape
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 输入参数：TwoDimensional *twoDimensional
 * 返回值：无
 * 功能描述：为二维图形删除一个子图形
 */
void TwoDimensional::remove_shape(TwoDimensional *twoDimensional) {
    if(nullptr != twoDimensional){
        m_two_dimensional.remove(twoDimensional);
    }
}

/*
 * 函数名：draw
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 输入参数：无
 * 返回值：无
 * 功能描述：遍历观察者,每个观察者执行draw()函数。
 */
void ThreeDimensional::draw() {
    cout<<"画出"<<m_name<<":"<<endl;
    list<ThreeDimensional *>::iterator beg = m_three_dimensional.begin();
    for( ; beg != m_three_dimensional.end() ; beg++){
        (*beg)->draw();
    }
}

void Sphere::draw() {
    cout<<"画了一个"<<m_name<<endl;
}

void Pyramid::draw(){
    cout<<"画了一个"<<m_name<<endl;
}

void Cuboid::draw(){
    cout<<"画了一个"<<m_name<<endl;
}

/*
 * 函数名：add_shape
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 输入参数：TwoDimensional *twoDimensional
 * 返回值：无
 * 功能描述：为三维图形添加子图形
 */
void ThreeDimensional::add_shape(ThreeDimensional *threeDimensional) {
    if(nullptr != threeDimensional){
        m_three_dimensional.push_back(threeDimensional);
    }
}

/*
 * 函数名：remove_shape
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-14
 * 输入参数：TwoDimensional *twoDimensional
 * 返回值：无
 * 功能描述：为三维图形删除一个子图形
 */
void ThreeDimensional::remove_shape(ThreeDimensional *threeDimensional) {
    if(nullptr != threeDimensional){
        m_three_dimensional.remove(threeDimensional);
    }
}

int main(){
    subject *pencil = new Pencil();
    TwoDimensional *two = new TwoDimensional("二维图形",pencil);
    ThreeDimensional *three = new ThreeDimensional("三维图形",pencil);
    Circle *circle = new Circle("圆形",pencil);
    Rectangle *rectangle = new Rectangle("矩形",pencil);
    Triangle *triangle = new Triangle("三角形",pencil);
    Sphere *sphere = new Sphere("球体",pencil);
    Pyramid *pyramid = new Pyramid("锥体",pencil);

    pencil->operation();
    two->add_shape(circle);
    two->add_shape(rectangle);
    two->add_shape(triangle);
    pencil->attach(two);
    pencil->notify();
    cout<<endl;

    pencil->operation();
    two->remove_shape(circle);
    three->add_shape(sphere);
    three->add_shape(pyramid);
    pencil->attach(three);
    pencil->notify();
}
