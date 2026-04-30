#include "Pipeline.h"

double& Pipeline::operator[](int i) {
    return data[i];
}

double Pipeline::operator[](int i) const {
    if (data.find(i) != data.end())
        return data.at(i);
    return 0.0;
}

double Pipeline::operator()(double x) const {
    double p0 = (*this)[0];
    double p1 = (*this)[1];
    double p2 = (*this)[2];
    return p1 * x - p0 * p2 + val;
}

Pipeline Pipeline::add(double v) const {
    Pipeline p = *this;
    p.val += v;
    return p;
}


