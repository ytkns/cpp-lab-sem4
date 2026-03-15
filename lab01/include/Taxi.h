#pragma once
#include <iostream>
#include <string>
#include "Samochod.h"
using namespace std;

class Taxi: public Samochod{
    private:
        double stawka;
    public:
        Taxi(string m, string n, int rok, double s);
        void Prezentuj() const;

};
