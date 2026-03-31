#pragma once
#include "IEvent.h"

/**
 * @brief Klasa reprezentująca Item event(odpowiada za podniesienie/ użycie przedmiotu).
 * Dziedziczy po klasie IEvent.
 */
class ItemEvent : public IEvent {
    private:
        string name; // Nazwa przedmiotu

    public:
        /**
         * @brief Konstruktor Item event.
         * @param i Id playera.
         * @param n Nazwa przedmiotu.
         */
        ItemEvent(int i, string n);

        /**
         * @brief Zwraca nazwę przedmiotu związanego z eventem.
         */
        string getName() const;
};