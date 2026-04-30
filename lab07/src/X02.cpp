#include "X02.h"
        
void X02::Write1(){
    for(int i=0; i<2*number; i++)
        cout << c;

    X06::Write1();

    for(int i=0; i<number; i++)
        cout << c;

}
        
void X02::Write2(){
    for(int i=0; i<number; i++)
        cout << c;

    X06::Write2();

    for(int i=0; i<2*number; i++)
        cout << c;
}
        
void X02::Write3(){
    for(int i=0; i<2*number; i++)
        cout << c;

    X06::Write3();

    for(int i=0; i<2*number; i++)
        cout << c;
}