#include <iostream>
#include "composite.h"

using namespace std;

int main() {
    string str("��");

    ConcreteCommandA com1("�й���ѧԺ");
    ConcreteCommandB com2("�й���ѧԺ�����㼼���о���");
    ConcreteCommandC com3("�й���ѧԺ����������");

    cout << "һ��Ŀ¼" << endl;
    com1.display(str);
    cout << endl;

    cout << "��Ӷ���Ŀ¼" << endl;
    com1.attach(&com2);
    com1.attach(&com3);
    com1.display(str);
    cout << endl;

    ConcreteCommandA com11("�й���ѧԺ�����Ƚ��о�Ժ");
    ConcreteCommandB com22("�������칹��������");
    ConcreteCommandC com33("�������Ƽ�������");

    cout << "�������Ŀ¼" << endl;
    com11.attach(&com22);
    com11.attach(&com33);
    com1.attach(&com11);
    com1.display(str);
    cout<<endl;

    cout<<"ɾ��Ŀ¼"<<endl;
    com11.detach(&com22);
    com1.display(str);
}