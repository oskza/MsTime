#ifndef MSTIME_TIMER_H
#define MSTIME_TIMER_H
#include <stdint.h>

class Timer {
private:
    uint32_t _intervalMs;
    uint32_t _repeatLimit;
    uint32_t _referenceMs;
    uint32_t _completedRepeats;
protected:
    bool running;
public:
    Timer();
    Timer(uint32_t timeout, uint32_t numRepeats = 0);
    virtual ~Timer() = default;
    virtual void start(uint32_t nowMs);
    virtual void stop();
    void reset(uint32_t nowMs);
    virtual bool poll(uint32_t nowMs);
    bool isRunning() const;
    bool hasElapsed(uint32_t nowMs, uint32_t durationMs) const;
    uint32_t getElapsedTime(uint32_t nowMs) const;
    void setIntervalMs(uint32_t ms);
    void setRepeatLimit(uint32_t limit);
};
#endif
