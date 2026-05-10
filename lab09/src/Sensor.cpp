#include "Sensor.h"

Sensor::Sensor(string n, double x): Device(n), q(x) {}

void Sensor::accept(Visitor& v) {
    v.visit(*this);
}

double Sensor::getQ(){
    return q;
}