#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Keypad.h>
const uint8_t ROWS = 4;
const uint8_t COLS = 4;
char keys[ROWS][COLS] =
    {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};
uint8_t colPins[COLS] = {5, 4, 3, 2};
uint8_t rowPins[ROWS] = {9, 8, 7, 6};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup()
{
  lcd.init();
  lcd.clear();
  // lcd.backlight(); // Make sure backlight is on
  Serial.begin(9600);
  lcd.setCursor(2, 0);
  lcd.print("KEY PRESSED");
  lcd.setCursor(2, 1);
  lcd.print("NULL");
}

void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("KEY PRESSED");
    Serial.println(key);
    lcd.setCursor(2, 1);
    lcd.print(key);
  }
}