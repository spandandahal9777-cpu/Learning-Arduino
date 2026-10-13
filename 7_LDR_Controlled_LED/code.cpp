// 7_LDR_Controlled_LED

// Pin Definitions with types indicated
const int sensorPin = A0;  // Analog Pin (A): Reads light level from the LDR circuit
const int ledPin = 9;      // Digital / PWM Pin (~): Controls the nightlight LED

// Threshold value for darkness (you can adjust this after testing)
const int threshold = 400; 

void setup() {
  pinMode(ledPin, OUTPUT);       // Set the LED pin as an output
  Serial.begin(9600);            // Start serial communication to view readings
}

void loop() {
  // Read the analog voltage from the sensor (range: 0 to 1023)
  int sensorValue = analogRead(sensorPin);
  
  // Print the current light level to the Serial Monitor for calibration
  Serial.print("Light Level: ");
  Serial.println(sensorValue);

  // Check if it is dark outside/in the room
  if (sensorValue < threshold) {
    digitalWrite(ledPin, HIGH);  // Turn the nightlight ON
  } else {
    digitalWrite(ledPin, LOW);   // Turn the nightlight OFF
  }

  delay(500); // Wait half a second before the next reading
}