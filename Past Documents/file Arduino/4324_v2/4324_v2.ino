// sudah bisa membaca dari nextion
//merubah beberapa lib
//D:\youtube_Project\JOBS\Lat_Ardu\31824_TS(SKRIP)\31824_gab_v5
//sudah baik membaca RTC nya, belum masuk milis
//menambahkan ser_13
//sudah jalan RTC nextion sudah bisa disimpan
//sudah oks
//sudah bisa disimpan

#include <String.h>
#include <SparkFunHTU21D.h>
#include <Wire.h>
#include "MultiMap.h"
#include <SPI.h>
#include <SD.h>
//#include <ctype.h> // Tambahkan untuk mendukung fungsi isAlphaNumeric

int sampleWindow = 50;
int sample;
File myFile;

HTU21D htu1 = HTU21D();
HTU21D htu2 = HTU21D();
HTU21D htu3 = HTU21D();
HTU21D htu4 = HTU21D();
HTU21D htu5 = HTU21D();
HTU21D htu6 = HTU21D();

int analogPin = A0;
int soundPin = A2;
int airspeedPin = A1;
int ChgPin = 7;
int ChgState = 0;
int BattValue = 409;
int airspeedValue = 0;
int dataCount = 1; // Variabel untuk menyimpan nomor data, dimulai dari 1

int chgFlag = 19;
int temp10;
int temp20;
int temp30;
int temp40;
int temp50;
int temp60;

int BattLevel = 100;
int SoundLevel;
int SpeedLevel;

// Maximum length of the concatenated string
const size_t maxStringLength = 6;

// Buffers for C-style strings
char buffer[maxStringLength];

int MaxTemp10;
int MaxTemp20;
int MaxTemp30;
int MaxTemp40;
int MaxTemp50;
int MaxTemp60;
char var[60];

unsigned int prevMillis = 0;
unsigned int prevMillis2 = 0;
int humid5;
char DataSensor[60]; //fixed size of array
void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(0x70);  // TCA9548A address
  if (bus > 7) return;
  Wire.write(1 << bus);  // select bus
  Wire.endTransmission();
}

//* CODE FOR WRITE to SD CARD *\\

void setup() {
  Serial.begin(9600);
  
  pinMode(ChgPin, INPUT);
  Wire.begin();
  TCA9548A(1);
  htu1.begin();

  TCA9548A(2);
  htu2.begin();

  TCA9548A(3);
  htu3.begin();

  TCA9548A(4);
  htu4.begin();
  TCA9548A(5);
  htu5.begin();

  TCA9548A(6);
  htu6.begin();

  pinMode(analogPin, INPUT);

  if (!SD.begin(10)) { //tergantung di pin chipselect yang digunakan
    Serial.println("Gagal baca microSD!");
    return;
  }
  Serial.println("Sukses baca kartu microSD!"); //berhasil
  Serial.println();
  //WriteDataToSD();
  
}
bool flag=false;

void loop()
{
  if (Serial.available() > 0) {
    tanggal_waktu(); // Panggil fungsi hanya jika ada data yang tersedia
  }
  
  unsigned int currentMillis = millis();
  if ((currentMillis - prevMillis >= 6000)&&(flag==false)) { 
    //ini adalah untuk mengirim fungsi ke tampilan nextion
    //ini tidak dibutuhkan pada penyimpanan data di SD card
    readSensor();
    sendChgStatusToNextion();
    sendBattLevelToNextion();
    sendSpeedLevelToNextion();
    sendSoundLevelToNextion();
    sendTemperature1ToNextion();
    sendTemperature2ToNextion();
    sendTemperature3ToNextion();
    sendTemperature4ToNextion();
    sendTemperature5ToNextion();
    sendHumid5ToNextion();
    sendTemperature6ToNextion();
    
    Serial.println(F("Flag: False"));
    flag=true;
    prevMillis = currentMillis;
    Serial.print(F("prevMillis: "));
    Serial.println(prevMillis);
    Serial.println();
  }
  if ((currentMillis - prevMillis >= 3000) && (flag==true)) {
    // Task 2: Run every 4000 milliseconds
   WriteDataToSD(DataSensor);   
    Serial.println(F("Flag: True"));
    flag=false;
    
    prevMillis = currentMillis;  
    //delay(200);
    Serial.print(F("prevMillis2: "));
    Serial.println(prevMillis);
    //Serial.println();
  }
}

void readSensor() {
  int temp1;
  int temp2;
  int temp3;
  int temp4;
  int temp5;
  int temp6;

  TCA9548A(0);
  temp1 = htu1.readTemperature();
  temp10 = temp1;
  TCA9548A(1);
  temp2 = htu2.readTemperature();
  temp20 = temp2;
  TCA9548A(2);
  temp3 = htu3.readTemperature();
  temp30 = temp3;
  TCA9548A(3);
  temp4 = htu4.readTemperature();
  temp40 = temp4;
  TCA9548A(4);
  temp5 = htu5.readTemperature();
  temp50 = temp5;
  humid5 = htu5.readHumidity();
  TCA9548A(5);
  temp6 = htu6.readTemperature();
  temp60 = temp6;

  MaxTemp10 = max(temp10, MaxTemp10);
  MaxTemp20 = max(temp20, MaxTemp20);
  MaxTemp30 = max(temp30, MaxTemp30);
  MaxTemp40 = max(temp40, MaxTemp40);
  MaxTemp50 = max(temp50, MaxTemp50);
  MaxTemp60 = max(temp60, MaxTemp60);
  //MaxTemp70 = max(temp70, MaxTemp70);
  
  int battcalc;
  battcalc = analogRead(analogPin);
  //Serial.println(battcalc);
  BattValue = map(battcalc, 450, 715, 50, 100);
  BattLevel = min(BattValue, BattLevel);
  //Serial.println(BattValue);
  //Serial.println(BattLevel);
  if (BattLevel > 100) (BattLevel = 100);

  unsigned int startMillis = millis();  // Start of sample window
  int peakToPeak = 0;                  // peak-to-peak level
  unsigned int signalMax = 0;            //minimum value
  unsigned int signalMin = 1024;         //maximum value
  while (millis() - startMillis < sampleWindow) {
    sample = analogRead(soundPin);  //get reading from microphone
    if (sample < 1024)              // toss out spurious readings
    {
      if (sample > signalMax) {
        signalMax = sample;  // save just the max levels
      } else if (sample < signalMin) {
        signalMin = sample;  // save just the min levels
      }
    }
  }
  int avg = signalMax - signalMin;
  int out[] = { 45, 50, 54, 65, 77, 82, 84, 87, 90, 93 };
  int in[] = { 45, 77, 99, 135, 190, 293, 409, 569, 615, 1012 };
  SoundLevel = multiMap<int>(avg, in, out, 10);

  SpeedLevel = 0;
  ChgState = digitalRead(ChgPin);
  Serial.print("ChgState:");
  Serial.println(ChgState);
  
  if (ChgState == HIGH) {
    BattLevel = 100;
    chgFlag = 10;
  } else {
    chgFlag = 30;
  }
  Serial.print("chgFlag:");  
  Serial.println(chgFlag);  
}

void appendStr(char var[10]) {
  // Check if the string is not empty before appending a comma

  if (DataSensor[0] != '\0') {
    strcat(DataSensor, ",");
  }
  //var[0] = '\0';
  // Concatenate each string with a comma
  strcat(DataSensor, var);
  DataSensor[60]='\0';
  //strcpy(DataSensor[150],'\0');
  //strcat(DataSensor, ",");
  

  //Serial.print(F("Data Sensor ke-"));

  //Serial.print(DataSensor);
  //DataSensor="";
}

void sendChgStatusToNextion() {
  char command[25]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(chgFlag, 5, 2, buff);
  sprintf(command, "chg.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();

  /*strchgStatus = String(chgFlag, 0);
  char buff[6];
  dtostrf(chgFlag, 5, 2, buff);
  Serial.print("Buff chg: ");
  Serial.println(buff);
  */
}
void sendBattLevelToNextion() {
  //String command = "BattLevel.txt=\"" + String(BattLevel, 0) + "\"";
  //lcd.print(command);
  char command[25]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(BattLevel, 5, 2, buff);
  snprintf(command, sizeof(command), "BattLevel.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendSpeedLevelToNextion() {
  //String command = "SpeedLevel.txt=\"" + String(SpeedLevel, 0) + "\"";
  //lcd.print(command);
  //Serial.print(command);
  char command[25]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(SpeedLevel,5, 2, buff);
  snprintf(command, sizeof(command), "SpeedLevel.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void floatToString(float value, char* buffer, int precision) {
  int intPart = static_cast<int>(value);
  int fracPart = static_cast<int>((value - intPart) * pow(10, precision));
  snprintf(buffer, 20, "%d.%0*d", intPart, precision, fracPart);
}

void sendSoundLevelToNextion() {
  char command[25]; // Adjust the size based on your requirements
  char buff[10];
  //Serial.print("Sound Level: ");
  //Serial.println(SoundLevel);
  dtostrf(SoundLevel,5,2, buff);
  //floatToString(SoundLevel, command, 2);
  snprintf(command, sizeof(command), "SoundLevel.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}


void sendTemperature1ToNextion() {
  //String command = "temp1.txt=\"" + String(temp10, 0) + "\"";
  //Serial.print(command);
  //lcd.print(command);
  char command[20]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(temp10, 5, 1, buff);
  snprintf(command, sizeof(command), "temp1.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}


void sendTemperature2ToNextion() {
  char command[20]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(temp20, 5, 1, buff);
  snprintf(command, sizeof(command), "temp2.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendTemperature3ToNextion() {
  //String command = "temp2.txt=\"" + String(temp20, 0) + "\"";
  //Serial.print(command);
  char command[20]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(temp30, 5, 1, buff);
  snprintf(command, sizeof(command), "temp3.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}


void sendTemperature4ToNextion() {
  char command[20]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(temp40, 5, 1, buff);
  snprintf(command, sizeof(command), "temp4.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendTemperature5ToNextion() {
  char command[20]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(temp50, 5, 1, buff);
  snprintf(command, sizeof(command), "temp5.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendTemperature6ToNextion() {
  char command[20]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(temp60, 5, 1, buff);
  snprintf(command, sizeof(command), "temp6.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendHumid5ToNextion() {
  char command[25]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(humid5, 5, 1, buff);
  snprintf(command, sizeof(command), "humid5.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature1ToNextion() {
  //lcd.print(command);
  char command[20]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp10, 3, 1, buff);
  snprintf(command, sizeof(command), "maxtemp1.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature2ToNextion() {
  char command[20]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp20, 3, 1, buff);
  snprintf(command, sizeof(command), "maxtemp2.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature3ToNextion() {
  //String command = "maxtemp3.txt=\"" + String(MaxTemp30, 0) + "\"";
  //Serial.print(command);
  //lcd.print(command);
  char command[20]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp30, 3, 1, buff);
  snprintf(command, sizeof(command), "maxtemp3.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature4ToNextion() {
  //String command = "maxtemp4.txt=\"" + String(MaxTemp40, 0) + "\"";
  //Serial.print(command);
  //String command="soundLvl";
  //lcd.print(command);
  char command[20]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp40, 3, 1, buff);
  snprintf(command, sizeof(command), "maxtemp4.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature5ToNextion() {
  //String command = "maxtemp5.txt=\"" + String(MaxTemp50, 0) + "\"";
  //Serial.print(command);
  //lcd.print(command);
  char command[20]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp50, 3, 1, buff);
  snprintf(command, sizeof(command), "maxtemp5.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature6ToNextion() {
  //String command = "maxtemp6.txt=\"" + String(MaxTemp60, 0) + "\"";
  //Serial.print(command);
  //lcd.print(command);
  char command[20]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp60, 3, 1, buff);
  snprintf(command, sizeof(command), "maxtemp6.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void endNextionCommand() {
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
}

void WriteDataToSD(const char* data) {
  var[59]='\0';
  myFile = SD.open("hasil1.txt", FILE_WRITE); //menulis File coba.txt
  // jika file sudah berhasil dibuka maka tulis data dimulai
  if (myFile) {
    Serial.println(F("mencoba nulis data di file hasil1.txt"));
    if (dataCount == 1) {
    myFile.println();
    myFile.println("Hasil ukur Baby Incubator Test");
    myFile.println(data);
    myFile.println("Data, T1, T2, T3, T4, T5, T6, Humadity, Air Speed, Sound Level");
    }
    myFile.print(dataCount);
    myFile.print(", ");
    myFile.print(temp10);
    myFile.print(", ");
    myFile.print(temp20);
    myFile.print(", ");
    myFile.print(temp30);
    myFile.print(", ");
    myFile.print(temp40);
    myFile.print(", ");
    myFile.print(temp50);
    myFile.print(", ");
    myFile.print(temp60);
    myFile.print(", ");
    myFile.print(humid5);
    myFile.print(", ");
    myFile.print(SpeedLevel);
    myFile.print(", ");
    myFile.print(SoundLevel);
    myFile.println();
    myFile.close();
    dataCount++;
    Serial.println("SELESAI!");
  } else {
    // jika gagal print error
    Serial.println(F("GAGAL TULIS hasil1.txt"));
  }
}

void tanggal_waktu() {
  String data = Serial.readStringUntil('\n');
  int dateIndex = data.indexOf("Date:");
  int timeIndex = data.indexOf("Time:");
  
  if (dateIndex != -1 && timeIndex != -1) {
    dateIndex += 5;
    timeIndex += 5;
    
    String date = data.substring(dateIndex, dateIndex + 8);
    String time = data.substring(timeIndex, timeIndex + 6);
    
    date = date.substring(0, 2) + "-" + date.substring(2, 4) + "-" + date.substring(4, 8);
    time = time.substring(0, 2) + ":" + time.substring(2, 4) + ":" + time.substring(4, 6);

    Serial.println("Tanggal:" + date);
    Serial.println("Waktu:" + time);
    
    String dateTime = "Date:" + date + "\nTime:" + time;
    WriteDataToSD(dateTime.c_str());
  }
}
