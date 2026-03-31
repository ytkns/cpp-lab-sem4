#pragma once
#include "EventBus.h"

/** 
  * @brief Klasa pośrednicząca dla EventBus (Wzorzec Proxy). 
  */
class BusProxy : public EventBus {
public:
    /** 
     * @brief Konstruktor przyjmujący referencję do oryginalnego eventbusa. 
     */
    BusProxy(EventBus& b);
    
    /** 
     * @brief Nadpisana metoda subskrypcji, rejestruje w obu eventbusach. 
     */
    void subscribe(Callback cb);

    /** 
     * @brief Metoda przetwarza zdarzenia z obu eventbusów. 
     */
    void processEvents();

private:

    EventBus& realBus;
};