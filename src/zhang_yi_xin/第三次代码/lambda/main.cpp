#include <iostream>
using namespace std;
int main(){
    int boys = 4;
    int girls = 3;
    auto totalChild = [girls, &boys]( )->int{ return girls * boys;};
    cout<<totalChild()<<endl;
    return totalChild ();
}
