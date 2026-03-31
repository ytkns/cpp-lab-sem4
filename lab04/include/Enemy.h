#pragma once
#include"Entity.h"
using namespace std;

/**
 * @brief Klasa Enemy (Przeciwnik).
 * Dziedziczy po Entity.
 */
class Enemy: public Entity{
    public: 
        /**
         * @brief Konstruktor przeciwnika.
         * @param i Unikalne ID przeciwnika.
         * @param h Początkowe punkty życia.
         * @param b Referencja do eventbusa.
         */
        Enemy(int i, int h, EventBus& b);

        /**
         * @brief Metoda obsługująca damage event.
         * @param dmg Ilość punktów życia do odjęcia.
         */
        void takeDamage(int dmg);
};