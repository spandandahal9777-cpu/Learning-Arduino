// 4_Potentiometer_LED_Dimmer

// Pin Definitions
const int PIN_POT = A0; // Red potentiometer
const int PIN_LED = 9;  // Red LED (PWM)

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  const int pot = analogRead(PIN_POT);  // returns value from 0-1023

  // maps potentiometer values 0-1023 to pwn values 0-255
  // map(from, fromLow, fromHigh, toLow, toHigh)
  const uint8_t pwm = static_cast<uint8_t>(map(pot, 0, 1023, 0, 255));
  
  analogWrite(PIN_LED, pwm);
  delay(5);
}