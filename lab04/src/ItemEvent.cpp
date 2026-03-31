#include "ItemEvent.h"

ItemEvent::ItemEvent(int i, string n): IEvent(EventType::ITEM, i), name(n) {}

string ItemEvent::getName() const{
    return name;
}