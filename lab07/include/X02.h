#pragma once
#include "X06.h"

/** 
 * @brief Klasa X02 dziedziczaca po X06.
 */
class X02: public X06{
    private:
        char c = '$'; /*znak przypisany do klasy X02*/

    public:
        /** 
         * @brief Konstruktor klasy X02.
         *
         * @param[in] v wartosc inicjalizujaca
         */
        X02(int n=1): X06(n) {};

        /** 
         * @brief Nadpisana metoda Write1.
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