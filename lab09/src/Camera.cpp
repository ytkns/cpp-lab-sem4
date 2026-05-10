#include "Camera.h"

Camera::Camera(string n, int x): Device(n), q(x) {}

void Camera::accept(Visitor& v) {
    v.visit(*this);
}

int Camera::getQ(){
    return q;
}