#pragma once
#include <iostream>

/** 
 * @brief Klasa testowa służąca do demonstracji działania inteligentnych wskaźników.
 * Klasa wypisuje komunikaty w momencie tworzenia i niszczenia obiektu,
 * co pozwala śledzić cykl życia zasobów zarzadzanych przez SPtr.
 */
class Test {
    public:
        /**
         * @brief Konstruktor inicjalizujący obiekt testowy.
         * Wypisuje komunikat o utworzeniu obiektu z konkretnym identyfikatorem.
         * @param[in] i Unikalny identyfikator obiektu.
         */
        Test(int i);

        /** 
         * @brief Destruktor klasy Test.
         * Wypisuje komunikat o zniszczeniu obiektu.
         */
        ~Test();

        /** 
         * @brief Metoda wypisująca powitanie wraz z identyfikatorem obiektu.
         */
        void hello() const;

    private:
        int id; // Identyfikator obiektu testowego
};