#pragma once
#include <iostream>

/** 
  * @brief Klasa służąca do gromadzenia i obliczania statystyk ciągu liczb.
  * Klasa przechowuje sumę, liczbę elementów oraz wartości min i max.
  */
class Statistics {
private:
    int sum = 0;
    int count = 0;
    int max_val = 0; 
    int min_val = 0;

public:
    /** 
      * @brief Aktualizuje statystyki o nową wartość.
      * @param[in] a Wartość, która zostanie uwzględniona w obliczeniach średniej, min i max.
      */
    void operator()(int a);

    /** 
      * @brief Wypisuje podsumowanie statystyk na standardowe wyjście.
      * Wyświetla średnią, wartość najmniejszą oraz największą.
      */
    void Print() const;
};