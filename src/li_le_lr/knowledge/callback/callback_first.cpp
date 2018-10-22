//
// Created by lilelr on 10/22/18.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void printf_text(){
    printf("Hello World!\n");
}

void printf_text_with_parameter(char* s){
    printf(s);
}

void call_print_text(void (*callback1)()){
    callback1();
}

void call_print_text_with_parameter(void (*callback2)(char*), char* s){
    callback2(s);
}


int main(){
    call_print_text(printf_text);
    call_print_text_with_parameter(printf_text_with_parameter,"Hellow lele\n");
}
