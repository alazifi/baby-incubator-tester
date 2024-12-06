#include <SparkFunHTU21D.h>
#include <Wire.h>
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

unsigned long prevTime = 0;
unsigned long delayUpNextion = 500;

HTU21D htu1 = HTU21D();
HTU21D htu2 = HTU21D();
HTU21D htu3 = HTU21D();
HTU21D htu4 = HTU21D();
HTU21D htu5 = HTU21D();
HTU21D htu6 = HTU21D();

void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(0x70);  // TCA9548A address
  if (bus > 7) return;
  Wire.write(1 << bus);  // select bus
  Wire.endTransmission();
}

void setup() {
  Serial.begin(115200);
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
}

void loop() {
  if(millis() - prevTime >= delayUpNextion){
  upTemp1(sTemp1());
  upTemp2(sTemp2());
  upTemp3(sTemp3());
  upTemp4(sTemp4());
  upTemp5(sTemp5());
  upTemp6(sTemp6());
  upHumi5(sHumi5());
  upAirSpeed(airSpeed());
  upSoundLevel(soundLevel());
  upMaxTemp1(mTemp1());
  upMaxTemp2(mTemp2());
  upMaxTemp3(mTemp3());
  upMaxTemp4(mTemp4());
  upMaxTemp5(mTemp5());
  upMaxTemp6(mTemp6());
  upBatLev(batLevel());
  upChgState(chgState());
  }
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

float mTemp1(){
  float maxTemp1 = 19;
  return max(sTemp1(), maxTemp1);
}

float mTemp2(){
  float maxTemp2 = 19;
  return max(sTemp2(), maxTemp2);
}

float mTemp3(){
  float maxTemp3 = 19;
  return max(sTemp3(), maxTemp3);
}

float mTemp4(){
  float maxTemp4 = 19;
  return max(sTemp4(), maxTemp4);
}

float mTemp5(){
  float maxTemp5 = 19;
  return max(sTemp5(), maxTemp5);
}

float mTemp6(){
  float maxTemp6 = 19;
  return max(sTemp6(), maxTemp6);
}

int batVal(){
  return map(analogRead(batPin), 370, 405, 50, 100);
}

int batLevel() {
  int batLevel = min(batVal(), batLevel);
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

void upTemp1(float temp1) {
  static char vTemp1[6];
  dtostrf(temp1, 2, 1, vTemp1);
  Serial.print("temp1.txt=\"" + String(vTemp1) + "\"" + endChar);
}

void upTemp2(float temp2) {
  static char vTemp2[6];
  dtostrf(temp2, 2, 1, vTemp2);
  Serial.print("temp2.txt=\"" + String(vTemp2) + "\"" + endChar);
}

void upTemp3(float temp3) {
  static char vTemp3[6];
  dtostrf(temp3, 2, 1, vTemp3);
  Serial.print("temp3.txt=\"" + String(vTemp3) + "\"" + endChar);
}

void upTemp4(float temp4) {
  static char vTemp4[6];
  dtostrf(temp4, 2, 1, vTemp4);
  Serial.print("temp4.txt=\"" + String(vTemp4) + "\"" + endChar);
}

void upTemp5(float temp5) {
  static char vTemp5[6];
  dtostrf(temp5, 2, 1, vTemp5);
  Serial.print("temp5.txt=\"" + String(vTemp5) + "\"" + endChar);
}

void upTemp6(float temp6) {
  static char vTemp6[6];
  dtostrf(temp6, 2, 1, vTemp6);
  Serial.print("temp6.txt=\"" + String(vTemp6) + "\"" + endChar);
}

void upHumi5(float humi5) {
  static char vHumi5[6];
  dtostrf(humi5, 2, 1, vHumi5);
  Serial.print("humi5.txt=\"" + String(vHumi5) + "\"" + endChar);
}

void upMaxTemp1(float temp1){
  static char vMaxTemp1[6];
  dtostrf(temp1, 2, 1, vMaxTemp1);
  Serial.print("mTemp1.txt=\"" + String(vMaxTemp1) + "\"" + endChar);
}

void upMaxTemp2(float temp2){
  static char vMaxTemp2[6];
  dtostrf(temp2, 2, 1, vMaxTemp2);
  Serial.print("mTemp2.txt=\"" + String(vMaxTemp2) + "\"" + endChar);
}

void upMaxTemp3(float temp3){
  static char vMaxTemp3[6];
  dtostrf(temp3, 2, 1, vMaxTemp3);
  Serial.print("mTemp3.txt=\"" + String(vMaxTemp3) + "\"" + endChar);
}

void upMaxTemp4(float temp4){
  static char vMaxTemp4[6];
  dtostrf(temp4, 2, 1, vMaxTemp4);
  Serial.print("mTemp4.txt=\"" + String(vMaxTemp4) + "\"" + endChar);
}

void upMaxTemp5(float temp5){
  static char vMaxTemp5[6];
  dtostrf(temp5, 2, 1, vMaxTemp5);
  Serial.print("mTemp5.txt=\"" + String(vMaxTemp5) + "\"" + endChar);
}

void upMaxTemp6(float temp6){
  static char vMaxTemp6[6];
  dtostrf(temp6, 2, 1, vMaxTemp6);
  Serial.print("mTemp6.txt=\"" + String(vMaxTemp6) + "\"" + endChar);
}

void upSoundLevel(int sound) {
  static char vSound[3];
  itoa(sound, vSound, 2);
  Serial.print("soundLev.txt=\"" + String(vSound) + "\"" + endChar);
}

void upAirSpeed(int airSpeed){
  static char vAirSpeed[3];
  itoa(airSpeed, vAirSpeed, 2);
  Serial.print("airSpeed.txt=\"" + String(vAirSpeed) + "\"" + endChar);
}

void upBatLev(int batLev){
  static char vBatLev[3];
  itoa(batLev, vBatLev, 2);
  Serial.print("batLev.txt=\"" + String(vBatLev) + "\"" + endChar);
}

void upChgState(int chgSt){
  static char vChgSt[3];
  itoa(chgSt, vChgSt, 2);
  Serial.print("chgSt.txt=\"" + String(vChgSt) + "\"" + endChar);
}