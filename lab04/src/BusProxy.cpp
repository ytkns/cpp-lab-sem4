#include "BusProxy.h"

BusProxy::BusProxy(EventBus& b) : realBus(b) {}

void BusProxy::subscribe(Callback cb) {
    realBus.subscribe(cb);
    EventBus::subscribe(cb);
}

void BusProxy::processEvents() {
    realBus.processEvents();
    EventBus::processEvents();
}