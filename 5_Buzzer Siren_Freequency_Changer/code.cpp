// 5_Buzzer_Siren_Frequency_Changer
// ---------- Pin and tuning constants ----------
const int BUZZER_PIN = 9;          // Buzzer connected to digital pin 9
const int POT_PIN = A0;            // Potentiometer wiper connected to analog pin A0
const int FREQ_MIN_HZ = 200;       // Lowest pitch (knob fully one way)
const int FREQ_MAX_HZ = 2000;      // Highest pitch (knob fully the other way)
const int UPDATE_INTERVAL_MS = 50; // Update the tone every 50 ms (20 times per second)

// Holds the smoothed pot reading (0-1023). Persists across the whole program.
static uint16_t filteredAdc = 0;

void setup() {
  // Pin 9 sends a signal out to the buzzer, so it must be an output
  pinMode(BUZZER_PIN, OUTPUT);

  // Seed the filter with the real knob position so the pitch doesn't
  // glide up from 0 at startup
  filteredAdc = analogRead(POT_PIN);

  // Convert the 0-1023 reading into a 200-2000 Hz frequency
  uint16_t startFreq = map(filteredAdc, 0, 1023, FREQ_MIN_HZ, FREQ_MAX_HZ);

  // Start the buzzer at that frequency (keeps playing until changed)
  tone(BUZZER_PIN, startFreq);
}

void loop() {
  // Remembers the time of the last update; keeps its value between loop() calls
  static uint32_t lastUpdateMs = 0;

  // Non-blocking timer: if less than 50 ms has passed, exit loop() right away
  // (no delay(), so the Arduino is never frozen)
  if (millis() - lastUpdateMs < UPDATE_INTERVAL_MS) {
    return;
  }
  lastUpdateMs = millis(); // 50 ms passed, so record the time of this update

  // Take a fresh raw reading from the potentiometer (0-1023)
  uint16_t currentAdc = analogRead(POT_PIN);

  // Low-pass filter: new value = 75% old + 25% new, which smooths out noise
  filteredAdc = (filteredAdc * 3 + currentAdc) / 4;

  // Convert the smoothed reading to a frequency between 200 and 2000 Hz
  uint16_t freq = map(filteredAdc, 0, 1023, FREQ_MIN_HZ, FREQ_MAX_HZ);

  // Update the buzzer pitch (calling tone() again just changes the frequency)
  tone(BUZZER_PIN, freq);
}