#include "EventBus.h"

EventBus::~EventBus() {
    while(!events.empty()) { 
        delete events.front(); 
        events.pop(); 
    }
}

void EventBus::subscribe(Callback cb){
    subscribers.push_back(cb);
}

void EventBus::pushEvent(IEvent* e){
    events.push(e);
}

void EventBus::processEvents(){
    while(!events.empty()){
        IEvent* e = events.front();
        events.pop();

        for (auto cb : subscribers) 
            cb(e);

        delete e;
    }
}

void EventBus::operator()(IEvent* event){
    pushEvent(event);
}

EventBus& EventBus::getInstance() {
    static EventBus instance;
    return instance;
}

EventBus::Callback EventBus::operator[](int index) {
    if (index >= 0 && index < (int)subscribers.size()) {
        return subscribers[index];
    }
    return nullptr;
}
