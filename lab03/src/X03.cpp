#include "X03.h"

X03::X03(int n): X06::X06(n) {};

void X03::Write(){
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