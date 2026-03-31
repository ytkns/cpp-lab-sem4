#include "X06.h"

X06::X06(int n): X04::X04(n) {};

void X06::Write(){
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

