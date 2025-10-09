#include <StopWatch.h>

void setup() {
    Serial.begin(9600);
    delay(500);

    Serial.println("Starting stopwatch...");

    StopWatch stopwatch;

    stopwatch.start();
    delay(1000);

    uint32_t lap = stopwatch.lap();
    delay(1000);

    uint32_t total = stopwatch.stop();

    Serial.print("Lap: "); Serial.println(lap);
    Serial.print("Total:  "); Serial.println(total);
}

void loop() {}
