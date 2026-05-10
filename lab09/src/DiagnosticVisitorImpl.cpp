#include "DiagnosticVisitorImpl.h"
#include "Sensor.h"
#include "Router.h"
#include "Camera.h"
using namespace std;

void DiagnosticVisitorImpl::visit(Sensor& s) {
    cout << s.getId();
    if (s.getQ() < 0.95)
        cout << ": Sensor DEGRADED\n";
    else
        cout << ": Sensor OK\n";
}

void DiagnosticVisitorImpl::visit(Router& r) {
    cout << r.getId() << ": Router stable\n";
}

void DiagnosticVisitorImpl::visit(Camera& c) {
    cout << c.getId();
    if (c.getQ() < 1080)
        cout << ": Camera LOW RES\n";
    else
        cout << ": Camera HD\n";
}