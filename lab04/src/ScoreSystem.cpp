#include "ScoreSystem.h"
#include "IEvent.h"
#include "DamageEvent.h"
void ScoreSystem::handleEvent(IEvent* e){
    if (e->getType() == EventType::DAMAGE) {
        DamageEvent* ev = (DamageEvent*)e;
        cout << "[ScoreSystem] Enemy " << ev->getId() << " took " << ev->getDmg() << " damage" << endl;
    }
}