#include <Keypad.h>

// Define the keypad matrix
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define the correct password
char password[] = "1234";
int passwordLength = 4;

// Variables
char enteredPassword[5];
int enteredLength = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    // Check if the entered key is a number or '#' (submit)
    if (isdigit(key) || key == '#') {
      // Clear the entered password if '#' is pressed
      if (key == '#') {
        enteredLength = 0;
        memset(enteredPassword, 0, sizeof(enteredPassword));
      }
      else {
        // Append the entered key to the password
        enteredPassword[enteredLength++] = key;
        Serial.print("Entered: ");
        Serial.println(key);
      }

      // Check if the entered password matches the correct password
      if (enteredLength == passwordLength) {
        if (strcmp(enteredPassword, password) == 0) {
          Serial.println("Password correct!");
          // Perform actions for correct password
        }
        else {
          Serial.println("Password incorrect!");
          // Perform actions for incorrect password
          for(int i=0;i<=4;i++){
          }
        }

        // Reset the entered password
        enteredLength = 0;
        memset(enteredPassword, 0, sizeof(enteredPassword));
      }
    }
  }
}
