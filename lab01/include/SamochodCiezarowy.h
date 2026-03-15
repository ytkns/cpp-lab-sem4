#pragma once
#include <iostream>
#include <string>
#include "Samochod.h"
using namespace std;

class SamochodCiezarowy: public Samochod{
    private:
        double ladownosc;
    public:
        SamochodCiezarowy(string m, string n, int rok, double l);
        void Prezentuj() const;

};
