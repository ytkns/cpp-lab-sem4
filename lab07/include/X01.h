#pragma once
#include "X05.h"

/** 
 * @brief Klasa X01 dziedziczaca po X05.
 */
class X01: public X05{
    private:
        char c = '!'; /*znak przypisany do klasy X01*/

    public:
        /** 
         * @brief Konstruktor klasy X01.
         *
         * @param[in] v wartosc inicjalizujaca
         */
        X01(int n=1): X05(n) {};

        /** 
         * @brief Nadpisana metoda Write1.
         */
        void Write1() override;

        /** 
         * @brief Przysloniecie metody Write2 z klasy bazowej.
         */
        void Write2();

        /** 
         * @brief Nadpisana metoda Write3.
         */
        void Write3() override;
};