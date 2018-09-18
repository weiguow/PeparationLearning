/*
 *在备忘录模式中，原发器（Originator）需要创建备忘录（Memento），并将备忘录交给负责人（Caretaker）
 * 来保存和管理。在创建备忘录时可以通过克隆原发器对象来实现，即使用原型模式，此时原发器需要支持自我复制。
 * 为简化系统设计，可以将原发器和备忘录合并，直接将克隆生成的原发器对象保存在负责人中。
 */

#include<iostream>
#include<string>
using namespace std;


class Memento
{
public:
    Memento(string m_word) :word(m_word){}
private:
    friend class Word_Input;
    string word;
    string GetWords()
    {
        return word;
    }
};

class Word_Input  //Originator 原发器，它创建备忘录并存储其当前内部状态，还可以使用备忘录来恢复内部状态；
{
private:
    string m_word;
public:
    Word_Input(string myword) :m_word(myword){}
    //存档
    Memento*SaveWords()
    {
        return new Memento(m_word);
    }
    //恢复存档
    void RecycleWords(Memento*pword)
    {
        m_word = pword->GetWords();
        cout << "Good! 坚持最初的想法！你最初的想法是这样滴：" << endl;
    }
    //输出文字
    void ShowWords()
    {
        cout << m_word << endl << endl;
    }

};

class Caretake
{
private:
    Memento* Pmemento;
public:
    void SetMemento(Memento*m_pmemento)
    {
        Pmemento = m_pmemento;
    }
    Memento* GetMemento()
    {
        return Pmemento;
    }
};

int main(void) {
    Word_Input *wi_1 = new Word_Input("我对自己说我要努力学习设计模式！");
    wi_1->ShowWords();//显示初始状态
    //存档
    Caretake *ct = new Caretake;
    ct->SetMemento(wi_1->SaveWords());
    //建立新的状态
    Word_Input *wi_2 = new Word_Input("后来随着学习的深入，我的想法发生了改变，设计模式太抽象太难了！");
    wi_2->ShowWords();//显示新的状态

    int choise;
    cout << "请输入你的选择：1.放弃      2.坚持最初的想法" << endl;
    cout << "你的选择是：";
    cin >> choise;
    switch (choise) {
        case 1:
            cout << "你就这点出息！" << endl;
            break;
        case 2:
            wi_1->RecycleWords(ct->GetMemento());//读取存档，坚持最初的想法
            wi_1->ShowWords();
            break;
        default:
            cout << "你输入的选项有误！" << endl;
    }
    delete wi_1;
    delete wi_2;
    delete ct;

    return 0;
}



