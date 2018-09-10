#include <iostream>
using namespace std;

 // "ITarget"抽象目标类
 class Target
 {
 public:

     //Methods
     virtual void Request(){};
 };

 //"Adaptee"适配者类
 class Adaptee
 {
 public:

     //Methods
     void SpecificRequest()
     {
         cout<<"ClassAdapter SpecificRequest()"<<endl;

     }
 };

 //"Adapter"适配器类
 class Adapter : public Adaptee,public Target
 {
 public:

     //Implements ITarget interface
     void Request()
     {
         // Possibly do some data manipulation
         // and then call specificRequest
         this->SpecificRequest();
     }

 };

//int main()
// {
//     //create adapter and place a request
//     Target *t = new Adapter();
//     t->Request();
//
//     return 0;
//
// }