/*
 * 作者:王倩楠
 * 编写日期:2018/9/11
 * 联系方式：sherlock_vip@163.com
 * 功能描述:在不破坏封装的前提下，捕获一个对象的内部状态，
 *         并在该对象之外保存这个状态，这样可以在以后将对象恢复到原先保存的状态。
 */
#include<iostream>
#include<string>

using namespace std;


/*
 * 类名:Memento
 * 编写日期:18-9-11
 * 功能描述:备忘录角色，用于存储 Originator 的内部状态，并且可以防止 Originator 以外的对象访问 Memento。?
 */
class Originator;

class Memento {
public:
    Memento(string m_word) : word(m_word) {}

private:
    friend class Originator;

    //Originator声明为memento的友元类
    //防止Originator以外的其他对象访问memento,封密的效果,即定义中所说的不破坏封闭.
    string GetWords() {
        return word;
    }

    string word;
};

/*
 * 类名:Originator
 * 编写日期:18-9-11
 * 功能描述:原发器，负责创建一个备忘录，可以记录、恢复自身的内部状态
 */

class Originator {
public:
    Originator(string myword) : word(myword) {}

    //存档

    Memento *CreateMemento() {
        return new Memento(word);
    }

    //恢复存档

    void RestoreMemento(Memento *pword) {
        word = pword->GetWords();
        cout << "状态恢复" << endl;
    }

    //输出文字

    void ShowWords() {
        cout << word << endl << endl;
    }

private:
    string word;
};


/*
 * 类名:Caretake
 * 编写日期:18-9-11
 * 功能描述:负责存储备忘录，不能对备忘录的内容进行操作和访问，只能够将备忘录传递给其他对象
 */
class Caretake {
public:
    void SetMemento(Memento *m_pmemento) {
        Pmemento = m_pmemento;
    }

    Memento *GetMemento() {
        return Pmemento;
    }

private:
    Memento *Pmemento;
};



int main(void) {
    Originator *wi_1 = new Originator("显示初始状态");
    wi_1->ShowWords();  //显示初始状态

    //存档

    Caretake *ct = new Caretake;
    ct->SetMemento(wi_1->CreateMemento());

    //建立新的状态

    Originator *wi_2 = new Originator("显示新的状态");
    wi_2->ShowWords();//显示新的状态


    int choise;
    cout << "请输入你的选择：1.不更新状态      2.更新状态" << endl;
    cout << "你的选择是：";
    cin >> choise;
    switch (choise) {
        case 1:
            cout << "已放弃更新" << endl;
            break;
        case 2:
            wi_1->RestoreMemento(ct->GetMemento());//读取存档，坚持最初的想法
            wi_1->ShowWords();
            break;
        default:
            cout << "你输入的选项有误！" << endl;
    }

    system("pause");
    return 0;
}
