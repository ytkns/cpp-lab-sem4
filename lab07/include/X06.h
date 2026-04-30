#pragma once
#include "X07.h"

/** 
 * @brief Klasa X06 dziedziczaca po X07.
 */
class X06: public X07{
    private:
        char c = '&'; /*znak przypisany do klasy X06*/

    public:
        /** 
        * @brief Konstruktor klasy X06.
        *
        * @param[in] v wartosc inicjalizujaca
        */
        X06(int n=1): X07(n) {};

        /** 
        * @brief Implementacja metody Write1.
        */
        void Write1() override;

        /** 
        * @brief Przysloniecie metody Write2 z klasy bazowej.
        */
        void Write2();

        /** 
        * @brief Przysloniecie metody Write3 z klasy bazowej.
        */
        void Write3();
};