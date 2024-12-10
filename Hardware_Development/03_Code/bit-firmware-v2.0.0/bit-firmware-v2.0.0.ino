#include <SparkFunHTU21D.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include "MultiMap.h"

String endChar = "\xFF\xFF\xFF";

int batPin = A0;
int soundPin = A2;
int airSpeedPin = A1;

int chgPin = 7;
int count = 0;

const int CS = 4;

int sampleWindow = 50;
int sample;

File dataFile;

HTU21D htu1 = HTU21D();
HTU21D htu2 = HTU21D();
HTU21D htu3 = HTU21D();
HTU21D htu4 = HTU21D();
HTU21D htu5 = HTU21D();
HTU21D htu6 = HTU21D();

unsigned int prevMillis = 0;

void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(0x70);  // TCA9548A address
  if (bus > 7) return;
  Wire.write(1 << bus);  // select bus
  Wire.endTransmission();
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  // TCA9548A(1);
  htu1.begin();
  // TCA9548A(2);
  htu2.begin();
  // TCA9548A(3);
  htu3.begin();
  // TCA9548A(4);
  htu4.begin();
  // TCA9548A(5);
  htu5.begin();
  // TCA9548A(6);
  htu6.begin();

  if(!SD.begin(CS)){
    Serial.println("Gagal Baca SD Card!");
    return;
  }
}

void loop() {
  Serial.begin(9600);
  updateTemp1(sTemp1());
  updateTemp2(sTemp2());
  updateTemp3(sTemp3());
  updateTemp4(sTemp4());
  updateTemp5(sTemp5());
  updateTemp6(sTemp6());
  updateHumi5(sHumi5());
  updateAirSpeed(airSpeed());
  updateSoundLevel(soundLevel());
  writeDataToSD(dataCore());
  delay(1000);
}

float sTemp1() {
  TCA9548A(0);
  return htu1.readTemperature();
}

float sTemp2() {
  TCA9548A(1);
  return htu2.readTemperature();
}

float sTemp3() {
  TCA9548A(2);
  return htu3.readTemperature();
}

float sTemp4() {
  TCA9548A(3);
  return htu4.readTemperature();
}

float sTemp5() {
  TCA9548A(4);
  return htu5.readTemperature();
}

float sHumi5() {
  TCA9548A(4);
  return htu5.readHumidity();
}

float sTemp6() {
  TCA9548A(5);
  return htu6.readTemperature();
}

int batLevel() {
  int batVal = map(analogRead(batPin), 450, 715, 50, 100);
  int batLevel = min(batVal, batLevel);
  return (batLevel > 100 || chgState()) ? 100 : batLevel;
}

int soundLevel() {
  int peakToPeak = 0;
  unsigned int startMillis = millis(); 
  unsigned int signalMax = 0;
  unsigned int signalMin = 1023;
  while (millis() - startMillis < sampleWindow) {
    sample = analogRead(soundPin);
    if (sample < 1024) {
      if (sample > signalMax) {
        signalMax = sample;
      } else if (sample < signalMin) {
        signalMin = sample;
      }
    }
  }

  int avg = signalMax - signalMin;
  int out[] = { 45, 50, 54, 65, 77, 82, 84, 87, 90, 93 };
  int in[] = { 45, 77, 99, 135, 190, 293, 409, 569, 615, 1012 };
  return multiMap<int>(avg, in, out, 10);
}

int chgFlag(){
  return (chgState()) ? 10 : 30;
}

bool chgState(){
  return (digitalRead(chgPin) == HIGH) ? true : false;
}

int airSpeed(){
  return 0;
}

void updateTemp1(float temp1) {
  static char vTemp1[6];
  dtostrf(temp1, 2, 1, vTemp1);
  Serial.print("temp1.txt=\"" + String(vTemp1) + "\"" + endChar);
}

void updateTemp2(float temp2) {
  static char vTemp2[6];
  dtostrf(temp2, 2, 1, vTemp2);
  Serial.print("temp2.txt=\"" + String(vTemp2) + "\"" + endChar);
}

void updateTemp3(float temp3) {
  static char vTemp3[6];
  dtostrf(temp3, 2, 1, vTemp3);
  Serial.print("temp3.txt=\"" + String(vTemp3) + "\"" + endChar);
}

void updateTemp4(float temp4) {
  static char vTemp4[6];
  dtostrf(temp4, 2, 1, vTemp4);
  Serial.print("temp4.txt=\"" + String(vTemp4) + "\"" + endChar);
}

void updateTemp5(float temp5) {
  static char vTemp5[6];
  dtostrf(temp5, 2, 1, vTemp5);
  Serial.print("temp5.txt=\"" + String(vTemp5) + "\"" + endChar);
}

void updateTemp6(float temp6) {
  static char vTemp6[6];
  dtostrf(temp6, 2, 1, vTemp6);
  Serial.print("temp6.txt=\"" + String(vTemp6) + "\"" + endChar);
}

void updateHumi5(float humi5) {
  static char vHumi5[6];
  dtostrf(humi5, 2, 1, vHumi5);
  Serial.print("humi5.txt=\"" + String(vHumi5) + "\"" + endChar);
}

void updateSoundLevel(int sound) {
  static char vSound[6];
  itoa(sound, vSound, 2);
  Serial.print("soundLev.txt=\"" + String(vSound) + "\"" + endChar);
}

void updateAirSpeed(int airSpeed){
  static char vAirSpeed[6];
  itoa(airSpeed, vAirSpeed, 2);
  Serial.print("airSpeed.txt=\"" + String(vAirSpeed) + "\"" + endChar);
}

String dataCore(){
  count++;
  return ""+String(count)+", "+String(sTemp1())+", "+String(sTemp2())+", "+String(sTemp3())+", "+String(sTemp4())+", "+String(sTemp5())+", "+String(sTemp6())+", "+String(sHumi5())+", "+String(airSpeed())+", "+String(soundLevel())+"";
}

String timestamp(){
  return;
}

void writeDataToSD(String data){
  dataFile = SD.open("result.txt", FILE_WRITE);
  if(dataFile){
    dataFile.print(data);
  }
}