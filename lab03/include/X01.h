#pragma once
#include "X04.h"

class X01: public X04{
    protected:
        const char* c = "&";
    public:
        X01(int n);
        void Write();

};