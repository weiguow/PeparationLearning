/*
 * ����:��ٻ�
 * ��д����:2018/9/11
 * ��ϵ��ʽ��sherlock_vip@163.com
 * ��������:�ڲ��ƻ���װ��ǰ���£�����һ��������ڲ�״̬��
 *         ���ڸö���֮�Ᵽ�����״̬�������������Ժ󽫶���ָ���ԭ�ȱ����״̬��
 */
#include<iostream>
#include<string>

using namespace std;


/*
 * ����:Memento
 * ��д����:18-9-11
 * ��������:����¼��ɫ�����ڴ洢 Originator ���ڲ�״̬�����ҿ��Է�ֹ Originator ����Ķ������ Memento��?
 */
class Originator;

class Memento {
public:
    Memento(string m_word) : word(m_word) {}

private:
    friend class Originator;

    //Originator����Ϊmemento����Ԫ��
    //��ֹOriginator����������������memento,���ܵ�Ч��,����������˵�Ĳ��ƻ����.
    string GetWords() {
        return word;
    }

    string word;
};

/*
 * ����:Originator
 * ��д����:18-9-11
 * ��������:ԭ���������𴴽�һ������¼�����Լ�¼���ָ�������ڲ�״̬
 */

class Originator {
public:
    Originator(string myword) : word(myword) {}

    //�浵

    Memento *CreateMemento() {
        return new Memento(word);
    }

    //�ָ��浵

    void RestoreMemento(Memento *pword) {
        word = pword->GetWords();
        cout << "״̬�ָ�" << endl;
    }

    //�������

    void ShowWords() {
        cout << word << endl << endl;
    }

private:
    string word;
};


/*
 * ����:Caretake
 * ��д����:18-9-11
 * ��������:����洢����¼�����ܶԱ���¼�����ݽ��в����ͷ��ʣ�ֻ�ܹ�������¼���ݸ���������
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
    Originator *wi_1 = new Originator("��ʾ��ʼ״̬");
    wi_1->ShowWords();  //��ʾ��ʼ״̬

    //�浵

    Caretake *ct = new Caretake;
    ct->SetMemento(wi_1->CreateMemento());

    //�����µ�״̬

    Originator *wi_2 = new Originator("��ʾ�µ�״̬");
    wi_2->ShowWords();//��ʾ�µ�״̬


    int choise;
    cout << "���������ѡ��1.������״̬      2.����״̬" << endl;
    cout << "���ѡ���ǣ�";
    cin >> choise;
    switch (choise) {
        case 1:
            cout << "�ѷ�������" << endl;
            break;
        case 2:
            wi_1->RestoreMemento(ct->GetMemento());//��ȡ�浵�����������뷨
            wi_1->ShowWords();
            break;
        default:
            cout << "�������ѡ������" << endl;
    }

    system("pause");
    return 0;
}
