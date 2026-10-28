#include "CallbackTimer.h"

CallbackTimer::CallbackTimer()
    : Timer(),
    _onElapsed(nullptr),
    _onStart(nullptr),
    _onStop(nullptr) {}

CallbackTimer::CallbackTimer(uint32_t intervalMs, uint32_t repeatLimit)
    : Timer(intervalMs, repeatLimit),
    _onElapsed(nullptr),
    _onStart(nullptr),
    _onStop(nullptr) {}

void CallbackTimer::onElapsed(Callback cb) { _onElapsed = cb; }

void CallbackTimer::onStart(Callback cb) { _onStart = cb; }

void CallbackTimer::onStop(Callback cb) { _onStop = cb; }

void CallbackTimer::clearCallbacks() {
    _onElapsed = nullptr;
    _onStart = nullptr;
    _onStop = nullptr;
}

void CallbackTimer::stop() {
    const bool wasRunning = isRunning();
    Timer::stop();
    if (wasRunning && _onStop)
        _onStop();
}

void CallbackTimer::start(uint32_t nowMs) {
    if (isRunning())
        return;
    Timer::start(nowMs);
    if (_onStart)
        _onStart();
}

bool CallbackTimer::poll(uint32_t nowMs) {
    if (!Timer::poll(nowMs))
        return false;
    // Capture completion before callbacks can start another run or change handlers
    Callback onStopCb = isRunning() ? nullptr : _onStop;
    if (_onElapsed)
        _onElapsed();
    if (onStopCb)
        onStopCb();
    return true;
}
