#include "X01.h"

X01::X01(int n): X04::X04(n) {};

void X01::Write(){
    int n = 0;
    while(n < nr){
        cout << c;
        n++;
    }

    X04::Write();

    n = 0;
    while(n < nr){
        cout << c;
        n++;
    }
    
}

