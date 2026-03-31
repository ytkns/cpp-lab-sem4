#include "LootSystem.h"
#include "IEvent.h"
#include "ItemEvent.h"

void LootSystem::handleEvent(IEvent* e){
    if(e->getType() == EventType::ITEM){
        ItemEvent *it = (ItemEvent*)e; 
        cout << "[LootSystem] Player " << it->getId() << " picked up: " << it->getName() << endl;
    }
}