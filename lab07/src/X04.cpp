#include "X04.h"

void X04::Write1(){
    for(int i=0; i<2*number; i++)
        cout << c;

    X03::Write1();

    for(int i=0; i<number; i++)
        cout << c;    
}
        
void X04::Write2(){
    for(int i=0; i<number; i++)
        cout << c;

    X03::Write2();

    for(int i=0; i<2*number; i++)
        cout << c;   
}
        
void X04::Write3(){
    for(int i=0; i<2*number; i++)
        cout << c;

    X03::Write3();

    for(int i=0; i<2*number; i++)
        cout << c;   
}