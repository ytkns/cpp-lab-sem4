#include "HealEvent.h"

HealEvent::HealEvent(int i): IEvent(EventType::HEAL, i){}


HealEvent::HealEvent(int i, int n): IEvent(EventType::HEAL, i), hp(n) {}