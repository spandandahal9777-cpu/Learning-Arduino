// 8_16x2_I2C_LCD_Display

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C address = 0x27 
// 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on the backlight
  
  lcd.setCursor(0, 0); // Set cursor to column 0, row 0
  lcd.print("Hello World!"); // Print first line
  
  lcd.setCursor(0, 1); // Set cursor to column 0, row 1
  lcd.print("Arduino I2C");  // Print second line
}

void loop() {
  // Nothing to do here
}