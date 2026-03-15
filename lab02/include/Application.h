#pragma once

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Application
 * @brief Klasa reprezentująca prostą aplikację.
 *
 * Klasa umożliwia uruchamianie aplikacji oraz aktywowanie
 * dziennika (logu). Przechowuje nazwę aplikacji.
 */
class Application {

    private:

        /// Nazwa aplikacji
        string name;

    public:

        /**
        * @brief Uruchamia aplikację.
        *
        * Funkcja wypisuje komunikat informujący o uruchomieniu aplikacji.
        */
        void Run();

        /**
        * @brief Aktywuje dziennik aplikacji.
        *
        * Funkcja wypisuje komunikat informujący o aktywowaniu logów.
        */
        void ActivateLog();

        /**
        * @brief Konstruktor klasy Application.
        *
        * Tworzy obiekt aplikacji i ustawia jego nazwę.
        *
        * @param appName Nazwa aplikacji.
        */
        Application(string appName);

    
};