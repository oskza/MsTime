#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <Arduino.h>

class StopWatch {
private:
    uint32_t _ms;
    bool _state;
    uint32_t getElapsedTime();
public:
    StopWatch();
    virtual ~StopWatch();
    bool isRunning();
    void start();
    uint32_t stop();
    uint32_t lap();
};
#endif
