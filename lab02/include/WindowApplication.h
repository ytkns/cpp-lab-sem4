#pragma once
#include "Window.h"
#include "Application.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @class WindowApplication
 * @brief Klasa reprezentująca aplikację zintegrowaną z oknem.
 *
 * Klasa dziedziczy po klasach Window i Application, umożliwiając
 * uruchamianie aplikacji oraz wyświetlanie i maksymalizację okna.
 */
class WindowApplication : public Window, public Application {

    private:

        /// Identyfikator aplikacji
        int id;
    public:

        /**
        * @brief Uruchamia aplikację w oknie.
        *
        * Funkcja wypisuje komunikat informujący o wyświetleniu okna
        * aplikacji.
        */
        void Run();

        /**
        * @brief Konstruktor klasy WindowApplication.
        *
        * Tworzy obiekt aplikacji z przypisanym identyfikatorem, rozmiarem okna
        * oraz nazwą aplikacji.
        *
        * @param i Identyfikator aplikacji.
        * @param k Rozmiar okna.
        * @param n Nazwa aplikacji.
        */
        WindowApplication(int i, int k, string n);
};