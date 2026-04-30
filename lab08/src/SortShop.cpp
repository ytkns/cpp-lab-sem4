#include "SortShop.h"

SortShop::SortShop(const Shop& s): Shop(s) { mySort(); }

void SortShop::Add(const Product& p){
    s.push_back(p);
    this->mySort();
}

Product& SortShop::operator[](int i){
    if(i==3){
        Product e(0,0);
        s[3] = e;
        mySort();
        return s[0];
    }
    return s[i];
}

SortShop SortShop::operator()(int i, int j){
    mySort();
    SortShop nowy;
    for(int k = i; k <= j && k < s.size(); k++)
        nowy.Add(s[k]);
    return nowy;
}

ostream& operator<<(ostream& out, SortShop& s){
    out << (Shop&)s;
    return out;
}

void SortShop::mySort(){
    sort(s.begin(), s.end(), []( Product a,  Product b){return a.get_ilosc() < b.get_ilosc();});
}

