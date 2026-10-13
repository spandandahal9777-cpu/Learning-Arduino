// 3_RGB_Color_Mixer

// Pin Definitions
const int PIN_POT_R = A0; // Red potentiometer
const int PIN_POT_G = A1; // Green potentiometer
const int PIN_POT_B = A2; // Blue potentiometer

const int PIN_LED_R = 9;  // Red LED (PWM)
const int PIN_LED_G = 10; // Green LED (PWM)
const int PIN_LED_B = 11; // Blue LED (PWM)

void setup() {
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
}


void loop() {
  const int potR = analogRead(PIN_POT_R); // returns value from 0-1023
  const int potG = analogRead(PIN_POT_G); 
  const int potB = analogRead(PIN_POT_B); 

  // maps potentiometer values 0-1023 to pwn values 0-255
  // map(from, fromLow, fromHigh, toLow, toHigh)
  const uint8_t pwmR = static_cast<uint8_t>(map(potR, 0, 1023, 0, 255));
  const uint8_t pwmG = static_cast<uint8_t>(map(potG, 0, 1023, 0, 255));
  const uint8_t pwmB = static_cast<uint8_t>(map(potB, 0, 1023, 0, 255));

  // sets that PWN value to LED pins as analog output
  analogWrite(PIN_LED_R, pwmR);
  analogWrite(PIN_LED_G, pwmG);
  analogWrite(PIN_LED_B, pwmB);

  delay(5);
}