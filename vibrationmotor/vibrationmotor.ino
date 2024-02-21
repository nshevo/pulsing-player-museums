/** ESP32 & Arduino UNO **/
/** red wire to pwm, blue to ground **/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

// motor pwm pins
int motor_1 = 5;
int motor_2 = 6;

// motor power scaling factor
double mpsf = 0.5; // * mpsf

void setupPlayer()
{
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial))
  { // Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true)
    {
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
}

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  // setup vibration motors
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);

  setupPlayer();
}

void buzzing()
{
  for (int i = 0; i < 3; i++)
  {
    analogWrite(motor_1, 255 * mpsf);
    analogWrite(motor_2, 255 * mpsf);
    delay(400);
    analogWrite(motor_1, 0);
    analogWrite(motor_2, 0);
    delay(300);
  }
}

void vibration_pattern()
{

  // m1: long pulse rise
  for (int power = 0; power < 255; power++)
  {
    analogWrite(motor_1, power * mpsf);
    Serial.println((String) "1. Power of " + power * mpsf);
    power = power + 50;
    delay(500);
  }
  analogWrite(motor_1, 255 * mpsf);

  delay(1500);

  // m1: long pulse fall
  for (int power = 250; power > 50; power--)
  {
    analogWrite(motor_1, power * mpsf);
    Serial.println((String) "1. Power of " + power * mpsf);
    power = power - 25;
    delay(500);
  }
  analogWrite(motor_1, 0);

  // m2: long pulse rise
  for (int power = 0; power < 255; power++)
  {
    analogWrite(motor_2, power * mpsf);
    Serial.println((String) "2. Power of " + power * mpsf);
    power = power + 50;
    delay(500);
  }
  analogWrite(motor_2, 255 * mpsf);

  delay(1500);

  // m2: long pulse fall
  for (int power = 250; power > 50; power--)
  {
    analogWrite(motor_2, power * mpsf);
    Serial.println((String) "2. Power of " + power * mpsf);
    power = power - 25;
    delay(500);
  }
  analogWrite(motor_2, 0);

  // m1: short pulse rise
  for (int power = 0; power < 255; power++)
  {
    analogWrite(motor_1, power * mpsf);
    Serial.println((String) "1. Power of " + power * mpsf);
    power = power + 75;
    delay(250);
  }
  analogWrite(motor_1, 255 * mpsf);

  delay(150);

  // m1: short pulse fall
  for (int power = 250; power > 50; power--)
  {
    analogWrite(motor_1, power * mpsf);
    Serial.println((String) "1. Power of " + power * mpsf);
    power = power - 75;
    delay(250);
  }
  analogWrite(motor_1, 0);

  // m2: long pulse rise
  for (int power = 0; power < 255; power++)
  {
    analogWrite(motor_2, power * mpsf);
    Serial.println((String) "2. Power of " + power * mpsf);
    power = power + 75;
    delay(250);
  }
  analogWrite(motor_2, 255 * mpsf);

  delay(500);

  // m2: long pulse fall
  for (int power = 250; power > 50; power--)
  {
    analogWrite(motor_2, power * mpsf);
    Serial.println((String) "2. Power of " + power * mpsf);
    power = power - 75;
    delay(250);
  }
  analogWrite(motor_2, 0);

  delay(2000);

  // start buzzing
  buzzing();
}

void vibration_pattern_two()
{

  // m2: long pulse rise
  for (int power = 0; power < 255; power++)
  {
    analogWrite(motor_2, power * mpsf);
    Serial.println((String) "2. Power of " + power * mpsf);
    power = power + 75;
    delay(250);
  }
  analogWrite(motor_2, 255 * mpsf);

  delay(500);

  // m2: long pulse fall
  for (int power = 250; power > 50; power--)
  {
    analogWrite(motor_2, power * mpsf);
    Serial.println((String) "2. Power of " + power * mpsf);
    power = power - 75;
    delay(250);
  }

  analogWrite(motor_2, 0);

  // m1: short pulse rise
  for (int power = 0; power < 255; power++)
  {
    analogWrite(motor_1, power * mpsf);
    Serial.println((String) "1. Power of " + power * mpsf);
    power = power + 75;
    delay(250);
  }
  analogWrite(motor_1, 255 * mpsf);

  delay(150);

  // m1: short pulse fall
  for (int power = 250; power > 50; power--)
  {
    analogWrite(motor_1, power * mpsf);
    Serial.println((String) "1. Power of " + power * mpsf);
    power = power - 75;
    delay(250);
  }
  analogWrite(motor_1, 0);

  // m2: long pulse rise
  for (int power = 0; power < 255; power++)
  {
    analogWrite(motor_2, power * mpsf);
    Serial.println((String) "2. Power of " + power * mpsf);
    power = power + 50;
    delay(500);
  }
  analogWrite(motor_2, 255 * mpsf);

  delay(1500);

  // m2: long pulse fall
  for (int power = 250; power > 50; power--)
  {
    analogWrite(motor_2, power * mpsf);
    Serial.println((String) "2. Power of " + power * mpsf);
    power = power - 25;
    delay(500);
  }
  analogWrite(motor_2, 0);

  // m1: long pulse rise
  for (int power = 0; power < 255; power++)
  {
    analogWrite(motor_1, power * mpsf);
    Serial.println((String) "1. Power of " + power * mpsf);
    power = power + 50;
    delay(500);
  }
  analogWrite(motor_1, 255 * mpsf);

  delay(1500);

  // m1: long pulse fall
  for (int power = 250; power > 50; power--)
  {
    analogWrite(motor_1, power * mpsf);
    Serial.println((String) "1. Power of " + power * mpsf);
    power = power - 25;
    delay(500);
  }
  analogWrite(motor_1, 0);

  delay(2000);

  // start buzzing
  buzzing();
}

void play()
{
  myDFPlayer.volume(15); // Set volume value. From 0 to 30
  myDFPlayer.play(1);    // Play the first mp3
}

void loop()
{
  // runs repeatedly:
  vibration_pattern();
  delay(3000);
  play();
  delay(100000);
  vibration_pattern_two();
  delay(3000);
  myDFPlayer.play(2);
  delay(190000);
  vibration_pattern();
  delay(3000);
  myDFPlayer.play(3);
  delay(285000); 
  
}
