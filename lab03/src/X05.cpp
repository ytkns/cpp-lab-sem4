#include "X05.h"

X05::X05(int n): X07::X07(n) {};

void X05::Write(){
    int n = 0;
    while(n < nr){
        cout << c;
        n++;
    }

    X07::Write();

    n = 0;
    while(n < nr){
        cout << c;
        n++;
    }
    
}