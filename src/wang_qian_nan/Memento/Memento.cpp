#include<iostream>
#include<string>

using namespace std;


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
