#pragma once
#include <iostream>
using namespace std;

/** 
 * @brief Klasa bazowa dla calej hierarchii dziedziczenia.
 *
 * Reprezentuje szczyt drzewa, jest klasa abstrakcyjna.
 */
class X07{
    protected:
        int number; /*< Przechowywana wartosc liczbowa do okreslania ilosci znakow */

    public:

        /** 
        * @brief Konstruktor klasy bazowej.
        *
        * @param[in] v wartosc inicjalizujaca (domyslnie 1)
        */
        X07(int n=1);

        /** 
        * @brief Wirtualny destruktor.
        */
        virtual ~X07() {}

        /** 
        * @brief Czysto wirtualna metoda do wypisywania wzoru 1.
        *
        * Czyni klase X07 abstrakcyjna.
        */
        virtual void Write1() = 0;

        /** 
        * @brief Metoda do wypisywania wzoru 2.
        *
        * Domyslnie wypisuje wartosc zmiennej.
        */
        void Write2();

        /** 
        * @brief Metoda do wypisywania wzoru 3.
        *
        * Domyslnie wypisuje wartosc zmiennej.
        */
        void Write3();
};