#include "Taxi.h"

Taxi::Taxi(string m, string n, int r, double s): Samochod(m, n, r), stawka(s) {}

void Taxi::Prezentuj() const{
    cout << "Taxi: " << marka << " " << model << " (" << rok << "), stawka: " << stawka << endl;
}