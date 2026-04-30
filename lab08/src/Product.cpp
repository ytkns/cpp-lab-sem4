#include "Product.h"

int Product::get_ilosc(){
    return ilosc;
}

Product::Product(int t, int n): typ(t), ilosc(n) {}

int Product::operator[](int n){
    return (n==0) ? typ : ilosc;

}
    
Product& Product::operator++(){
    ilosc++; 
    return *this;
}
        
Product Product::operator++(int){
    Product temp = *this;
    ilosc++;
    return temp;
}
        
Product& Product::operator--(){
    if(ilosc>=1)
        ilosc--; 
    return *this;
}
        
Product Product::operator--(int){
    Product temp = *this;
    if(ilosc>=1)
        ilosc--;
    return temp;
}

Product Product::operator+(int n){
    Product nowy = *this;
    nowy.ilosc += n;
    return nowy;
}
        
Product Product::operator-(int n){
    Product nowy = *this;
    if(nowy.ilosc >= n)
        nowy.ilosc -= n;
    else
        nowy.ilosc = 0;
    return nowy;
}
        
Product Product::operator*(int n){
    Product nowy = *this;
    nowy.ilosc *= n;
    return nowy;
}
        
bool Product::operator<(const Product& other){
    return this->ilosc < other.ilosc;
}
        
bool Product::operator>(const Product& other){
    return this->ilosc > other.ilosc;
}
        
bool Product::operator<=(const Product& other){
    return this->ilosc <= other.ilosc;
}
        
bool Product::operator>=(const Product& other){
    return this->ilosc >= other.ilosc;
}
        
bool Product::operator==(const Product& other){
    return this->ilosc == other.ilosc;
}
        
bool Product::operator!=(const Product& other){
    return this->ilosc != other.ilosc;
}

ostream& operator<<(ostream& os, const Product& p){
    os << "typ: " << p.typ << ", ilosc sztuk: " << p.ilosc << endl;
    return os;
}
        