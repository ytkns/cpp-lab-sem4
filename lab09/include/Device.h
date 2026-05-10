#pragma once

#include <string>
#include "DiagnosticVisitorImpl.h"
#include "ActionVisitorImpl.h"

using namespace std;

/**
 * @brief Klasa bazowa reprezentująca urządzenie.
 *
 * Klasa Device jest klasą abstrakcyjną, po której dziedziczą wszystkie typy urządzeń w systemie.
 * Przechowuje identyfikator urządzenia oraz deklaruje metodę accept() wykorzystywaną we wzorcu Visitor.
 */
class Device {
    protected:

        /**
        * @brief Identyfikator urządzenia.
        */
        string id;

    public:

        /**
         * @brief Konstruktor klasy Device.
         *
         * Inicjalizuje identyfikator urządzenia.
         * @param i identyfikator urządzenia
         */
        Device(string i);

        /**
         * @brief Zwraca identyfikator urządzenia.
         *
         * @return identyfikator urządzenia
         */
        string getId();

        /**
         * @brief Wirtualny destruktor klasy Device.
         */
        virtual ~Device() = default;

        /**
         * @brief Akceptuje obiekt odwiedzający.
         *
         * Metoda wykorzystywana we wzorcu projektowym Visitor.
         * @param v referencja do odwiedzającego
         */
        virtual void accept(Visitor& v) = 0;
};