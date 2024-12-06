//final build 2022 dec
//script ini sudah tampil pembacaan sensornya
// belum dicoba untuk SDcard nya


#include <SparkFunHTU21D.h>
#include <Wire.h>
#include "MultiMap.h"
//#include <SoftwareSerial.h>  //Terlalu besar makan memori
#include <SPI.h>
#include <SD.h>

//SoftwareSerial lcd(2, 3);
const int sampleWindow = 50;
unsigned int sample;



HTU21D htu1 = HTU21D();
HTU21D htu2 = HTU21D();
HTU21D htu3 = HTU21D();
HTU21D htu4 = HTU21D();
HTU21D htu5 = HTU21D();
HTU21D htu6 = HTU21D();

const int analogPin = A0;
const int soundPin = A2;
const int airspeedPin = A1;
const int ChgPin = 7;
int ChgState = 0;
int BattValue = 409;
int airspeedValue = 0;
float chgFlag = 19;
float temp10=1;
float temp20=1;
float temp30=1;
float temp40=1;
float temp50=1;
float temp60=1;

float BattLevel = 100;
float SoundLevel;
float SpeedLevel;

/*
char strchgStatus[6];
char strBattLevel[6];
char strSpeedLevel[6];
char strSoundLevel[6];
char strTemp10[6];
char strTemp20[6];
char strTemp30[6];
char strTemp40[6];
char strTemp50[6];
char strTemp60[6];
char strHumid5[6];
char strMaxTemp10[6];
char strMaxTemp20[6];
char strMaxTemp30[6];
char strMaxTemp40[6];
char strMaxTemp50[6];
char strMaxTemp60[6];
*/

// Maximum length of the concatenated string
const size_t maxStringLength = 6;

// Buffers for C-style strings
char buffer[maxStringLength];


float MaxTemp10;
float MaxTemp20;
float MaxTemp30;
float MaxTemp40;
float MaxTemp50;
float MaxTemp60;

unsigned long prevMillis = 0;
unsigned long prevMillis2 = 0;

float humid5;

char DataSensor[153]; //fixed size of array

void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(0x70);  // TCA9548A address
  if (bus > 7) return;
  Wire.write(1 << bus);  // select bus
  Wire.endTransmission();
  //delay(100);
}


void setup() {
  Serial.begin(9600);
  //lcd.begin(9600);

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
  unsigned long currentMillis = millis();
  if ((currentMillis - prevMillis >= 6000)&&(flag==false)) { 
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
    sendTemperature6ToNextion();
    sendHumid5ToNextion();
  /*
    sendMaxTemperature1ToNextion();
    sendMaxTemperature2ToNextion();
    sendMaxTemperature3ToNextion();
    sendMaxTemperature4ToNextion();
    sendMaxTemperature5ToNextion(); 
    sendMaxTemperature6ToNextion();
  */
    Serial.println(F("Flag: False"));
    flag=true;
    prevMillis = currentMillis;
    Serial.print(F("prevMillis: "));
    Serial.println(prevMillis);
    Serial.println(); 


  }

  if ((currentMillis - prevMillis >= 3000) && (flag==true)) {
    // Task 2: Run every 4000 milliseconds
    //WriteDataToSD(DataSensor);
    ReadDataSD();
    //strcpy(DataSensor[150],'\0');
    //strcpy(DataSensor,"\0");
    /*
    for(int i=0;i<155;i++)
    {
      Serial.print(F("Data Sensor ke-"));
      Serial.println(i);
      Serial.print(DataSensor[i]);
    }  
    */
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
  float temp1;
  float temp2;
  float temp3;
  float temp4;
  float temp5;
  float temp6;

  TCA9548A(1);
  temp1 = htu1.readTemperature();
  temp10 = temp1 * 10;
  TCA9548A(2);
  temp2 = htu2.readTemperature();
  temp20 = temp2 * 10;
  TCA9548A(3);
  temp3 = htu3.readTemperature();
  temp30 = temp3 * 10;
  TCA9548A(4);
  temp4 = htu4.readTemperature();
  temp40 = temp4 * 10;
  TCA9548A(5);
  temp5 = htu5.readTemperature();
  temp50 = temp5 * 10;
  humid5 = htu5.readHumidity();
  
  TCA9548A(6);
  temp6 = htu6.readTemperature();
  
  temp60 = temp6 * 10;

  MaxTemp10 = max(temp10, MaxTemp10);
  MaxTemp20 = max(temp20, MaxTemp20);
  MaxTemp30 = max(temp30, MaxTemp30);
  MaxTemp40 = max(temp40, MaxTemp40);
  MaxTemp50 = max(temp50, MaxTemp50);
  MaxTemp60 = max(temp60, MaxTemp60);
  //MaxTemp70 = max(temp70, MaxTemp70);
  
  int battcalc;
  battcalc = analogRead(analogPin);
  BattValue = map(battcalc, 370, 405, 50, 100);
  BattLevel = min(BattValue, BattLevel);
  if (BattLevel > 100) (BattLevel = 100);

  unsigned long startMillis = millis();  // Start of sample window
  float peakToPeak = 0;                  // peak-to-peak level
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
  float out[] = { 45, 50, 54, 65, 77, 82, 84, 87, 90, 93 };
  float in[] = { 45, 77, 99, 135, 190, 293, 409, 569, 615, 1012 };
  SoundLevel = multiMap<float>(avg, in, out, 10);

  SpeedLevel = 0;
  ChgState = digitalRead(ChgPin);

  if (ChgState == HIGH) {
    BattLevel = 100;
    chgFlag = 10;
  } else {
    chgFlag = 30;
  }
}

void appendStr(char var[10]) {
  // Check if the string is not empty before appending a comma

  if (DataSensor[0] != '\0') {
    strcat(DataSensor, ",");
  }
  //var[0] = '\0';
  // Concatenate each string with a comma
  strcat(DataSensor, var);
  DataSensor[152]='\0';
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
  dtostrf(temp10, 5, 2, buff);
  snprintf(command, sizeof(command), "temp1.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}


void sendTemperature2ToNextion() {
  char command[20]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(temp20, 5, 2, buff);
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
  dtostrf(temp30, 5, 2, buff);
  snprintf(command, sizeof(command), "temp3.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}


void sendTemperature4ToNextion() {
  char command[20]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(temp40, 5, 2, buff);
  snprintf(command, sizeof(command), "temp4.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendTemperature5ToNextion() {
  char command[20]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(temp50, 5, 2, buff);
  snprintf(command, sizeof(command), "temp5.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendTemperature6ToNextion() {
  char command[20]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(temp60, 5, 2, buff);
  snprintf(command, sizeof(command), "temp6.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendHumid5ToNextion() {
  char command[25]; // Adjust the size based on your requirements
  char buff[10];
  dtostrf(humid5, 5, 2, buff);
  snprintf(command, sizeof(command), "humid5.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature1ToNextion() {

  //lcd.print(command);
  char command[25]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp10, 5, 2, buff);
  snprintf(command, sizeof(command), "maxtemp1.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();

}

void sendMaxTemperature2ToNextion() {
  char command[25]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp20, 5, 2, buff);
  snprintf(command, sizeof(command), "maxtemp2.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature3ToNextion() {
  //String command = "maxtemp3.txt=\"" + String(MaxTemp30, 0) + "\"";
  //Serial.print(command);
  //lcd.print(command);
  char command[25]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp30, 5, 2, buff);
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
  char command[25]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp40, 5, 2, buff);
  snprintf(command, sizeof(command), "maxtemp4.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature5ToNextion() {
  //String command = "maxtemp5.txt=\"" + String(MaxTemp50, 0) + "\"";
  //Serial.print(command);
  //lcd.print(command);
  char command[25]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp50, 5, 2, buff);
  snprintf(command, sizeof(command), "maxtemp5.txt=\"%s\"", buff);
  Serial.print(command);
  appendStr(buff);
  endNextionCommand();
}

void sendMaxTemperature6ToNextion() {
  //String command = "maxtemp6.txt=\"" + String(MaxTemp60, 0) + "\"";
  //Serial.print(command);
  //lcd.print(command);
  char command[25]; // Adjust the size based on your requirements
  char buff[15];
  dtostrf(MaxTemp60, 5, 2, buff);
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

//* CODE FOR WRITE to SD CARD *\\

void WriteDataToSD(char var[152]) {
  var[152]='\0';
  File myFile;
  myFile = SD.open("Logger.csv", FILE_WRITE); //menulis File coba.txt
  // jika file sudah berhasil dibuka maka tulis data dimulai
  if (myFile) {
    Serial.println(F("mencoba nulis data di file Logger.csv"));

      //Serial.write(myFile.read()); 
    
    myFile.print(var);
    //myFile.print(",");
    myFile.println();


    myFile.close();
    Serial.println(F("SELESAI!"));
  } else {
    // jika gagal print error
    Serial.println(F("GAGAL TULIS Logger.csv"));
  }
}
/****Code to read file in SD card ****/
//baca data di SD card
void ReadDataSD() {
  File myFile;
  Serial.println(F("Open file on MicroSD card..."));
  
  myFile = SD.open("Logger.csv");
  if (myFile) {
    Serial.print(F("Logger.csv"));
    Serial.println(F("..."));
     while(myFile.available())   // tunggu sampai file siap terbuka 
    { 
      Serial.write(myFile.read()); 
    }

    Serial.println(F("berhasil ditampilkan"));
    myFile.close();  // Close the file handle
    Serial.println(F("done!"));
  } else {
    Serial.println(F("failed Read File"));
  }
}
