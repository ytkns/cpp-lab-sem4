#pragma once

#include <iostream>
#include <string>
#include "Device.h"

using namespace std;

class Visitor;

/**
 * @brief Klasa reprezentująca sensor.
 *
 * Klasa Sensor dziedziczy po klasie Device,
 * przechowuje wartość jakości sensora.
 */
class Sensor : public Device {
    private:

        /**
         * @brief Wartość jakości sensora.
         */
        double q;

    public:

        /**
         * @brief Konstruktor dwuargumentowy klasy Sensor.
         *
         * Inicjalizuje identyfikator urządzenia i wartość jakości.
         *
         * @param n identyfikator urządzenia
         * @param x wartość jakości sensora
         */
        Sensor(string n, double x);

        /**
         * @brief Metoda akceptuje obiekt odwiedzający.
         *
         * Wykorzystywana we wzorcu projektowym Visitor.
         *
         * @param v referencja do odwiedzającego
         */
        void accept(Visitor& v) override;

        /**
         * @brief Metoda zwraca wartość jakości sensora.
         *
         * @return wartość jakości sensora
         */
        double getQ();
};