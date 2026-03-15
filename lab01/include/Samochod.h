#pragma once
#include<iostream>
#include <string>
using namespace std;

class Samochod{
    protected:
        string marka;
        string model;
        int rok;
        
    public:
        Samochod(string m, string n, int r);
        void Prezentuj() const;

};