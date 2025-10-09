#include "StopWatch.h"

StopWatch::StopWatch() : _ms(0), _state(false) {}

StopWatch::~StopWatch() {}

uint32_t StopWatch::getElapsedTime() { return millis() - _ms; }

bool StopWatch::isRunning() { return _state; }

void StopWatch::start() {
    if(_state)
        return;
    _state = true;
    _ms = millis();
}

uint32_t StopWatch::stop() {
    if(!_state)
        return 0;
    uint32_t tm = getElapsedTime();
    _ms = 0;
    _state = false;
    return tm;
}

uint32_t StopWatch::lap() { return _state ? getElapsedTime() : 0; }
