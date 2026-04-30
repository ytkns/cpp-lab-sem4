#pragma once
#include <algorithm>
#include "Shop.h"

/**
 * @class SortShop
 * @brief Specjalizacja sklepu utrzymująca produkty w stanie posortowanym.
 * 
 * Klasa dziedziczy po Shop i nadpisuje kluczowe metody tak, aby kolekcja produktów 
 * była zawsze ułożona rosnąco według liczby sztuk towaru.
 */
class SortShop : public Shop {
    private:
        /**
         * @brief Metoda pomocnicza sortująca wewnętrzny kontener produktów.
         * Wykorzystuje std::sort.
         */
        void mySort();

    public:
        /**
         * @brief Konstruktor konwertujący z klasy bazowej Shop.
         * Umożliwia operacje typu: SortShop = SortShop + int.
         * @param s Obiekt klasy bazowej, którego produkty zostaną przejęte i posortowane.
         */
        SortShop(const Shop& s);

        /**
         * @brief Konstruktor domyślny. Tworzy pusty, posortowany sklep.
         */
        SortShop() = default;

        /**
         * @brief Dodaje nowy produkt i sortuje kolekcję.
         * @param p Obiekt klasy Product do dodania.
         */
        void Add(const Product& p) override;

        /**
         * @brief Daje dostęp do produktu. Po potencjalnej modyfikacji przez referencję 
         * obiekt wymusza ponowne sortowanie, aby zachować spójność.
         * @param i Indeks produktu.
         * @return Referencja do produktu.
         */
        Product& operator[](int i);

        /**
         * @brief Tworzy nowy obiekt SortShop zawierający produkty z zakresu [i, j].
         * Nadpisuje zachowanie z klasy bazowej, aby wynik również był typu SortShop.
         * @param i Indeks początkowy.
         * @param j Indeks końcowy.
         * @return Nowy obiekt SortShop.
         */
        SortShop operator()(int i, int j);

        /**
         * @brief Przeciążony operator strumienia wyjściowego dla klasy pochodnej.
         * Wyświetla listę wszystkich produktów znajdujących się w sklepie.
         * @param os Strumień wyjściowy.
         * @param sh Obiekt klasy SortShop do wyświetlenia.
         * @return Referencja do strumienia wyjściowego.
         */
        friend ostream& operator<<(ostream& out, SortShop& s);
};