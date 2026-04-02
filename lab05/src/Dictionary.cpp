#include "Dictionary.h"

int& Dictionary::operator[](const std::string& s){
    return dict[s];

}

void Dictionary::print() const{
    if( dict.empty() )
        std::cout << "Empty Dictionary" << std::endl;
    
    for( auto &i: dict)
        std::cout << "[" << i.first << ", " << i.second << "]";
    std::cout << std::endl;  
}

void Dictionary::clear(){
    dict.clear(); 
}