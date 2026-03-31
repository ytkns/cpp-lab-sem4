#include "Player.h"
#include "IEvent.h"
#include "HealEvent.h"
#include "ItemEvent.h"

Player::Player(int i, int h, EventBus& b): Entity(i, h, b) {}

void Player::heal(int i){
    hp+=i;
    bus.pushEvent(new HealEvent(id));
}

void Player::pickItem(const string& item){
    bus.pushEvent(new ItemEvent(id, item));
}