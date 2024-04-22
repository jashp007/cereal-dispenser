//UPDATED MASTER
#include <LiquidCrystal.h>

// Initialize the LCD library with the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonHalf = 6;  // Button for "half" is connected to pin 6
const int buttonFull = 7;  // Button for "full" is connected to pin 7

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Select Quantity:");

  // Initialize the button pins as inputs
  pinMode(buttonHalf, INPUT_PULLUP);
  pinMode(buttonFull, INPUT_PULLUP);

  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 1);  // Move the cursor to the second line

  if (digitalRead(buttonHalf) == LOW) {  // Check if the "half" button is pressed
    while (digitalRead(buttonHalf) == LOW);  // Debounce
    Serial.write('H');  // Send 'H' to indicate "Half Bowl"
    lcd.print("Half Bowl      ");
    delay(1000);  // Give time for reading
    lcd.clear();
    lcd.print("Select Quantity:");
  }

  if (digitalRead(buttonFull) == LOW) {  // Check if the "full" button is pressed
    while (digitalRead(buttonFull) == LOW);  // Debounce
    Serial.write('F');  // Send 'F' to indicate "Full Bowl"
    lcd.print("Full Bowl      ");
    delay(1000);  // Give time for reading
    lcd.clear();
    lcd.print("Select Quantity:");
  }
}