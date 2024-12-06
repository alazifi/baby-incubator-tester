//final build 2022 dec
#include <SparkFunHTU21D.h>
#include <Wire.h> 
#include "MultiMap.h"

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
  sendTemperature3ToNextion();
  sendTemperature4ToNextion();
  sendTemperature5ToNextion();
  sendTemperature6ToNextion();  
  sendrhToNextion();
  sendMaxTemperature1ToNextion();
  sendMaxTemperature2ToNextion();
  sendMaxTemperature3ToNextion();
  sendMaxTemperature4ToNextion();
  sendMaxTemperature5ToNextion(); 
  sendMaxTemperature6ToNextion(); 
  Serial.println("-");
  delay(200);
}


void readSensor ()
{
  TCA9548A(1);
  temp1 = htu1.readTemperature();
  temp10=temp1*1000;
  TCA9548A(2);
  temp2 = htu2.readTemperature();
  temp20=temp2*1000;
  TCA9548A(3);
  temp3 = htu3.readTemperature();
  temp30=temp3*1000;
  TCA9548A(4);
  temp4 = htu4.readTemperature();  
  temp40=temp4*1000;
  TCA9548A(5);
  temp5 = htu5.readTemperature();  
  humid5 = htu5.readHumidity();
  temp50=temp5*1000;
  TCA9548A(6);
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
BattValue = map (battcalc, 370,405, 50, 100);
BattLevel = min(BattValue, BattLevel);
if (BattLevel >100) (BattLevel = 100);

   unsigned long startMillis= millis();                   // Start of sample window
   float peakToPeak = 0;                                  // peak-to-peak level
   unsigned int signalMax = 0;                            //minimum value
   unsigned int signalMin = 1024;                         //maximum value
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(soundPin);                             //get reading from microphone
      if (sample < 1024)                                  // toss out spurious readings
      {if (sample > signalMax)
         {signalMax = sample;                           // save just the max levels
         }
         else if (sample < signalMin)
         {signalMin = sample;                           // save just the min levels
         }
      }
   }
int avg = signalMax - signalMin; 
  float out[] = {45, 50, 54, 65, 77, 82, 84, 87, 90, 93};
  float in[]  = { 45, 77, 99, 135, 190, 293, 409, 569, 615, 1012}; 
  SoundLevel = multiMap<float>(avg, in, out, 10);
SpeedLevel  = 0;

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
  String command = "SoundLevel.txt=\""+String(SoundLevel ,0) +"\"";
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
