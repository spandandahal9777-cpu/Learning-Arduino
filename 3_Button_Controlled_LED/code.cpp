// 3_Button_Controlled_LED

//define the pin numbers for the button and LED
const int buttonPin = 8;
const int ledPin = 13;

void setup() {
    // Set up button with internal pull-up resistor
    pinMode(buttonPin, INPUT_PULLUP);
    
    // Set up LED pin as output
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

void loop() {
    // Read the current state of the button
    int buttonState = digitalRead(buttonPin);

    // Since INPUT_PULLUP is used, LOW means the button is pressed
    if (buttonState == LOW) {
        digitalWrite(ledPin, HIGH); // Turn LED ON when pressed
    } else {
        digitalWrite(ledPin, LOW);  // Turn LED OFF when released
    }
}