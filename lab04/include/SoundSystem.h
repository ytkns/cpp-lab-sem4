#pragma once
#include <iostream>
#include "IEvent.h"

/**
 * @brief System dźwięku (SoundSystem).
 * Odpowiada za dźwięki.
 */
class SoundSystem{
    public:
        /**
         * @brief Statyczna metoda obsługująca Callbacki.
         * @param e Wskaźnik na event.
         */
        static void handleEvent(IEvent* e);
        
};