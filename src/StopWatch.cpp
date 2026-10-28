#include "StopWatch.h"

StopWatch::StopWatch() : _referenceMs(0), running(false) {}

uint32_t StopWatch::getElapsedTime(uint32_t nowMs) const { return nowMs - _referenceMs; }

void StopWatch::start(uint32_t nowMs) {
    if(running)
        return;
    running = true;
    _referenceMs = nowMs;
}

uint32_t StopWatch::stop(uint32_t nowMs) {
    if(!running)
        return 0;
    uint32_t elapsedMs = getElapsedTime(nowMs);
    _referenceMs = 0;
    running = false;
    return elapsedMs;
}

uint32_t StopWatch::lap(uint32_t nowMs) const { return running ? getElapsedTime(nowMs) : 0; }

bool StopWatch::isRunning() const { return running; }
