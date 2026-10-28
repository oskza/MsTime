#include "Timer.h"

Timer::Timer() 
    : _intervalMs(5), 
    _repeatLimit(0), 
    _referenceMs(0), 
    _completedRepeats(0), 
    running(false) {}

Timer::Timer(uint32_t timeout, uint32_t numRepeats)
        : _repeatLimit(numRepeats), 
        _referenceMs(0), 
        _completedRepeats(0), 
        running(false) { 
    setIntervalMs(timeout); 
}

void Timer::stop() {
    running = false;
    _referenceMs = 0;
    _completedRepeats = 0;
}

void Timer::start(uint32_t nowMs) {
    running = true;
    _referenceMs = nowMs;
    _completedRepeats = 0;
}

void Timer::reset(uint32_t nowMs) { _referenceMs = nowMs; }

bool Timer::isRunning() const { return running; }

uint32_t Timer::getElapsedTime(uint32_t nowMs) const { return nowMs - _referenceMs; }

bool Timer::hasElapsed(uint32_t nowMs, uint32_t durationMs) const {
    return running && getElapsedTime(nowMs) >= durationMs;
}

bool Timer::poll(uint32_t nowMs) {
    if (!hasElapsed(nowMs, _intervalMs))
        return false;
    if (_repeatLimit > 0 && ++_completedRepeats >= _repeatLimit) {
        Timer::stop();
        return true;
    }
    reset(nowMs);
    return true;
}

void Timer::setIntervalMs(uint32_t ms) { _intervalMs = (ms == 0) ? 5 : ms; }

void Timer::setRepeatLimit(uint32_t limit) { _repeatLimit = limit; }
