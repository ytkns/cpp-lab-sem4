#pragma once
#include <iostream>

/**
  * @brief Klasa analizująca relacje w parach liczb.
  * Klasa zlicza ile par liczb jest sobie równych, ile rosnących i ile malejących.
  */
class PairStatistics {
    private:
        int equal;      // Liczba par o równej wartości
        int increasing; // Liczba par rosnących
        int decreasing; // Liczba par malejących

    public:
        /** 
          * @brief Konstruktor domyślny.
          * Inicjalizuje wszystkie liczniki wartością 0.
          */
        PairStatistics();

        /**
          * @brief Analizuje relację między podanymi liczbami i aktualizuje liczniki.
          * @param[in] a Pierwszy element pary.
          * @param[in] b Drugi element pary.
          */
        void operator()(int a, int b);

        /** 
          * @brief Wypisuje statystyki par na standardowe wyjście.
          */
        void Print() const;
};