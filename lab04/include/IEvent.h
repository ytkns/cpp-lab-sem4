#pragma once
#include <string>
using namespace std;

/**
 * @brief Typ wyliczeniowy określający rodzaj zdarzenia.
 * Identyfikuje typ eventu
 */
enum class EventType { DAMAGE, HEAL, ITEM };


/**
 * @brief Klasa bazowa dla wszystkich zdarzeń.
 * Zawiera wspólne dane dla każdego zdarzenia.
 */
class IEvent {
    protected:
        EventType type;
        int id;
    public:
        /**
         * @brief Konstruktor inicjalizujący dane zdarzenia.
         * @param t Typ zdarzenia.
         * @param i Identyfikator zdarzenia.
         */
        IEvent(EventType t, int i);

        /**
         * @brief Wirtualny destruktor.
         */
        virtual ~IEvent() = default;

        /**
         * @brief Funkcja zwracająca typ zdarzenia.
         * Funkcja zwraca typ zdarzenia.
         */
        EventType getType() const;

        /**
         * @brief Funkcja zwracająca identyfikator zdarzenia.
         * Funkcja zwraca id zdarzenia.
         */
        int getId() const;
};


