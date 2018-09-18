#include <iostream>
#include <string>
using namespace std;

class Memento
{
public:
    Memento(string m_word) :m_word(m_word){}
private:
    friend class Word_Input;
    string m_word;
    string GetWords()
    {
        return m_word;
    }
};
class Prototype
{
public:
    virtual Prototype *Clone() = 0;
    virtual void display() = 0;
    virtual Memento *SaveWords() = 0;
    virtual void RecycleWords(Memento *pword)= 0;
   // virtual Memento *SaveWords() = 0;
    //virtual void display() = 0;
};

class Word_Input:public Prototype
{
protected:
    string m_word;
   // int id;
public:
    Word_Input(string myword) :m_word(myword){}
    //存档
    Memento *SaveWords()
    {
        return new Memento(m_word);
    }

    //恢复存档
    void RecycleWords(Memento *pword)
    {
        m_word = pword->GetWords();
        cout << "word：" << endl;
    }

    virtual void display()
    {
        cout<< "word :" << " "<<this->m_word <<endl;
    }

    Word_Input *Clone()
    {
        return new Word_Input(*this);
    }

};

class Caretaker
{
private:
    Memento* Pmemento;
   // Word_Input *m_word_input;
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

int main()
{
    Prototype *obj1 = new Word_Input("patten");
    obj1->display();

    //存档
    Caretaker *ct = new Caretaker;
    ct->SetMemento(obj1->SaveWords());
    obj1->display();

    Prototype *obj2 = obj1->Clone();/*利用克隆读取存档*/
    obj2->display();
//    Prototype *obj3;

    //恢复
  //  obj1->RecycleWords(ct->GetMemento());
 //   obj1->display();

  //  getchar();
    return 0;
}
