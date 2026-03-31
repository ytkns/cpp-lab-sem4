#include "Enemy.h"
#include "IEvent.h"
#include "DamageEvent.h"

Enemy::Enemy(int i, int h, EventBus& b): Entity(i, h, b) {}

void Enemy::takeDamage(int dmg){
    hp-=dmg;
    bus.pushEvent(new DamageEvent(id, dmg));
}