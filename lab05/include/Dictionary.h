#pragma once
#include <iostream>
#include <string>
#include <map>

/**
  * @brief Klasa reprezentująca prosty słownik asocjacyjny. 
  */
class Dictionary{
    private:
        std::map<std::string, int> dict;
        
    public:
    /**
      * @brief Przeciążony operator dostępu do elementu. 
      */
        int& operator[](const std::string& s);

    /** 
      * @brief Wypisuje zawartość słownika
      */
        void print() const;

    /**
      * @brief Czyści zawartość słownika
      */
        void clear();

};