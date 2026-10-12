//2_Basic_Traffic_Light_Mechanism - each light gives ten seconds of time to the vehicle to pass thorugh the traffic light. 

void setup(){

  //LED AT 8D - RED
  pinMode( 8, OUTPUT);
  
  //LED AT 13D - YELLOW
  pinMode( 13, OUTPUT);
  
  //LED AT 12D - Green
  pinMode( 12, OUTPUT);
}

// Loop Blinking Function
void loop(){
  digitalWrite( 8, HIGH); // Turns RED i.e. Stop
  delay(10000);
  
  digitalWrite( 8, LOW);  // Turns OFF RED
  delay(10);
  
  digitalWrite( 13, HIGH); // Turns YELLOW i.e. Ready
  delay(10000);
  
  digitalWrite( 13, LOW);  // Turns OFF YELLOW
  delay(10);
  
  digitalWrite( 12, HIGH);// Turns GREEN i.e. Go
  delay(10000);
  
  digitalWrite( 12, LOW);  // Turns OFF GREEN
  delay(10);
 
}
  