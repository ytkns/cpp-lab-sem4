#include "Router.h"

Router::Router(string n, int x): Device(n), q(x) {}

void Router::accept(Visitor& v) {
    v.visit(*this);
}

int Router::getQ(){
    return q;
}