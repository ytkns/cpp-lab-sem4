#pragma once
#include "X07.h"

/** 
 * @brief Klasa X05 dziedziczaca po X07.
 */
class X05: public X07{
    private:
        char c = '*'; /*znak przypisany do klasy X06*/

    public:
        /** 
         * @brief Konstruktor klasy X05.
         *
         * @param[in] v wartosc inicjalizujaca
         */
        X05(int n=1): X07(n) {};

        /** 
         * @brief Implementacja metody Write1.
         */
        void Write1() override;

        /** 
         * @brief Nowa wirtualna metoda Write3.
         *
         * Pozwala na polimorfizm wzoru 3 w ramach galezi X05.
         */
        virtual void Write3();
};