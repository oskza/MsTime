#include <TaskTimer.h>

#define TIMEOUT_MS  1000
#define NUM_REPEATS 5

void onStart() { 
  Serial.println("Start"); 
  //...
}

void onReset() { 
  Serial.println("Reset"); 
  //...
}

TaskTimer timer(
  TIMEOUT_MS,
  [](){ 
    Serial.println("Exec"); 
    //...
  },
  onStart,
  onReset,
  NUM_REPEATS
);

void setup() {
  Serial.begin(9600);
  delay(500);
  
  timer.start();
}

void loop() { 
  timer.tick();
}
