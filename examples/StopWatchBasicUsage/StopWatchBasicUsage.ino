#include <StopWatch.h>

void setup() {
    Serial.begin(9600);
    delay(500);

    StopWatch stopwatch;

    Serial.println("Starting stopwatch...");
    stopwatch.start();

    Serial.println("Waiting 1 sec...");
    delay(1000);

    uint32_t lap = stopwatch.lap();
    Serial.print("Lap: "); Serial.print(lap); Serial.println(" ms");

    Serial.println("Waiting 2 sec...");
    delay(2000);

    uint32_t total = stopwatch.stop();
    Serial.print("Total:  "); Serial.print(total); Serial.println(" ms");
}

void loop() {}
