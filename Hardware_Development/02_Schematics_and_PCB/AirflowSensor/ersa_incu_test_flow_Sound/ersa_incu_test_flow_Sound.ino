//final build 2022 dec with flow
//eb02203a
#include <SparkFunHTU21D.h>
#include <Wire.h> 
#include <SPI.h>
#include <SD.h>
#include "MultiMap.h"
//#include "HX711.h"
#include "ADS1X15.h"
ADS1115 ADS(0x48);

const int sampleWindow = 50;  
unsigned int sample;

HTU21D htu1 = HTU21D();
HTU21D htu2 = HTU21D();
HTU21D htu3 = HTU21D();
HTU21D htu4 = HTU21D();
HTU21D htu5 = HTU21D();
HTU21D htu6 = HTU21D();
//HX711 scale;

//uint8_t dataPin = 6;
//uint8_t clockPin = 5;
//volatile float f;
//float speedcal;

const int analogPin = A0;//batt
//const int soundPin = A1;
//const int airspeedPin = A2;
const int ChgPin = 7;
int ChgState = 0;
int BattValue = 409;
int airspeedValue = 0;
float chgFlag = 20;
float temp10;
float temp20;
float temp30;
float temp40;
float temp50;
float temp60;
//float temp70;
float BattLevel = 100;
float SoundLevel;
float SpeedLevel;

float temp1;
float temp2;
float temp3;
float temp4;
float temp5;
float temp6; 
//float temp7;
 
float MaxTemp10 = 19;
float MaxTemp20 = 19;
float MaxTemp30 = 19;
float MaxTemp40 = 19;
float MaxTemp50 = 19;
float MaxTemp60 = 19; 
float humid5;

void TCA9548A(uint8_t bus)
{
  Wire.beginTransmission(0x70);  // TCA9548A address
  if (bus > 7) return;
  Wire.write(1 << bus);          // select bus
  Wire.endTransmission();
}


void setup() {

   Serial.begin(115200);//bauds=115200
   ADS.setGain(1);
 ADS.setMode(1);
   ADS.setDataRate(4); 
     ADS.begin();
pinMode(ChgPin, INPUT);
Wire.begin();
    TCA9548A(0);                
  htu1.begin();
    TCA9548A(1);
  htu2.begin();
    TCA9548A(2);
  htu3.begin();
    TCA9548A(3);
  htu4.begin();
    TCA9548A(4);
  htu5.begin();
    TCA9548A(5);
  htu6.begin();
  //  TCA9548A(7);
  //htu7.begin();
  
}


void loop() {

  readSensor();
//  readSound();
  sendBattLevelToNextion();
  sendChgStatusToNextion();
  sendSoundLevelToNextion();
  sendSpeedLevelToNextion();
  sendTemperature1ToNextion();
  sendTemperature2ToNextion();
//  sendTemperature3ToNextion();
//  sendTemperature4ToNextion();
//  sendTemperature5ToNextion();
//  sendTemperature6ToNextion();  
//  sendrhToNextion();
 // sendMaxTemperature1ToNextion();
//  sendMaxTemperature2ToNextion();
//  sendMaxTemperature3ToNextion();
//  sendMaxTemperature4ToNextion();
//  sendMaxTemperature5ToNextion(); 
//  sendMaxTemperature6ToNextion(); 
  Serial.println("-");
  delay(200);
}


void readSensor ()
{
  TCA9548A(0);
  temp1 = htu1.readTemperature();
  temp10=temp1*1000;
  TCA9548A(1);
  temp2 = htu2.readTemperature();
  temp20=temp2*1000;
  TCA9548A(2);
  temp3 = htu3.readTemperature();
  temp30=temp3*1000;
  TCA9548A(3);
  temp4 = htu4.readTemperature();  
  temp40=temp4*1000;
  TCA9548A(4);
  temp5 = htu5.readTemperature();  
  humid5 = htu5.readHumidity();
  temp50=temp5*1000;
  TCA9548A(5);
  temp6 = htu6.readTemperature();  
  temp60=temp6*1000;

  MaxTemp10 = max(temp10, MaxTemp10);
  MaxTemp20 = max(temp20, MaxTemp20);
  MaxTemp30 = max(temp30, MaxTemp30);
  MaxTemp40 = max(temp40, MaxTemp40);
  MaxTemp50 = max(temp50, MaxTemp50);
  MaxTemp60 = max(temp60, MaxTemp60);
  //MaxTemp70 = max(temp70, MaxTemp70);

int battcalc;
battcalc = analogRead(analogPin);
BattValue = map (battcalc, 446,760, 0, 100);
BattLevel = min(BattValue, BattLevel);
if (BattLevel >100) (BattLevel = 100);
if (BattLevel <0) (BattLevel = 0);
      sample = ADS.readADC(0);
      SpeedLevel = ADS.readADC(1);

   
  float out[] = {50,52.3, 67.8, 76.2, 83.7, 90, 95,103.7};
  float in[]  = { 11757,11765, 11774, 11927, 12400, 13615, 16830,19500}; 
//SoundLevel = multiMap<float>(sample, in, out, 8);

SoundLevel = (sample);

ChgState = digitalRead(ChgPin);

if (ChgState == HIGH)
{
BattLevel = 100;
chgFlag = 10;
}
else 
{chgFlag = 30;
}
}


void sendChgStatusToNextion()
{
  String command = "chg.txt=\""+String(chgFlag,0) +"\"";
  Serial.print(command);
  endNextionCommand();
}
void sendBattLevelToNextion()
{
  String command = "BattLevel.txt=\""+String(BattLevel,0) +"\"";
  Serial.print(command);
  endNextionCommand();
}
void sendSpeedLevelToNextion()
{
  String command = "SpeedLevel.txt=\""+String(SpeedLevel,0) +"\"";
  Serial.print(command);
  endNextionCommand();
}
void sendSoundLevelToNextion()
{
  String command = "SoundLevel.txt=\""+String(SoundLevel ,1) +"\"";
  Serial.print(command);
  endNextionCommand();

}

void sendTemperature1ToNextion()
{
  String command = "temp1.txt=\""+String(temp10,0) +"\"";
  Serial.print(command);
  endNextionCommand();
}
void sendMaxTemperature1ToNextion()
{
  String command = "maxtemp1.txt=\""+String(MaxTemp10,0) +"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendTemperature2ToNextion()
{
  String command = "temp2.txt=\""+String(temp20,0)+"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendMaxTemperature2ToNextion()
{
  String command = "maxtemp2.txt=\""+String(MaxTemp20,0) +"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendTemperature3ToNextion()
{
  String command = "temp3.txt=\""+String(temp30,0)+"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendMaxTemperature3ToNextion()
{
  String command = "maxtemp3.txt=\""+String(MaxTemp30,0) +"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendTemperature4ToNextion()
{
  String command = "temp4.txt=\""+String(temp40,0)+"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendMaxTemperature4ToNextion()
{
  String command = "maxtemp4.txt=\""+String(MaxTemp40,0) +"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendTemperature5ToNextion()
{
  String command = "temp5.txt=\""+String(temp50,0)+"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendMaxTemperature5ToNextion()
{
  String command = "maxtemp5.txt=\""+String(MaxTemp50,0) +"\"";
  Serial.print(command);
  endNextionCommand();
  
}

void sendrhToNextion()
{
  String command = "rh.txt=\""+String(humid5,1)+"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendTemperature6ToNextion()
{
  String command = "temp6.txt=\""+String(temp60,0)+"\"";
  Serial.print(command);
  endNextionCommand();
}

void sendMaxTemperature6ToNextion()
{
  String command = "maxtemp6.txt=\""+String(MaxTemp60,0) +"\"";
  Serial.print(command);
  endNextionCommand();
}


void endNextionCommand()
{
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}
