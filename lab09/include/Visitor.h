#pragma once

class Sensor;
class Router;
class Camera;

/**
 * @brief Interfejs odwiedzającego.
 *
 * Klasa Visitor definiuje interfejs wzorca projektowego Visitor.
 * Umożliwia wykonywanie różnych operacji na obiektach klas
 * Sensor, Router oraz Camera bez modyfikowania tych klas.
 */
class Visitor {

    public:

        /**
         * @brief Wirtualny destruktor klasy Visitor.
         */
        virtual ~Visitor() = default;

        /**
         * @brief Odwiedza obiekt klasy Sensor.
         *
         * @param s referencja do obiektu Sensor
         */
        virtual void visit(Sensor& s) = 0;

        /**
         * @brief Odwiedza obiekt klasy Router.
         *
         * @param r referencja do obiektu Router
         */
        virtual void visit(Router& r) = 0;

        /**
         * @brief Odwiedza obiekt klasy Camera.
         *
         * @param c referencja do obiektu Camera
         */
        virtual void visit(Camera& c) = 0;
};