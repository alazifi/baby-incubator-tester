# ARDUINO CODING DOCUMENTATION
<sup>Ganti ke Bahasa Indonesia? [Klik disini!](Kode_Arduino.md)</sup>

## Version Log
- [V4.0.0](#v400-unreleased)
- [V3.0.0](#v300)
- [V2.1.0](#v210)
- [V2.0.0](#v200)
- [V1.1.0](#v110)
- [V1.0.0](#v100) 

- - - -

# V4.0.0 (unreleased)
<sup>[(Back to top)](#version-log)</sup>

#### Developer: Haidar
## Added
- **Breaking:** Added `sensIndicator` pin
- **Breaking:** Added `limiter` pin

- - - -

# V3.0.0
<sup>[(Back to top)](#version-log)</sup>

#### Developer: Haidar
## Changed
- **Breaking:** Changed the calculation method from `mapping method` to `analog to digital convertion method` for functions `soundLevel()` and `airSpeed()` 
- Changed initial value of `count` form `-3` to `-4`
- Changed pin number of `CS` from `4` to `10`
- Changed first time of data update to HMI Nextion to `8000 ms` after device boot up
- Changed interval time to store data from `3000 ms` to `1000 ms`
- Changed SPI addresses of `HTU21D`
- Changed logic in `dataCore()` function following the value of `count`

## Added
- Added library `"ADS1X15.h"` to interfacing `AUX` sensor
- Added `unsigned long` type variables 
- Added variable `logTime`
- Added special character `\n` to `dataLable()` function

## Removed
- Removed library `"MultiMap.h"`

- - - -

# V2.1.0
<sup>[(Back to top)](#version-log)</sup>

#### Developer: Haidar
## Changed
- Changed initial value of `count` to `-3`
- Changed the global variable `dataFile` to a local variable
- Changed the baud rate from `9600` to `115200`
- Changed SPI addresses of `HTU21D`
- Changed data type of `soundLevel` from `int` to `byte`
- Changed data type of `airSpeed` from `int` to `float`
- Renamed all function name that update the measurement data to HMI Nextion from `updateXxx` to `upXxx`

## Added
- Added integer variable `batVal` with value `409` as the default value of battery error handler
- Added unsigned long variables for handling interval time to update displayed data to Nextion for `1000 ms` and write data to SD card for `3000 ms`
- Combined multiple HMI update functions for each sensor into a single function `printNextion()`
- Added 6 functions to handle proccess of finding maximum temperature of HTU21D `mTempX()` and their HMI update functions `upMaxTempX()`
- Added logic alternative to battery leveling method
- Dummy default value of `airSpeed()`
- Added function `upBatLev()` to update battery percentage
- Added function `upChgState()` to indicate charging proccess
- Added char type functions `decToChar()`, `intToChar()`, and `strToChar()` to support character proccessing
- Added char type functions `dataHeader()`, `dataLable()`, `dataCore()` and `timestamp()` to support data writing to SD Card

## Removed
- Removed `chgFlag()` function

- - - -

# V2.0.0
<sup>[(Back to top)](#version-log)</sup>

#### Developer: Haidar
## Changed
- **Breaking:** renamed all variables, constants, and functions
- **Breaking:** changed some variables to functions
## Removed
- Removed the `"String.h"` library
- Removed some variables and functions

- - - -

# V1.1.0
<sup>[(Back to top)](#version-log)</sup>

#### Developer: Haidar
## Changed
- Replaced the use of a variable for the `header string constant` with a direct string literal in `Serial.println()` to optimize memory usage and improve code efficiency.
- Optimized memory usage by switching from `String concatenation method` to `myFile.print()` for SD card data writing

## Removed
- Removed a function `floatToString()`

- - - -

# V1.0.0
<sup>[(Back to top)](#version-log)</sup>
#### Developer: Rustanto
### :package: Description

The first legacy code created to support PCB device that has features:
1. Measure 6 temperature in Celcius, 1 humidity in %RH, and its maximum values, also sound level in dB and air flow in m/s
2. Display measurement results to HMI Nextion every `6000 ms`
3. Store measurement results to SD Card every `3000 ms`
4. Battery level indicator

### :clipboard: Characteristics and Functions
void TCA9548A(uint8_t bus)
void setup()
void loop()
void readSensor() 
void appendStr(char var[10])
void sendChgStatusToNextion()
void sendBattLevelToNextion()
void sendSpeedLevelToNextion() 
void floatToString(float value, char* buffer, int precision) 
void sendSoundLevelToNextion()
void sendTemperature1ToNextion() 
void sendTemperature2ToNextion() 
void sendTemperature3ToNextion() 
void sendTemperature4ToNextion() 
void sendTemperature5ToNextion() 
void sendTemperature6ToNextion() 
void sendHumid5ToNextion() 
void sendMaxTemperature1ToNextion() 
void sendMaxTemperature2ToNextion() 
void sendMaxTemperature3ToNextion()
void sendMaxTemperature4ToNextion() 
void sendMaxTemperature5ToNextion() 
void sendMaxTemperature6ToNextion() 
void endNextionCommand() 
void formatDataToString() 
void WriteDataToSD(const char* data) 
void tanggal_waktu() 

Library used:
#include <String.h>
#include <SparkFunHTU21D.h>
#include <Wire.h>
#include "MultiMap.h"
#include <SPI.h>
#include <SD.h>