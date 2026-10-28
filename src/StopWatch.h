#ifndef MSTIME_STOPWATCH_H
#define MSTIME_STOPWATCH_H
#include <stdint.h>

class StopWatch {
private:
    uint32_t _referenceMs;
    bool running;
    uint32_t getElapsedTime(uint32_t nowMs) const;
public:
    StopWatch();
    void start(uint32_t nowMs);
    uint32_t stop(uint32_t nowMs);
    uint32_t lap(uint32_t nowMs) const;
    bool isRunning() const;
};
#endif
