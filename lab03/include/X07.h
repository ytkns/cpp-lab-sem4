#pragma once
#include "X06.h"

class X07: public X06{
    protected:
        const char* c = "@";
    public:
        X07();
        X07(int n);
        void Write();
        
};