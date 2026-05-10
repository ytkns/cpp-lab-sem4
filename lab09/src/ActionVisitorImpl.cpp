#include <iostream>
#include "ActionVisitorImpl.h"
using namespace std;

void ActionVisitorImpl::visit(Sensor& s) {
    cout << "Measuring environment...\n";
}
        
void ActionVisitorImpl::visit(Router& r) {
    cout << "Routing packets...\n";
}
        
void ActionVisitorImpl::visit(Camera& c) {
    cout << "Recording video...\n";
}