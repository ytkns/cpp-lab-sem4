#pragma once
#include "IEvent.h"

/**
 * @brief Klasa reprezentująca event DAMAGE.
 * Dziedziczy po klasie IEvent.
 */
class DamageEvent : public IEvent {
    private:
        int damage; // ilosc damage'u

    public:

        /**
         * @brief Konstruktor damage eventu.
         * @param i ID celu.
         * @param dmg Ilość damage'u.
         */
        DamageEvent(int i, int dmg);

        /**
         * @brief Zwraca ilość aktualnego damage'u zdarzenia.
         */
        int getDmg() const;
};