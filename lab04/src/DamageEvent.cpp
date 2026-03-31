#include "DamageEvent.h"

DamageEvent::DamageEvent(int i, int dmg): IEvent(EventType::DAMAGE, i), damage(dmg) {}

int DamageEvent::getDmg() const{
    return damage;
}