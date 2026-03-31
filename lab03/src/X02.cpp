#include "X02.h"

X02::X02(int n): X01::X01(n) {};

void X02::Write() {
    int n = 0;

    while(n < nr){
        cout << c;
        n++;
    }

    X01::Write();

    n = 0;

    while(n < nr){
        cout << c;
        n++;
    }
}

