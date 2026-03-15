#include "SamochodCiezarowy.h"

SamochodCiezarowy::SamochodCiezarowy(string m, string n, int r, double l): Samochod(m, n, r), ladownosc(l) {}

void SamochodCiezarowy::Prezentuj() const{
    cout << "Samochod ciezarowy: " << marka << " " << model << " (" << rok << "), ladownosc: " << ladownosc << endl;
}