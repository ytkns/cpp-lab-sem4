#pragma once
#include "X03.h"

/** 
 * @brief Klasa X04 dziedziczaca po X05.
 */
class X04: public X03{
    private:
        char c= '%'; /*znak przypisany do klasy X04*/

    public:
        /** 
         * @brief Konstruktor klasy X04.
         *
         * @param[in] v wartosc inicjalizujaca
         */
        X04(int n=1): X03(n) {};

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