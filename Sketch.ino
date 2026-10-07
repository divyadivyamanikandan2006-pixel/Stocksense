#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

// ---------- LCD ----------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------- HX711 ----------
HX711 scale;

#define HX_DT 18
#define HX_SCK 19

// ---------- Ultrasonic ----------
#define TRIG_PIN 5
#define ECHO_PIN 17

// ---------- Alert ----------
#define LED_PIN 2
#define BUZZER_PIN 4

// ---------- Stock Limits ----------
#define LOW_LIMIT 5.0
#define HIGH_LIMIT 5.1

void setup() {

  Serial.begin(115200);

  // LCD
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  // HX711
  scale.begin(HX_DT, HX_SCK);

  // Wokwi 50 kg Load Cell
  scale.set_scale(420.0);
  scale.tare();

  // Ultrasonic
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // LED and Buzzer
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // Starting Screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SMART INVENTORY");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM STARTING");

  delay(2000);
  lcd.clear();
}

void loop() {

  // ---------- Read Weight ----------
  float weight = scale.get_units(5);

  if (weight < 0) {
    weight = 0;
  }

  // ---------- Read Distance ----------
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  float distance = duration / 58.0;

  // ---------- LCD Display ----------
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Weight:");
  lcd.print(weight, 1);
  lcd.print("kg");

  // ---------- Stock Classification ----------

  if (weight < LOW_LIMIT) {

    // LOW STOCK
    lcd.setCursor(0, 1);
    lcd.print("LOW STOCK!");

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("STATUS: LOW STOCK");

  }

  else if (weight <= HIGH_LIMIT) {

    // NORMAL STOCK
    lcd.setCursor(0, 1);
    lcd.print("NORMAL STOCK");

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("STATUS: NORMAL STOCK");

  }

  else {

    // HIGH STOCK
    lcd.setCursor(0, 1);
    lcd.print("HIGH STOCK");

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("STATUS: HIGH STOCK");
  }

  // ---------- Serial Monitor ----------

  Serial.print("Weight: ");
  Serial.print(weight, 2);

  Serial.print(" kg | Distance: ");
  Serial.print(distance, 1);

  Serial.println(" cm");

  delay(1000);
}
