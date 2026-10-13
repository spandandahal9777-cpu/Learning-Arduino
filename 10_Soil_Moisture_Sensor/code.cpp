
// 10_Soil_Moisture_Sensor

const int SOIL_PIN = A0; // Connect sensor analog output to A0

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Serial.println("Soil Moisture Sensor Ready...");
}

void loop() {
  int sensorValue = analogRead(SOIL_PIN); // Read the analog value (0 to 1023)

  Serial.print("Moisture Value: ");
  Serial.println(sensorValue); // Higher/Lower depends on sensor type (see note below)

  delay(1000); // Wait 1 second between readings
}