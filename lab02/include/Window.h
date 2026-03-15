#pragma once

#include <iostream>
using namespace std;

/**
 * @class Window
 * @brief Klasa reprezentująca okno aplikacji.
 *
 * Klasa pozwala na tworzenie okna, jego uruchamianie oraz maksymalizację.
 */
class Window {

    private:

        /// Rozmiar okna
        int size;
    public:

        /**
        * @brief Konstruktor klasy Window.
        *
        * Tworzy okno o podanym rozmiarze.
        *
        * @param windowSize Rozmiar okna.
        */
        Window(int windowSize);

        /**
        * @brief Uruchamia okno.
        *
        * Funkcja wypisuje komunikat informujący o wyświetleniu okna.
        */
        void Run();

        /**
        * @brief Maksymalizuje okno.
        *
        * Funkcja wypisuje komunikat informujący o maksymalizacji okna.
        */
        void Maximize();
};