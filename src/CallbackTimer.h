#ifndef MSTIME_CALLBACK_TIMER_H
#define MSTIME_CALLBACK_TIMER_H
#include "Timer.h"

class CallbackTimer : public Timer {
public:
    using Callback = void (*)();
    CallbackTimer();
    CallbackTimer(uint32_t intervalMs, uint32_t repeatLimit = 0);
    void onElapsed(Callback cb);
    void onStart(Callback cb);
    void onStop(Callback cb);
    void clearCallbacks();
    void stop() override;
    void start(uint32_t nowMs) override;
    bool poll(uint32_t nowMs) override;
private:
    Callback _onElapsed;
    Callback _onStart;
    Callback _onStop;
};
#endif
