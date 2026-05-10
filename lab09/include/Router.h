#pragma once
#include<iostream>
#include<string>
#include "Device.h"
using namespace std;

/**
 * @brief Klasa reprezentująca router.
 *
 * Klasa Router dziedziczy po klasie Device,
 * przechowuje wartość jakości routera.
 */
class Router: public Device{
    private:
        /**
         * @brief Wartość jakości routera.
         */
        int q;

    public:
        /**
         * @brief Konstruktor dwuargumentowy klasy Router.
         *
         * Inicjalizuje identyfikator urządzenia i wartość jakości.
         *
         * @param n identyfikator urządzenia
         * @param x wartość jakości routera
         */
        Router(string n, int x);

        /**
         * @brief Metoda akceptuje obiekt odwiedzający.
         *
         * Wykorzystywana we wzorcu projektowym Visitor.
         *
         * @param v referencja do odwiedzającego
         */
        void accept(Visitor& v) override;

        /**
         * @brief Metoda zwraca wartość jakości routera.
         *
         * @return wartość jakości routera
         */
        int getQ();
};