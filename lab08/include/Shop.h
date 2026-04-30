#pragma once
#include <vector>
#include "Product.h"

/**
 * @class Shop
 * @brief Klasa bazowa reprezentująca sklep przechowujący kolekcję produktów.
 * 
 * Klasa zarządza dynamiczną listą obiektów typu Product. Służy jako fundament 
 * dla sklepów specjalistycznych (jak SortShop). Definiuje interfejs dla operacji 
 * dodawania, usuwania i masowej modyfikacji ilości produktów.
 */
class Shop {
    protected:
        vector<Product> s; /**< Kontener przechowujący produkty. Chroniony, aby klasy pochodne miały do niego bezpośredni dostęp. */

    public:
        /**
         * @brief Wirtualny destruktor zapewniający poprawne usuwanie obiektów klas pochodnych.
         */
        virtual ~Shop() = default;

        /**
         * @brief Konstruktor domyślny. Tworzy pusty sklep.
         */
        Shop();

        /**
         * @brief Konstruktor kopiujący.
         * @param other Inny obiekt klasy Shop.
         */
        Shop(const Shop& other);

        /**
         * @brief Dodaje nowy produkt na koniec kolekcji.
         * Metoda wirtualna – klasa pochodna może zmienić sposób dodawania (wymusza sortowanie).
         * @param p Obiekt klasy Product do dodania.
         */
        virtual void Add(const Product& p);

        /**
         * @brief Usuwa ostatni produkt z kolekcji.
         */
        void Remove();

        /**
         * @brief Czyści całą zawartość sklepu.
         */
        void Clear();

        /**
         * @brief Operator przypisania głębokiego.
         * @param other Obiekt źródłowy.
         * @return Referencja do aktualnego obiektu Shop.
         */
        Shop& operator=(const Shop& other);

        /**
         * @brief Tworzy nowy sklep, zwiększając ilość każdego produktu o n.
         * @param n Wartość zwiększenia.
         * @return Nowy obiekt Shop (zawsze typu bazowego).
         */
        Shop operator+(int n);

        /**
         * @brief Tworzy nowy sklep, zmniejszając ilość każdego produktu o n.
         * @param n Wartość zmniejszenia.
         * @return Nowy obiekt Shop (zawsze typu bazowego).
         */
        Shop operator-(int n);

        /**
         * @brief Tworzy nowy sklep, mnożąc ilość każdego produktu przez n.
         * @param n Mnożnik.
         * @return Nowy obiekt Shop (zawsze typu bazowego).
         */
        Shop operator*(int n);

        /**
         * @brief Daje bezpośredni dostęp do produktu pod indeksem.
         * @param i Indeks produktu.
         * @return Referencja do produktu.
         */
        Product& operator[](int i);

        /**
         * @brief Tworzy nowy sklep zawierający kopie produktów z zakresu [i, j].
         * @param i Indeks początkowy.
         * @param j Indeks końcowy.
         * @return Obiekt Shop z podzakresem produktów.
         */
        Shop operator()(int i, int j);

        /** @name Operatory porównania
         * Porównują sumaryczną liczbę sztuk wszystkich produktów w dwóch sklepach.
         * @{
         */
        bool operator<(const Shop& other);
        bool operator>(const Shop& other);
        bool operator<=(const Shop& other);
        bool operator>=(const Shop& other);
        bool operator==(const Shop& other);
        bool operator!=(const Shop& other);
        /** @} */

        /**
         * @brief Przeciążony operator strumienia wyjściowego dla klasy bazowej.
         * Wyświetla listę wszystkich produktów znajdujących się w sklepie.
         * @param os Strumień wyjściowy.
         * @param sh Obiekt klasy Shop do wyświetlenia.
         * @return Referencja do strumienia wyjściowego.
         */
        friend ostream& operator<<(ostream& os, Shop& sh);
};