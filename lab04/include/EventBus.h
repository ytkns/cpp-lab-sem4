#pragma once
#include <vector>
#include <queue>
#include "IEvent.h"
#include "DamageEvent.h"
using namespace std;


/**
 * @brief Klasa EventBus.
 * Rejestruje Callbacki, rozsyła eventy.
 */
class EventBus {   
    public:
        /**
         * @brief Definicja typu wskaźnika na Callback.
         * Callback przyjmuje wskaźnik na IEvent.
         */
        typedef void (*Callback)(IEvent*);

        /**
         * @brief Destruktor klasy EventBus.
         */
        ~EventBus();

        /**
         * @brief Rejestruje nowy callback, ktory jest powiadomiony o evencie.
         * @param cb Wskaźnik na funkcję typu Callback.
         */
        void subscribe(Callback cb);

        /**
         * @brief Dodaje nowy event do kolejki.
         * @param e Wskaźnik na event.
         */
        void pushEvent(IEvent* e);

        /**
         * @brief Przetwarza wszystkie zdarzenia zgromadzone w kolejce.
         * Dla każdego zdarzenia wywołuje wszystkie zarejestrowane subskrypcje (callbacki).
         */
        void processEvents(); 

        /** @brief Przeciążony operator wywołania.
         * @param[in] event Wskaźnik do obiektu zdarzenia (musi być utworzony dynamicznie).
         */
        void operator()(IEvent* event);

        /** @brief Zwraca referencję do jedynej instancji klasy (Wzorzec Singleton).
         * @return Referencja do statycznej instancji klasy EventBus.
         */
        static EventBus& getInstance();
        
        /**
        * @brief Operator indeksowania - zwraca callback o podanym indeksie.
        * @param[in] index Indeks callbacka.
        * @return Callback.
        */
        Callback operator[](int index);
        
    private:
        /**
         * @brief Lista wszystkich zarejestrowanych subskryberów.
         */
        vector<Callback> subscribers;

        /**
         * @brief Kolejka FIFO przechowująca eventy do przetworzenia.
         */
        queue<IEvent*> events;

        
};

