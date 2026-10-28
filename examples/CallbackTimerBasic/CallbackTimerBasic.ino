#include <Arduino.h>
#include <CallbackTimer.h>

#define INTERVAL_MS 1000
#define REPEAT_LIMIT 5

CallbackTimer timer(INTERVAL_MS, REPEAT_LIMIT);

void handleElapsed() { Serial.println("Elapsed"); }

void setup() {
    Serial.begin(9600);
    delay(500);

    timer.onStart([]() { Serial.println("Start"); });
    timer.onElapsed(handleElapsed);
    timer.onStop([]() { Serial.println("Stop"); });
    timer.start(millis());
}

void loop() { timer.poll(millis()); }
