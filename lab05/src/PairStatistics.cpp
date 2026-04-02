#include "PairStatistics.h"

PairStatistics::PairStatistics(): equal(0), increasing(0), decreasing(0) {}

void PairStatistics::operator()(int a, int b) {
    if (a == b)
        equal++;
    else if (a < b)
        increasing++;
    else
        decreasing++;
}

void PairStatistics::Print() const{
    std::cout << "Liczba par rownych: " << equal << std::endl;
    std::cout << "Liczba par rosnacych: " << increasing << std::endl;
    std::cout << "Liczba par malejacych: " << decreasing << std::endl;
}

