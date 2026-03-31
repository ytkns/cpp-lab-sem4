#pragma once
#include <iostream>
#include "IEvent.h"

/**
 * @brief System punktacji (ScoreSystem).
 * Klasa odpowiedzialna za śledzenie postępów gracza.
 */
class ScoreSystem{
    public:
        /**
         * @brief Statyczna metoda obsługująca Callbacki.
         * @param e Wskaźnik na event.
         */
        static void handleEvent(IEvent* e);
};