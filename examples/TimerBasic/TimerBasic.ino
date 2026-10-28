#include <Arduino.h>
#include <Timer.h>

constexpr uint32_t INTERVAL_MS = 1000;

Timer timer(INTERVAL_MS);

void setup() {
    Serial.begin(9600);
    delay(500);
    timer.start(millis());
}

void loop() {
    const uint32_t nowMs = millis();
    if (timer.poll(nowMs)) {
        Serial.print("Interval elapsed at: ");
        Serial.print(nowMs);
        Serial.println(" ms");
    }
}
