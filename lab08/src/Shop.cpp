#include "Shop.h"
     
Shop::Shop() {}

Shop::Shop(const Shop& other): s(other.s) {}

void Shop::Add(const Product& p){
    s.push_back(p);
}
        
void Shop::Remove(){
    if (s.empty()) 
        cout << "BLAD: Pusto !" << endl;
    else
        s.pop_back();
}
        
void Shop::Clear(){
    s.clear();
}

Shop& Shop::operator=(const Shop& other){
    if(this != &other)
        s = other.s;
    return *this;
}
        
Shop Shop::operator+(int n){
    Shop nowy(*this);
    for (auto& p: nowy.s){
        p = p + n;
    }
    return nowy;
}
        
Shop Shop::operator-(int n){
    Shop nowy(*this);
    for (auto& p: nowy.s){
        p = p - n;
    }
    return nowy;
}
        
Shop Shop::operator*(int n){
    Shop nowy(*this);
    for (auto& p: nowy.s){
        p = p * n;
    }
    return nowy;
}
        
Product& Shop::operator[](int i){
    return s[i];
}

Shop Shop::operator()(int i, int j){
    Shop nowy;
    for(int k = i; k <= j && k < s.size(); k++)
        nowy.Add(s[k]);
    
    return nowy;
}

bool Shop::operator<(const Shop& other){
    int a = 0;
    for(auto p : s)
        a += p.get_ilosc();

    int b = 0;
    for(auto p: other.s)
        b += p.get_ilosc();

    return a < b;
}
        
bool Shop::operator>(const Shop& other){
    int a = 0;
    for(auto p : s)
        a += p.get_ilosc();

    int b = 0;
    for(auto p: other.s)
        b += p.get_ilosc();

    return a > b;
}
        
bool Shop::operator<=(const Shop& other){
    int a = 0;
    for(auto p : s)
        a += p.get_ilosc();

    int b = 0;
    for(auto p: other.s)
        b += p.get_ilosc();
    return a <= b;
}
        
bool Shop::operator>=(const Shop& other){
    int a = 0;
    for(auto p : s)
        a += p.get_ilosc();

    int b = 0;
    for(auto p: other.s)
        b += p.get_ilosc();

    return a >= b;
}
        
bool Shop::operator==(const Shop& other){
    int a = 0;
    for(auto p : s)
        a += p.get_ilosc();

    int b = 0;
    for(auto p: other.s)
        b += p.get_ilosc();

    return a == b;
}
        
bool Shop::operator!=(const Shop& other){
    int a = 0;
    for(auto p : s)
        a += p.get_ilosc();

    int b = 0;
    for(auto p: other.s)
        b += p.get_ilosc();

    return a != b;
}

ostream& operator<<(ostream& os, Shop& sh){
    os << "---\n# Zawartosc/sklad:\n";
    for ( const auto& p : sh.s){
        os << p;
    }
    os << "---\n"; 
    return os;
}
