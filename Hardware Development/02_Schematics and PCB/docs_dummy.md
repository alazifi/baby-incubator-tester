# MAIN PCB DOCUMENTATION

## Guide for Versioning
Semantic versioning uses this format:
```bash
X.Y.Z
```
that corresponds to
```bash
MAJOR.MINOR.PATCH
```
Details:
1. **MAJOR** indicates major changes that are incompatible with previous versions.
	- Example: Redesigning new architecture and changing the core functionality
	- Increment: `1.0.0` &rarr; `2.0.0`

2. **MINOR** indicates changes that are backward-compatible with the addition of new features
	- Example: Adding new sensor
	- Increment: `1.1.0` &rarr; `1.2.0`

3. **PATCH** indicates minor changes that do not add new features but solve issues or optimize existing functionalities
	- Example: Bug fixing, replacing faulty component
	- Increment: `1.1.1` &rarr; `1.1.2`


## Version log
- [V1.0.0](#V1.0.0)
- [V2.0.0](#V2.0.0)



<a name="V1.0.0"></a>

# V1.0.0
#### Creator: Mr. Rustanto
### :package: Description

The legacy system version of Fania Ersa's PCB that has features:
- 6 probes of temperature measurement based on HTU21D
- 1 Human Machine Interface using Nextion NX4827K043
- 1 x micro SD slot to store measurement data 
- Rechargeable device using 12V/2A adapter

### :clipboard: Characteristics

#### :hammer_and_wrench: Schematic:
- Uses green colored wire to connect between components
#### :zap: PCB:
- PCB dimension is 128.5 mm x 74.3 mm
- Dedicated port for uploading program

<a name="V2.0.0"></a>

# V2.0.0
#### Creator: Mr. Haidar
### :package: Description

Versi 2 

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
- Changing the wiring method from using green wires to global labels
- Changing symbols, references, and values of all components
- Changing pin connections between components
- Assigning new footprint to the new symbols
- Adding component symbol `74VHC125M` to support data storage to the SD card

#### :zap: PCB:
- Changing dimension to 93.8 mm x 75 mm
- Changing layout
- Eliminating dedicated port for uploading program

# V2.1.1
#### Creator: Mr. Haidar
### :package: Description

Versi 2.1.1

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
##### Patch Changes
1. References Changes

	<div align="center">

	| V2.0.0 | V2.1.1 |
	|:------:|:------:|
	|U1|ATMEGA328|
	|U2|BufferSD|
	|U4|StepDown|
	|U5|PCA9548A|
	|J4|T6|
	|J5|T5|
	|J6|T4|
	|J7|T3|
	|J8|T2|
	|J9|T1|
	|J10|I2C|
	|J12|Nextion|
	|J13|AUX|

	</div>

2. Values Changes

	<div align="center">

	| V2.0.0 | V2.1.1 |
	|:------:|:------:|
	|74VHC125M|IC-SD|
	|Next|Nextion|

	</div>

3. Pin Connection Changes
	- AUX 
		<div align="center">

		|AUX PINS| V2.0.0 | V2.1.1 |
		|:-----:|:------:|:------:|
		|3|AUX1|AUX2|
		|4|AUX2|AUX1|

		</div>

	- I2C
		<div align="center">

		|I2C PINS| V2.0.0 | V2.1.1 |
		|:-----:|:------:|:------:|
		|3|SDA|SCL|
		|4|SCL|SDA|

		</div>

	- Nextion
		<div align="center">

		|I2C PINS| V2.0.0 | V2.1.1 |
		|:-----:|:------:|:------:|
		|1|5VDC|SCL|
		|2|RX|5VDC|
		|4|GND|RX|

		</div>

	- PCA9548A
		<div align="center">

		|I2C PINS| V2.0.0 | V2.1.1 |
		|:-----:|:------:|:------:|
		|9 (SD0)|SDA0|unconnected|
		|10 (SC0)|SCL0|unconnected|
		|11 (SD1)|SDA1|unconnected|
		|12 (SC1)|SCL1|unconnected|
		|13 (SD2)|SDA2|SDA0|
		|14 (SC2)|SCL2|SCL0|
		|15 (SD3)|SDA3|SDA1|
		|16 (SC3)|SCL3|SCL1|
		|17 (SD4)|SDA4|SDA2|
		|18 (SC4)|SCL4|SCL2|
		|19 (SD6)|unconnected|SDA3|
		|20 (SC6)|unconnected|SCL3|
		|21 (SD7)|unconnected|SDA4|
		|22 (SC7)|unconnected|SCL4|
		</div>

#### :zap: PCB:
##### Minor Changes
1. Adding 1 hole for mounting
2. Changing layout
3. Changing dimension to 94.23 mm x 75 mm

##### Patch Changes
1. Changing references, values, nets, and footprints corresponds to schematics
2. Adding ground plane
	
# V3.1.1
#### Creator: Mr. Haidar
### :package: Description

Versi 3.1.1

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
##### Major Changes
1. Breakdown U5 step down DC-DC module to IC and its support components:
	| Symbol | Value |
	|:------:|:------:|
	|LM2596T-5|LM2596T-5|
	|1N5824|1N5824|
	|C7|680 uF|
	|C8|220 uF|
	|L1|47 uH|

2. Changing symbol and footprint of VDCIn1 reference with 2 pin to Jack DC symbol with 3 pin 
##### Patch Changes
1. References Changes
	
	<div align="center">

	| V2.1.1 | V3.1.1 |
	|:------:|:------:|
	|Nextion|Nextion1|
	|I2C|I2C1|
	|AUX|AUX1|
	|BufferSD|BufferSD1|
	|PCA9548A|PCA9548A1|
	|J1|VDCIn1|
	|J2|Battery1|
	|J3|SwitchSlot1|
	|U3|AMS1117|
	
	</div>

2. Pin Connections Changes
	- PCA9548A1

		<div align="center">

		|I2C PINS| V2.1.1 | V3.1.1 |
		|:------:|:------:|:------:|
		|9 (SD0)|unconnected|SDA4|
		|10 (SC0)|unconnected|SCL4|
		|11 (SD1)|unconnected|SDA3|
		|12 (SC1)|unconnected|SCL3|
		|21 (SD6)|SDA3|unconnected|
		|22 (SC6)|SCL3|unconnected|
		|23 (SD7)|SDA4|unconnected|
		|24 (SC7)|SCL4|unconnected|

		</div>

	- Nextion1

		<div align="center">

		|Nextion PINS| V2.1.1 | V3.1.1 |
		|:------:|:------:|:------:|
		|2|5VDC|GND|
		|1|GND|5VDC|

		</div>
		
4. Values Changes:
	- Delete all unit
3. Footprints Changes:
	- Vertical JST to horizontal JST for Battery1

#### :zap: PCB:
##### Major Changes
1. Changing layout as the impact of step down breakdown
2. Changing dimension to 91 mm x 65.5 mm

##### Minor Changes
1. Changing hole position

V4.1.1 V3 to V4
Perubahan Major
Schematic:
1. Penambahan U6 dengan value OUT-7,5V sebagai sumber daya 2 untuk sensor 7,5 V beserta komponen pendukung:
- D2 1N5835
- L2 33uH
- C9 680 uF
- C10 330 uF
- R11 1k
- R12 1k
- R13 390
- CFF1 1,5nF
 
PCB:
Ukuran menjadi 92 mm x 75 mm

Perubahan Minor
Schematic:
Penggantian komponen:
	- L1 dengan nilai 47 uH
PCB:
Perubahan Patch
Schematic:
Perubahan References:
- 1N5401 menjadi D1
- 1N5825 menjadi D3
- LM2596T-5 menjadi U5
- ATMega328 menjadi U1
- AMS1117 menjadi U2
- C1 menjadi C7
- C2 menjadi C5
- C3 menjadi C2
- C5 menjadi C6
- C6 menjadi C1
- BufferSD1 menjadi U4
- VDCIn1 menjadi J12
- Battery1 menjadi J10
- SwitchSlot1 menjadi J11
- R7 menjadi R4
- R5 menjadi R8
- R6 menjadi R9
- R1 menjadi R5
- R2 menjadi R6
- R3 menjadi R10
- I2C1 menjadi J7
- Nextion1 menjadi J8
- AUX1 menjadi J9
- T6 menjadi J6
- T5 menjadi J5
- T4 menjadi J4
- T3 menjadi J3
- T2 menjadi J2
- T1 menjadi J1

Perubahan Values:
- LM2596T-5 menjadi OUT-5V

Perubahan koneksi pin:
	- Pin J7
		Pin 1 to 5VDC menjadi to 7V5DC
	- Pin J9
		Pin 1 to 5VDC menjadi to 7V5DC
		Pin 3 to AUX2 menjadi to AUX1
		Pin 4 to AUX1 menjadi to AUX2
	- Pin PCA9548A
		Pin 9 (SD0) to SDA4 menjadi unconnected
		Pin 10 (SC0) to SCL4 menjadi unconnected
		Pin 11 (SD1) to SDA3 menjadi unconnected
		Pin 12 (SC1) to SCL3 menjadi unconnected
		Pin 13 (SD2) to SDA0 menjadi to SDA2
		Pin 14 (SC2) to SCL0 menjadi to SCL2
		Pin 15 (SD3) to SDA1 menjadi to SDA1
		Pin 16 (SC3) to SCL1 menjadi to SCL1
		Pin 17 (SD4) to SDA2 menjadi to SDA0
		Pin 18 (SC4) to SCL2 menjadi to SCL0
		Pin 19 (SD5) to SDA5 menjadi to SDA5
		Pin 20 (SC5) to SCL5 menjadi to SCL5
		Pin 21 (SD6) to unconnected menjadi to SDA3
		Pin 22 (SC6) to unconnected menjadi to SCL3
		Pin 23 (SD7) to unconnected menjadi to SDA4
		Pin 24 (SC7) to unconnected menjadi to SCL4
PCB:
1. Perubahan layout PCB
2. Penambahan 1 hole 
3. Perubahan posisi hole dengan acuan pojok kiri atas dengan posisi soket di pojok kanan bawah

V4.2.1 v4 to v5
Perubahan Minor:
Skematik:
1. Penggantian komponen Daya U5:
	- R14 nilai 330
	- C8 nilai 470
	- R15 nilai 1k
	- CFF2 nilai 3,3 nF
2. Penggantian Value:
	- I2C menjadi AUX
	- AUX menjadi AUX2
3. Penggantian Symbol J7 4 pin menjadi 5 pin
	- Pin 1 to 7V5DC
	- Pin 2 to GND1
	- Pin 3 to GND2
	- Pin 4 to SCL
	- Pin 5 to SDA

Perubahan Patch:
	
Skematik:
Perubahan symbol U5 fixed stepdown menjadi adjustable
Perubahan references:
D2 menjadi D3
D3 menjadi D2

PCB:
1. Ground plane AUX dibedakan dari main ground plane
2. Ukuran PCB 92 mm x 75 mm dengan edge cuts


V4.3.1 (Versi Print PCB pertama) V5 to V6
Perubahan Minor:
Schematic:
Perubahan Symbol:
- Symbol IC U5 menjadi modul step down U5 dengan value StepDownLM2596
- Symbol IC U6 menjadi modul step down U6 dengan value StepDownLM2596
- Peniadaan komponen pendukung IC U5 dan U6
- Penyesuaian footprint U5 dan U6
PCB:
1. Perubahan layout PCB
2. Ukuran edge cuts menjadi 105mm x 75 mm
3. Penghilangan 1 hole
4. Penambahan 3d Visual unutk semua komponen

Perubahan Patch:
Perubahan Symbol:
J7 5 pin menjadi 4 pin
J9 4 pin menjadi 5 pin
Perubahan Values:
- AUX menjadi I2C
- AUX2 menjadi AUX
Perubahan koneksi:
- Symbol J7
	- Pin 2 to GND1 menjadi to GND
	- Pin 3 to GND2 menjadi to SCL
	- Pin 4 to SCL menjadi to SDA
- Symbol J9
	- Pin 3 to AUX1 menjadi to GND
	- Pin 4 to AUX2 menjadi to AUX1
	- Pin 5 to AUX2
- Symbol J13
	- Pin 1 (DAT2) semula floating menjadi to GND
	- Pin 10 dan 11 (MOUNT) semula floating menjadi to GND

V4.4.1 versi v6 to v7
Perubahan Minor:
Skematik
Penambahan 4 Test point:
- TP1 dengan value GND
- TP2 dengan value 5 V
- TP3 dengan value 7,5 V
- TP4 dengan value 12 V
PCB:
- penyesuaian layout pcb dengan test point, penghilangan komponen
- Penyesuaian layout pcb dengan resistor

Perubahan Patch:
Perubahan references
J13 menjadi J12
J12 menjadi J11
J10 menjadi J9
J11 menjadi J10
C2 menjadi C4
C4 menjadi C5 
C5 menjadi C1
C7 menjadi C2
J7 dengan value I2C dihilangkan
J8 menjadi J7
J9 menjadi J8

Perubahan koneksi:
- Pin J7 Nextion:
	- Pin 1 to 5VDC menjadi to GND
	- Pin 2 to GND menjadi to TX
	- Pin 3 to TX menjadi to RX
	- Pin 4 to RX menjadi to 5VDC
- Pin J8 AUX:
	- Pin 4 to AUX1 menjadi to SCL
	- Pin 5 to AUX2 menjadi to SDA
- Pin U4:
	- Label MISO dan MISO_L ditukar
	
PCB:
1. Perubahan tata letak text

V5.1.1
Perubahan Major
Skematik:
- Penggantian module U6 sebagai step down menjadi U6 dengan module ADS1115 sebagai amplifier
- Penggantian soket J10 2 pin menjadi 3 pin untuk fungsional lampu indikator
- Penambahan fitur indikator koneksi J8
	- Resistor pull up R11 dengan nilai 10k pada U1 pin 14 (PB0)
- Penambahan fitur limiter saat baterai mendekati ambang batas terendah 
	- Q1 dengan BD140
		- Basis sebagai trigger dengan input dari U1 pin 15 (PB1) 
		- Emiter 
	- R12 dengan 200 sebagai basis
- wiring 5VDC terpisah menjadi:
	- 5VDCB untuk komponen tidak terdampak limiter
	- 5VDCL untuk komponen terdampak limiter


PCB:
Perubahan Minor:
Skematik:
Perubahan wiring J8:
- Pin 1 to 75VDC menjadi to GAIN1
- Pin 2 to GND menjadi to GAIN0
- Pin 3 to GND menjadi to Sens_Indicator
- Pin 4 to SCL menjadi to GND
- Pin 5 to SDA menjadi 5VDCL

Perubahan tata teks

Perubahan koneksi
	- U1
		Pin 7 (VCC) to 5VDC menjadi to 5VDCB
		Pin 20 (AVCC) to 5VDC menjadi to 5VDCB
	- U2
		Pin 3 (VI) to 5VDC menjadi to 5VDCL
Perubahan koneksi
	- U5
		Pin 4 (OUT+) to 5VDC menjadi to 5VDCB

Perubahan posisi hole 		
		
Perubahan value:
IC-SD menjadi 74HCT125
PCB:
Perubahan Patch:
Skematik:
0. TP4 dihilangkan
1. Penambahan satuan untuk value
2. Perubahan wiring
	- Pin J7:
		Pin 1 to GND menjadi to 5VDCL
	    Pin 4 to 5VDC menjadi to GND
	- Pin PCA9548A
		Pin 13 (SD2) to SDA2 menjadi to SDA0
		Pin 14 (SC2) to SCL2 menjadi to SCL0
		Pin 15 (SD3) to SDA1 menjadi to SDA1
		Pin 16 (SC3) to SCL1 menjadi to SCL1
		Pin 17 (SD4) to SDA0 menjadi to SDA2
		Pin 18 (SC4) to SCL0 menjadi to SCL2
		Pin 19 (SD5) to SDA5 menjadi to SDA3
		Pin 20 (SC5) to SCL5 menjadi to SCL3
		Pin 21 (SD6) to SDA3 menjadi to SDA4
		Pin 22 (SC6) to SCL3 menjadi to SCL4
		Pin 23 (SD7) to SDA4 menjadi to SDA5
 		Pin 24 (SC7) to SCL4 menjadi to SCL5
3. Perubahan value
	- StepDownLM2596 menjadi Step_Down_DCDC
	- TP3 menjadi 12V
