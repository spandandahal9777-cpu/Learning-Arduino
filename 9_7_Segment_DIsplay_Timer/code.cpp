// 9_7_Segment_DIsplay_Timer

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

// Initialize the 7-segment display object
Adafruit_7segment display = Adafruit_7segment();

// Set initial countdown time in seconds (e.g., 150 seconds = 2 minutes 30 seconds)
int totalSeconds = 10;

void setup() {
  // Default I2C address for the HT16K33 backpack is 0x70
  display.begin(0x70);
  
  // Set brightness level from 0 (dimmest) to 15 (brightest)
  display.setBrightness(15);
}

void loop() {
  if (totalSeconds >= 0) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    
    // Format minutes and seconds into a 4-digit number (e.g., 2:30 becomes 230)
    int displayValue = (minutes * 100) + seconds;

    // Send value to display buffer
    display.print(displayValue, DEC);
    
    // Turn on the center colon dots (resembles a clock/timer)
    display.drawColon(true);
    
    // Push updates to the physical screen
    display.writeDisplay();

    delay(1000); // Wait 1 second
    totalSeconds--; // Decrement time
  } else {
    // Time's up: flash the display 3 times
    for (int i = 0; i < 3; i++) {
      display.clear();
      display.drawColon(false);
      display.writeDisplay();
      delay(250);
      
      display.print(0, DEC);
      display.drawColon(true);
      display.writeDisplay();
      delay(250);
    }
    while (1); // Halt execution when complete
  }
}