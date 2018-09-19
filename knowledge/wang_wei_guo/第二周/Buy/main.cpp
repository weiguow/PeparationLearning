#include "Facade.h"

int main() {
    Facade *facade=new Facade;
    facade->Buy();
    facade->Sell();
    getchar();
    return 0;
}