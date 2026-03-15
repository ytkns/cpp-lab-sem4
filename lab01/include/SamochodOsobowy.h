#pragma once
#include <iostream>
#include <string>
#include "Samochod.h"
using namespace std;

class SamochodOsobowy: public Samochod{
    private:
        int pasazerowie;
    public:
        SamochodOsobowy(string m, string n, int rok, int pas);
        void Prezentuj() const;

};
