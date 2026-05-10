#pragma once

#include "Visitor.h"

/**
 * @brief Klasa realizująca akcje urządzeń.
 *
 * Klasa ActionVisitorImpl implementuje interfejs Visitor
 * i odpowiada za wykonywanie działań charakterystycznych
 * dla różnych typów urządzeń.
 */
class ActionVisitorImpl : public Visitor {

    public:

        /**
         * @brief Wykonuje akcję dla sensora.
         *
         * @param s referencja do obiektu Sensor
         */
        void visit(Sensor& s) override;

        /**
         * @brief Wykonuje akcję dla routera.
         *
         * @param r referencja do obiektu Router
         */
        void visit(Router& r) override;

        /**
         * @brief Wykonuje akcję dla kamery.
         *
         * @param c referencja do obiektu Camera
         */
        void visit(Camera& c) override;
};