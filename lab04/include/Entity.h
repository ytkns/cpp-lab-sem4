#pragma once
#include "EventBus.h"
#include<iostream>

/**
 * @brief Klasa bazowa Entity.
 * Reprezentuje dowolny obiekt, posiadający statystyki (ID, HP)
 */
class Entity {
    protected:
        int id; //unikalny identyfikator
        int hp; //health points
        /**
         * @brief Referencja do eventbusa.
         * Dzięki niej każda pochodna klasa (np. Player, Enemy) może wysyłać eventy do systemu.
         */
        EventBus& bus;

    public:
        /**
         * @brief Konstruktor inicjalizujący.
         * @param i ID bytu.
         * @param h Punkty życia.
         * @param b Referencja do istniejącego eventbusa.
         */
        Entity(int i, int h, EventBus& b);

        /**
         * @brief Destruktor klasy Entity.
         */
        virtual ~Entity() = default; 

};