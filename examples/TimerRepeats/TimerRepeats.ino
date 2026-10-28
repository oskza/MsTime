#include <Arduino.h>
#include <Timer.h>

constexpr uint32_t INTERVAL_MS = 1000;
constexpr uint32_t REPEAT_LIMIT = 5;

Timer timer(INTERVAL_MS, REPEAT_LIMIT);
uint32_t completedRepeats = 0;

void setup() {
    Serial.begin(9600);
    delay(500);
    timer.start(millis());
}

void loop() {
    const uint32_t nowMs = millis();
    if (timer.poll(nowMs)) {
        ++completedRepeats;
        Serial.print("Repeat: ");
        Serial.print(completedRepeats);
        Serial.print(" / ");
        Serial.println(REPEAT_LIMIT);

        if (!timer.isRunning()) {
            Serial.println("All repeats completed; timer stopped.");
        }
    }
}
