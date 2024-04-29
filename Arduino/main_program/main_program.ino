#include "Kinematrix.h"
#include "sensors/ultrasonic-sens.h"
#include "sensors/hx711-sens.h"
#include "modules/time/timer-task.h"
#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

NewPing tinggiBadanSens(6, 7, 200);
HX711Sens beratBadanSens(9, 8);
LiquidCrystal_I2C lcd(0x27, 16, 2);
TimerTask lcdTim(2000);
TimerTask raspiTim(1000);

int animLCD = 0;
float tinggi, berat, imt;
void setup() {
  Serial.begin(9600);

  Serial.println("INIT...");
  beratBadanSens.init();

  beratBadanSens.setScale(23.16);
  beratBadanSens.tareDelay(100);
  lcd.init();
  lcd.backlight();

  Serial.println(beratBadanSens.isReady());
}

void loop() {
  tinggi = getTinggiBadan();
  berat = getBeratBadan();
  imt = berat / (tinggi * tinggi);


  if (lcdTim.triggered()) displayLCD();
  if (raspiTim.triggered()) sendKeRaspi();

  beratBadanSens.update();
}


float getBeratBadan() {
  return beratBadanSens.getValueWeight() / 1000;
}


float getTinggiBadan() {
  float tinggi = tinggiBadanSens.ping_cm();
  delay(80);
  return (200 - tinggi) + 3;
}

void displayLCD() {
  if (animLCD < 1) {
    lcd.setCursor(0, 0);
    lcd.print("Tinggi: " + String(tinggi));
    lcd.setCursor(13, 0);
    lcd.print("CM");
    lcd.setCursor(0, 1);
    lcd.print("Berat: " + String(tinggi));
    lcd.setCursor(13, 1);
    lcd.print("KG");
    animLCD += 1;
  } else {
    lcd.setCursor(0, 0);
    lcd.print("IMT: " + String(imt));
    animLCD = 0;
  }
}

void sendKeRaspi() {
  Serial.print(tinggi);
  Serial.print("|");
  Serial.println(getBeratBadan());
}
