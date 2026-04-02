#include "Statistics.h"


void Statistics::operator()(int a){
    sum += a;
    count += 1;
    if (a < min_val) min_val = a;
    if(a > max_val) max_val = a;
}

void Statistics::Print() const{
    double mean = (double)sum/(double)count;
    std::cout << "Srednia z wyrazow ciagu:" << mean << std::endl;
    std::cout << "Najmniejszy wyraz ciagu: " << min_val << std::endl;
    std::cout << "Najwiekszy wyraz ciagu: " << max_val << std::endl;
}