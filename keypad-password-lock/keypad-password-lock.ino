#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

unsigned long digits = 0;

char entered[6];
char password[] = "5*5C#";

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {A0, A1, A2, A3};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Password:");

  lcd.setCursor(0, 1);
}

void loop() {

  char key = keypad.getKey();

  if (key) {

    lcd.setCursor(digits, 1);
    lcd.print(key);

    entered[digits] = key;
    digits++;

    if (digits == 5) {

      entered[5] = '\0';

      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);

      if (strcmp(entered, password) == 0) {
        lcd.print("Correct!");
      }
      else {
        lcd.print("Wrong!");
      }

      delay(1500);

      lcd.setCursor(0, 1);
      lcd.print("                ");

      digits = 0;
    }
  }
}
