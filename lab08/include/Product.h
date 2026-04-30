#pragma once
#include <iostream>
using namespace std;

/**
 * @class Product
 * @brief Klasa reprezentująca produkt o określonym typie i ilości.
 * * Klasa umożliwia zarządzanie stanem magazynowym produktu poprzez różne
 * operatory (arytmetyczne, porównujące oraz inkrementacja/dekrementacja).
 */
class Product {
    private:
        int typ;   /** Identyfikator typu produktu */
        int ilosc; /** Liczba sztuk produktu */

    public:
        /**
         * @brief Pobiera aktualną ilość produktu.
         * @return Liczba sztuk (int).
         */
        int get_ilosc();

        /**
         * @brief Konstruktor inicjalizujący produkt.
         * @param t Typ produktu.
         * @param n Początkowa ilość produktu.
         */
        Product(int t, int n);

        /**
         * @brief Operator dostępu (indeksowy).
         * @param n Indeks (zależnie od implementacji, np. dostęp do cech).
         * @return Wartość powiązana z indeksem.
         */
        int operator[](int n);

        /**
         * @brief Preinkrementacja (++obj). Zwiększa ilość o 1.
         * @return Referencja do zmodyfikowanego obiektu.
         */
        Product& operator++();

        /**
         * @brief Postinkrementacja (obj++). Zwiększa ilość o 1.
         * @return Kopia obiektu sprzed inkrementacji.
         */
        Product operator++(int);

        /**
         * @brief Predekrementacja (--obj). Zmniejsza ilość o 1.
         * @return Referencja do zmodyfikowanego obiektu.
         */
        Product& operator--();

        /**
         * @brief Postdekrementacja (obj--). Zmniejsza ilość o 1.
         * @return Kopia obiektu sprzed dekrementacji.
         */
        Product operator--(int);

        /**
         * @brief Operator dodawania wartości do ilości.
         * @param n Wartość do dodania.
         * @return Nowy obiekt Product ze zwiększoną ilością.
         */
        Product operator+(int n);

        /**
         * @brief Operator odejmowania wartości od ilości.
         * @param n Wartość do odjęcia.
         * @return Nowy obiekt Product ze zmniejszoną ilością.
         */
        Product operator-(int n);

        /**
         * @brief Operator mnożenia ilości.
         * @param n Mnożnik.
         * @return Nowy obiekt Product z przemnożoną ilością.
         */
        Product operator*(int n);

        /** @name Operatory porównania
         * Porównują ilość (ilosc) bieżącego produktu z innym.
         * @{
         */
        bool operator<(const Product& other);
        bool operator>(const Product& other);
        bool operator<=(const Product& other);
        bool operator>=(const Product& other);
        bool operator==(const Product& other);
        bool operator!=(const Product& other);
        /** @} */

        /**
         * @brief Przeciążony operator strumienia wyjściowego.
         * Pozwala na wypisanie danych o produkcie (np. typ i ilość) do konsoli.
         * @param os Strumień wyjściowy.
         * @param p Obiekt klasy Product do wypisania.
         * @return Referencja do strumienia wyjściowego.
         */
        friend ostream& operator<<(ostream& os, const Product& p);
};