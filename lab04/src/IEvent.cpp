#include "IEvent.h"

IEvent::IEvent(EventType t, int i): type(t), id(i) {}

EventType IEvent::getType() const {
    return type;
} 

int IEvent::getId() const{
    return id;
}
