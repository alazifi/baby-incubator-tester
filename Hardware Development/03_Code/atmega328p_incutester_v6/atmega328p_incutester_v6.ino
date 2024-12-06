#include <SparkFunHTU21D.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
// #include "MultiMap.h"
#include "ADS1X15.h"

ADS1115 ADS(0x48);

String endChar = "\xFF\xFF\xFF";

int batPin = A0;
int airSpeedPin = A1;
int soundPin = A2;

int chgPin = 7;
int count = -4;

int batVal = 409;

const int CS = 10;

const int sampleWindow = 50;
unsigned int sample;

unsigned long prevTimeNextion = 0;
unsigned long prevTimeSD = 0;
unsigned long nowTimeNextion = 0;
unsigned long nowTimeSD = 0;
unsigned long logTime = 0;
unsigned long delayUpNextion = 1000;
unsigned long delayUpSD = 1000;

HTU21D htu1 = HTU21D();
HTU21D htu2 = HTU21D();
HTU21D htu3 = HTU21D();
HTU21D htu4 = HTU21D();
HTU21D htu5 = HTU21D();
HTU21D htu6 = HTU21D();

void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(0x70);
  if (bus > 7) return;
  Wire.write(1 << bus);
  Wire.endTransmission();
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  htu1.begin();
  htu2.begin();
  htu3.begin();
  htu4.begin();
  htu5.begin();
  htu6.begin();
  pinMode(chgPin, INPUT);
  digitalWrite(chgPin, LOW);
  if (!SD.begin(CS)) {
    // Serial.println("Gagal Baca SD Card!");
    return;
  }
     ADS.setGain(1);
 ADS.setMode(1);
   ADS.setDataRate(4); 
     ADS.begin();
}

void loop() {
  // if (millis() - prevTimeNextion >= delayUpNextion) {
  //   printNextion();
  //   // upBatLev(analogRead(batPin));
  //   // Serial.println(dataCore());
  //   prevTimeNextion = millis();
  // }
  // if (millis() - prevTimeSD >= delayUpSD) {
  //   writeDataToSD(dataCore());
  //   // Serial.println(dataCore());
  //   prevTimeSD = millis();
  // }


  logTime = millis();
  nowTimeNextion = millis();
  nowTimeSD = millis();

  if (logTime >= 8000) {
    if (millis() - prevTimeNextion >= delayUpNextion) {
      printNextion();
      prevTimeNextion = millis();
    }
  }
  // } else {
  if (millis() - prevTimeSD >= delayUpSD) {
    writeDataToSD(dataCore());
    prevTimeSD = millis();
  }
  // }
}

float sTemp1() {
  TCA9548A(2); //4
  return (htu1.readTemperature() > 45) ? 45.0 : htu1.readTemperature();
}

float sTemp2() {
  TCA9548A(3); //3
  return (htu2.readTemperature() > 45) ? 45.0 : htu2.readTemperature();
}

float sTemp3() {
  TCA9548A(4);  //2
  return (htu3.readTemperature() > 45) ? 45.0 : htu3.readTemperature();
}

float sTemp4() {
  TCA9548A(5);  //6
  return (htu4.readTemperature() > 45) ? 45.0 : htu4.readTemperature();
}

float sTemp5() {
  TCA9548A(6);  //7
  return (htu5.readTemperature() > 45) ? 45.0 : htu5.readTemperature();
}

float sHumi5() {
  TCA9548A(6);  //7
  return (htu5.readHumidity() > 100) ? 100 : htu5.readHumidity();
}

float sTemp6() {
  TCA9548A(7);  //5
  return (htu6.readTemperature() > 45) ? 45.0 : htu6.readTemperature();
}

float mTemp1() {
  float maxTemp1 = 19;
  return max(sTemp1(), maxTemp1);
}

float mTemp2() {
  float maxTemp2 = 19;
  return max(sTemp2(), maxTemp2);
}

float mTemp3() {
  float maxTemp3 = 19;
  return max(sTemp3(), maxTemp3);
}

float mTemp4() {
  float maxTemp4 = 19;
  return max(sTemp4(), maxTemp4);
}

float mTemp5() {
  float maxTemp5 = 19;
  return max(sTemp5(), maxTemp5);
}

float mTemp6() {
  float maxTemp6 = 19;
  return max(sTemp6(), maxTemp6);
}

byte batLevel() { //590 to 700
  int batMap = map(analogRead(batPin), 446, 760, 0, 100);  //nilai 720, 760 | 450 to 720
  batVal = min(batMap, batVal);
  if (batVal < 0) {
    return 0;
  } else if (batVal > 100 || chgState()) {
    return 100;
  } else {
    return batVal;
  }
}

int soundLevel() {
  // int peakToPeak = 0;
  // unsigned int startMillis = millis();
  // unsigned int signalMax = 0;
  // unsigned int signalMin = 1023;
  // while (millis() - startMillis < sampleWindow) {
  //   sample = analogRead(soundPin);
  //   if (sample < 1024) {
  //     if (sample > signalMax) {
  //       signalMax = sample;
  //     } else if (sample < signalMin) {
  //       signalMin = sample;
  //     }
  //   }
  // }

  // int avg = signalMax - signalMin;
  // int out[] = { 45, 50, 54, 65, 77, 82, 84, 87, 90, 93 };
  // int in[] = { 45, 77, 99, 135, 190, 293, 409, 569, 615, 1012 };
  return ADS.readADC(0);//multiMap<int>(avg, in, out, 10);
}

bool chgState() {
  return (digitalRead(chgPin) == HIGH) ? true : false;
}

float airSpeed() {
  return ADS.readADC(1);
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

void upMaxTemp1(float temp1) {
  static char vMaxTemp1[6];
  dtostrf(temp1, 2, 1, vMaxTemp1);
  Serial.print("mTemp1.txt=\"" + String(vMaxTemp1) + "\"" + endChar);
}

void upMaxTemp2(float temp2) {
  static char vMaxTemp2[6];
  dtostrf(temp2, 2, 1, vMaxTemp2);
  Serial.print("mTemp2.txt=\"" + String(vMaxTemp2) + "\"" + endChar);
}

void upMaxTemp3(float temp3) {
  static char vMaxTemp3[6];
  dtostrf(temp3, 2, 1, vMaxTemp3);
  Serial.print("mTemp3.txt=\"" + String(vMaxTemp3) + "\"" + endChar);
}

void upMaxTemp4(float temp4) {
  static char vMaxTemp4[6];
  dtostrf(temp4, 2, 1, vMaxTemp4);
  Serial.print("mTemp4.txt=\"" + String(vMaxTemp4) + "\"" + endChar);
}

void upMaxTemp5(float temp5) {
  static char vMaxTemp5[6];
  dtostrf(temp5, 2, 1, vMaxTemp5);
  Serial.print("mTemp5.txt=\"" + String(vMaxTemp5) + "\"" + endChar);
}

void upMaxTemp6(float temp6) {
  static char vMaxTemp6[6];
  dtostrf(temp6, 2, 1, vMaxTemp6);
  Serial.print("mTemp6.txt=\"" + String(vMaxTemp6) + "\"" + endChar);
}

char* decToChar(float dec) {
  static char vDev[6];
  dtostrf(dec, 2, 2, vDev);
  return vDev;
}

char* intToChar(int num) {
  static char vNum[4];
  itoa(num, vNum, 10);
  return vNum;
}

char* strToChar(String str) {
  static char vStr[30];
  str.toCharArray(vStr, 70);
  return vStr;
}

void upAirSpeed(int airSpeed) {
  static char vAirSpeed[6];
  dtostrf(airSpeed, 2, 1, vAirSpeed);
  Serial.print("airSpeed.txt=\"" + String(vAirSpeed) + "\"" + endChar);
}

void upSoundLevel(int sound) {
  static char vSound[3];
  itoa(sound, vSound, 10);
  Serial.print("soundLev.txt=\"" + String(vSound) + "\"" + endChar);
}

void upBatLev(int batLev) {
  static char vBatLev[3];
  itoa(batLev, vBatLev, 10);
  Serial.print("batLev.txt=\"" + String(vBatLev) + "\"" + endChar);
}

void upChgState(int chgSt) {
  static char vChgSt[3];
  itoa(chgSt, vChgSt, 10);
  Serial.print("chgFlag.txt=\"" + String(vChgSt) + "\"" + endChar);
}

void printNextion() {
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

char* nextionTimestamp() {
  static char nextTs[20];
  if (Serial.available()) {
    String vNextTs = Serial.readStringUntil('s');
    vNextTs.toCharArray(nextTs, sizeof(nextTs));
  }
  return nextTs;  //Format timestamp: "20/05/2024 13:09:45";
}

char* dataHeader() {
  return "\nHasil Ukur Baby Incubator Tester";
}

char* timeStamp() {
  static char ts[20];
  strcpy(ts, "Timestamp: ");
  strcat(ts, nextionTimestamp());
  return ts;
}

char* dataLable() {
  return "\nNo,T1,T2,T3,T4,T5,T6,Humidity,AirSpeed,SoundLevel";
}

char* dataCore() {
  count += 1;
  static char data[70];
  strcpy(data, intToChar(count));
  strcat(data, ",");
  strcat(data, decToChar(sTemp1()));
  strcat(data, ",");
  strcat(data, decToChar(sTemp2()));
  strcat(data, ",");
  strcat(data, decToChar(sTemp3()));
  strcat(data, ",");
  strcat(data, decToChar(sTemp4()));
  strcat(data, ",");
  strcat(data, decToChar(sTemp5()));
  strcat(data, ",");
  strcat(data, decToChar(sTemp6()));
  strcat(data, ",");
  strcat(data, decToChar(sHumi5()));
  strcat(data, ",");
  strcat(data, decToChar(airSpeed()));
  strcat(data, ",");
  strcat(data, intToChar(soundLevel()));
  if (count == -3) {
    return dataHeader();
  } else if (count == -2) {
    return nextionTimestamp();
  } else if (count == -1) {
    return nextionTimestamp();
  } else if (count == 0) {
    return dataLable();
  } else {
    return data;
  }
}

void writeDataToSD(char* data) {
  File dataFile = SD.open("hasil.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(data);
    dataFile.close();
    // Serial.println(data);
  } else {
    // Serial.println("Gagal baca");
  }
}