#include "Samochod.h"

Samochod::Samochod(string m, string n, int r): model(m), marka(n), rok(r) {}

void Samochod::Prezentuj() const{
    cout << marka << " " << model << " (" << rok << ")\n";
}