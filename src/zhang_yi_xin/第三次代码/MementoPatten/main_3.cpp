/*
 *在备忘录模式中，原发器（Originator）需要创建备忘录（Memento），并将备忘录交给负责人（Caretaker）
 * 来保存和管理。在创建备忘录时可以通过克隆原发器对象来实现，即使用原型模式，此时原发器需要支持自我复制。
 * 为简化系统设计，可以将原发器和备忘录合并，直接将克隆生成的原发器对象保存在负责人中。
 *///
#include<iostream>
#include<string>
using namespace std;

/*
 * 类名：Memento
 * 编写日期：18-9-18
 * 功能描述:备忘录，存储原发器的内部状态，根据原发器来决定保存哪些内部状态
 */
class Memento
{
public:
    Memento(string m_word) :m_word(m_word){}
private:
    friend class Originator;
    string m_word;
    string get_words()
    {
        return m_word;
    }
};

/*
 * 类名：Prototype
 * 编写日期：18-9-18
 * 功能描述： 抽象原型类 定义具有克隆自己的方法的接口
 */
class Prototype
{
public:
    virtual Prototype *clone() = 0;
    virtual void display() = 0;
    virtual Memento *save_words() = 0;
    virtual void recycle_words(Memento *pword)= 0;
};

/*
 * 类名：Originator
 * 编写日期：18-9-18
 * 功能描述： 原发器（Originator）需要创建备忘录（Memento），并将备忘录交给负责人（Caretaker）
 *           来保存和管理。在创建备忘录时可以通过克隆原发器对象来实现抽象
 */
class Originator
{
protected:
    string m_word;
    // int id;
public:
    Originator(string myword) :m_word(myword){}
    /*存档*/
    Memento *save_words()
    {
        return new Memento(m_word);
    }

    /*恢复/读取存档*/
    void recycle_words(Memento *pword)
    {
        m_word = pword->get_words();
        cout << "Good! 坚持最初的想法！你最初的想法是这样滴：" << endl;
    }

    void show_words()
    {
        cout << m_word << endl << endl;
    }

     void display()
    {
        cout<<"Good! 坚持最初的想法！你最初的想法是这样滴：" << " "<<this->m_word <<endl;
    }

    Originator *clone()         /*使用原型模式，此时原发器需要支持自我复制*/
    {
        return new Originator(*this);
    }
};

/*
 * 类名：Caretaker
 * 编写日期：18-9-18
 * 功能描述： Caretaker负责人,负责保存好备忘录，但不能对备忘录的内容进行操作或检查
 */
class Caretaker
{
private:
    Memento *m_memento;
public:
    void set_memento(Memento *memento)
    {
        m_memento = memento;
    }
    Memento* get_memento()
    {
        return m_memento;
    }
};

int main(void) {
    Originator *word_1 = new Originator("我对自己说我要努力学习设计模式！");
    word_1->show_words();//显示初始状态
    //存档
    Caretaker *caretaker = new Caretaker;
    caretaker->set_memento(word_1->save_words());
    //建立新的状态
    Originator *word_2 = new Originator("后来随着学习的深入，我的想法发生了改变，设计模式太抽象太难了！");
    word_2->show_words();//显示新的状态

    int choice;
    cout << "请输入你的选择：1.放弃      2.坚持最初的想法(1)      3.坚持最初的想法(2)"  << endl;
    cout << "你的选择是：";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "你就这点出息！" << endl;
            break;
        case 2:
            word_1->recycle_words(caretaker->get_memento());//读取存档，坚持最初的想法
            word_1->show_words();
            break;
        case 3:{
            Originator *obj2 = word_1->clone();/*利用克隆读取存档*/
            obj2->display();
            break;
        }
        default:
            cout << "你输入的选项有误！" << endl;
    }
    delete word_1;
    delete word_2;
    delete caretaker;

    return 0;
}

