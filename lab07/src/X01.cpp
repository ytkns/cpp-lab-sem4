#include "X01.h"
        
void X01::Write1(){
    for(int i=0; i<2*number; i++)
        cout << c;

    X05::Write1();

    for(int i=0; i<number; i++)
        cout << c;
}
        
void X01::Write2(){
    for(int i=0; i<number; i++)
        cout << c;

    X05::Write2();

    for(int i=0; i<2*number; i++)
        cout << c;
}
        
void X01::Write3(){
    for(int i=0; i<2*number; i++)
        cout << c;

    X05::Write3();

    for(int i=0; i<2*number; i++)
        cout << c;
}