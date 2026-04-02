#pragma once
#include <iostream>

/** 
 * @brief Inteligentny wskaźnik z mechanizmem zliczania referencji.
 * Klasa zarządza czasem życia obiektu typu T, usuwając go automatycznie,
 * gdy ostatni SPtr wskazujący na niego zostanie zniszczony.
 */
template<typename T>
class SPtr {
public:
    /** @brief Konstruktor tworzący inteligentny wskaźnik.
     * * @param[in] p Wskaźnik do surowego obiektu (domyślnie nullptr).
     */
    explicit SPtr(T* p = nullptr) : ptr(p), count(nullptr) {
        if (ptr) {
            count = new int(1);
            std::cout << "count = " << *count << std::endl;
        }
    }

    /** 
     * @brief Konstruktor kopiujący.
     * Zwiększa licznik referencji dla współdzielonego obiektu.
     * @param[in] other Inny obiekt SPtr tego samego typu.
     */
    SPtr(const SPtr& other) : ptr(other.ptr), count(other.count) {
        if (count) {
            (*count)++;
            std::cout << "count = " << *count << std::endl;
        }
    }

    /** 
     * @brief Destruktor.
     * Zmniejsza licznik referencji i zwalnia pamięć, jeśli licznik osiągnie zero.
     */
    ~SPtr() {
        decrement();
    }

    /** 
     * @brief Operator kopiujący przypisania.
     * Zwalnia aktualnie posiadany obiekt i przejmuje nowy od innego SPtr.
     * @param[in] other Obiekt, z którego kopiujemy wskaźnik.
     * @return Referencja do aktualnego obiektu.
     */
    SPtr& operator=(const SPtr& other) {
        if (this != &other) {
            decrement();
            ptr = other.ptr;
            count = other.count;
            if (count) {
                (*count)++;
                std::cout << "count = " << *count << std::endl;
            }
        }
        return *this;
    }

    /** 
     * @brief Operator dostępu do składowych obiektu.
     * @return Wskaźnik do zarządzanego obiektu.
     */
    T* operator->() const {
        return ptr;
    }

    /**
     * @brief Operator dereferencji.
     * @return Referencja do zarządzanego obiektu.
     */
    T& operator*() const {
        return *ptr;
    }

private:
    /** 
     * @brief Metoda pomocnicza zmniejszająca licznik referencji.
     * Jeśli licznik wynosi 0, zwalnia pamięć zajmowaną przez obiekt i licznik.
     */
    void decrement() {
        if (count) {
            (*count)--;
            std::cout << "count = " << *count << std::endl;
            if (*count == 0) {
                delete ptr;
                delete count;
            }
            ptr = nullptr;
            count = nullptr;
        }
    }

    T* ptr;      // Wskaźnik na obiekt
    int* count;  // Wskaźnik na współdzielony licznik referencji
};