#pragma once
#include <iostream>
#include "IEvent.h"

/**
 * @brief System łupów (LootSystem).
 * Klasa odpowiedzialna za logikę wypadania przedmiotów (lootu).
 */
class LootSystem {
    public:
        /**
         * @brief Statyczna metoda obsługująca Callbacki.
         * @param e Wskaźnik na event.
         */
        static void handleEvent(IEvent* e);
        
};