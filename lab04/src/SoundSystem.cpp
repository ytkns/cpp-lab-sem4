#include "SoundSystem.h"
#include "IEvent.h"
#include "HealEvent.h"
#include "DamageEvent.h"
#include "ItemEvent.h"
void SoundSystem::handleEvent(IEvent* e){
    if(e->getType() == EventType::DAMAGE)
        cout << "[SoundSystem] Play hit sound" << endl;
    else if(e->getType() == EventType::HEAL)
        cout << "[SoundSystem] Play heal sound" << endl;
    else if(e->getType() == EventType::ITEM)
        cout << "[SoundSystem] Play item pickup sound" << endl;
}