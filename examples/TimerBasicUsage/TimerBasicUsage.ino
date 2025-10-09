#include <Timer.h>

#define TIMEOUT_MS 1000

Timer timer(TIMEOUT_MS);

void setup() {
  Serial.begin(9600);
  delay(500);

  timer.start();
}

void loop() {
  if(timer.tick()) {
    Serial.println("tick");
    //...
  }
}
