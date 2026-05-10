#pragma once

#include "Visitor.h"

/**
 * @brief Klasa realizująca diagnostykę urządzeń.
 *
 * Klasa DiagnosticVisitorImpl implementuje interfejs Visitor
 * i odpowiada za wykonywanie diagnostyki różnych typów urządzeń.
 */
class DiagnosticVisitorImpl : public Visitor {

    public:

        /**
         * @brief Wykonuje diagnostykę sensora.
         *
         * @param s referencja do obiektu Sensor
         */
        void visit(Sensor& s) override;

        /**
         * @brief Wykonuje diagnostykę routera.
         *
         * @param r referencja do obiektu Router
         */
        void visit(Router& r) override;

        /**
         * @brief Wykonuje diagnostykę kamery.
         *
         * @param c referencja do obiektu Camera
         */
        void visit(Camera& c) override;
};