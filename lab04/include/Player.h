#pragma once
#include"Entity.h"
using namespace std;

/**
 * @brief Klasa Player (Gracz).
 * Dziedziczy po Entity.
 */
class Player: public Entity{
    public:
        /**
         * @brief Konstruktor gracza.
         * @param i ID gracza.
         * @param h Punkty życia.
         * @param b Referencja do eventbusa.
         */
        Player(int i, int h, EventBus& b);

        /**
         * @brief Metoda odpowiadająca za heal event.
         * @param i Ilość punktów życia do przywrócenia.
         */
        void heal(int i);

        /**
         * @brief Metoda odpowiadająca za podniesienie przedmiotu.
         * @param item Nazwa podniesionego przedmiotu.
         */
        void pickItem(const string& item);
};