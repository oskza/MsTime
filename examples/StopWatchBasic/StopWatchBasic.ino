#include <Arduino.h>
#include <StopWatch.h>

void setup() {
    Serial.begin(9600);
    delay(500);

    StopWatch stopwatch;

    const uint32_t startedAtMs = millis();
    stopwatch.start(startedAtMs);
    Serial.print("Starting stopwatch at: ");
    Serial.print(startedAtMs);
    Serial.println(" ms");

    Serial.println("Waiting 1 sec...");
    delay(1000);

    uint32_t lap = stopwatch.lap(millis());
    Serial.print("Lap: "); Serial.print(lap); Serial.println(" ms");

    Serial.println("Waiting 2 sec...");
    delay(2000);

    uint32_t total = stopwatch.stop(millis());
    Serial.print("Total:  "); Serial.print(total); Serial.println(" ms");
}

void loop() {}
