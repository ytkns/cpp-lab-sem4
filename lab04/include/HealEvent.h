#pragma once
#include "IEvent.h"

/**
 * @brief Klasa reprezentująca heal event.
 * Dziedziczy po klasie IEvent.
 */
class HealEvent : public IEvent {
    private:
        int hp;
    public:
        /**
        * @brief Konstruktor heal eventu.
        * @param i Id celu.
        */
        HealEvent(int i);

        HealEvent(int i, int n);
};