#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LDR_PIN 34
#define LED_PIN 26
#define BUZZER_PIN 27

LiquidCrystal_I2C lcd(0x27,16,2);

int threshold = 1800;

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Smart Light");
  lcd.setCursor(0,1);
  lcd.print("Monitoring");

  delay(2000);
  lcd.clear();
}

void loop()
{
  int ldrValue = analogRead(LDR_PIN);

  Serial.print("LDR Value : ");
  Serial.println(ldrValue);

  lcd.clear();

  if(ldrValue > threshold)
  {
      digitalWrite(LED_PIN,HIGH);
      digitalWrite(BUZZER_PIN,HIGH);

      lcd.setCursor(0,0);
      lcd.print("ROOM DARK");

      lcd.setCursor(0,1);
      lcd.print("LED ON");

      Serial.println("Dark Detected");
  }
  else
  {
      digitalWrite(LED_PIN,LOW);
      digitalWrite(BUZZER_PIN,LOW);

      lcd.setCursor(0,0);
      lcd.print("ROOM BRIGHT");

      lcd.setCursor(0,1);
      lcd.print("LED OFF");

      Serial.println("Bright");
  }

  delay(500);
}