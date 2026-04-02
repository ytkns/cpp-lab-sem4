#include "Test.h"

Test::Test(int i): id(i) {
    std::cout << "Test(" << id << ") created" << std::endl;
}

Test::~Test() {
    std::cout << "Test(" << id << ") destroyed" << std::endl;
}

void Test::hello() const{
    std::cout << "Hello from " << id << std::endl;
}