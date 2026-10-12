// 1_Blinking_LED

void setup(){
  //LED AT 13D
  pinMode( 13, OUTPUT);
}

// Loop Blinking Function
void loop(){
  digitalWrite( 13, HIGH); // Turns LED On
  delay(1000);  //delay for 1 sec = 1000 ms
  digitalWrite( 13, LOW);  // Turns LED off
  delay(1000);  
}
  