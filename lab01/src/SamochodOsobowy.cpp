#include "SamochodOsobowy.h"

SamochodOsobowy::SamochodOsobowy(string m, string n, int r, int pas): Samochod(m, n, r), pasazerowie(pas) {}

void SamochodOsobowy::Prezentuj() const{
    cout << "Samochod osobowy: " << marka << " " << model << " (" << rok << "), pasazerowie: " << pasazerowie << endl;
}