// Define Pins
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RST_PIN   9     // Configurable, see typical pin layout above
#define SS_PIN    10    // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance
LiquidCrystal_I2C lcd(0x27, 16, 2);
/* Set your new UID here! */
#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}

MFRC522::MIFARE_Key key;
Servo myservo;
int pos = 0;

void setup()
{
 Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);     // Do nothing if no serial port is opened
  SPI.begin();         // Init SPI bus
  mfrc522.PCD_Init();  // Init MFRC522 card
  myservo.attach(8);
  lcd.init();         // initialize the lcd
  lcd.backlight();    // Turn on the LCD screen backlight
}

void loop() {
  // Look for new cards, and select one if present
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  lcd.setCursor(1, 0);
  lcd.print("Scanning");
  delay(1500);
  lcd.clear();
  // Dump UID for debugging
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();

  // Check if this is your specific card
  if (mfrc522.uid.uidByte[0] == 0x6A && 
      mfrc522.uid.uidByte[1] == 0x95 && 
      mfrc522.uid.uidByte[2] == 0x56 && 
      mfrc522.uid.uidByte[3] == 0x12) {
    
    lcd.setCursor(1, 0);
    lcd.print("Opening Gate");
    delay(2000);
    lcd.clear();
    
    // Try to read the card serial number
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    delay(1000);
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    
  } else {
    lcd.setCursor(1, 0);
    lcd.print("Uknown Card/tag detected");
    lcd.setCursor(2, 1);
    lcd.print("Input invalid");
    delay(1500);
    lcd.clear();
  }
  
  // Halt PICC
  mfrc522.PICC_HaltA();
  delay(2000);
}
