#include "X07.h"

X07::X07(): X06(1) {}

X07::X07(int n): X06::X06(n) {};

void X07::Write(){
    int n = 0;
    while(n < nr){
        cout << c;
        n++;
    }

    X06::Write();

    n = 0;
    while(n < nr){
        cout << c;
        n++;
    }
}