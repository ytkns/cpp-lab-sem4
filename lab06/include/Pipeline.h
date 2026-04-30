#pragma once
#include <map>
using namespace std;

class Pipeline {
    private:
        map<int, double> data; // slownik z danymi
        double val = 0.0; //wartosc wlasna obiektu

    public:
        /*
        *@brief operator [] przyjmujacy indeks 
        *zwracający wartosc slownika o tym kluczu
        *param i klucz slownika
        *return data[i] wartosc o tym kluczu
        */
        double& operator[](int i);

        /*
        *@brief operator [] przyjmujacy indeks 
        *zwracający wartosc slownika o tym kluczu
        *param i klucz slownika
        *return data[i] wartosc o tym kluczu
        */
        double operator[](int i) const;

        /*
        *@brief operator () przyjmujacy wartość dla jakiej obliczany jest offset
        *param x wartosc dla jkaiej obliczamy wartosc 
        *return obliczona wartosc dla danego x
        */
        double operator()(double x) const;

        /*
        *@brief Funkcja dodaje wartosc v do wartosci calkowitej val
        *param v - wartosc dodawana
        *return p - obiekt z oliczona ponownie wartością val
        */
        Pipeline add(double v) const;
        
};

