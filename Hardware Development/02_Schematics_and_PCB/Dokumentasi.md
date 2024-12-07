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
- [V5.1.1](#v5.1.1)
- [V4.4.1](#v4.4.1)
- [V4.3.1](#v4.3.1)
- [V4.2.1](#v4.2.1)
- [V4.1.1](#v4.1.1)
- [V3.1.1](#v3.1.1)
- [V2.1.1](#v2.1.1)
- [V2.0.0](#v2.0.0)
- [V1.0.0](#v1.0.0)

<a name="V5.1.1"></a>

# V5.1.1
#### Creator: Mr. Haidar
### :package: Description

Versi 5.1.1

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
##### Major Changes
1. Changing U6 module step down menjadi U6 to ADS1115 module as amplifier
2. Changing 2 pin J10 to 3 pin J10 as indicator lamp
3. Adding connection indicator of J8 with pull up resistor R11 with value 10k at pin 14 U1 (PB0)
4. Adding power limiter feature with force shut down when battery at the lowest threshold with components: 
	- Q1 symbol with value BD140
		- Base as trigger from input pin 15 U1 (PB1) 
		- Emitter as 5VDCB
		- Collector as 5VDCL
	- R12 symbol with value 200 as base resistor
5. 5VDC wiring splitted into:
	- 5VDCB for not afected components by limiter
	- 5VDCL for affected components by limiter

##### Minor Changes
1. Changing pin connections of J8:
		<div align="center">
	|J8 PINS|V4.3.1| V5.1.1 |
	|:------:|:------:|:------:|
	|1|75VDC|GAIN1|
	|2|GND|GAIN0|
	|3|GND|Sens_Indicator|
	|4|SCL|GND|
	|5|SDA|5VDCL|
	</div>
2. Changing text layout
3. Changing connections
	- U1
			<div align="center">
		|U1 PINS|V4.3.1| V5.1.1 |
		|:------:|:------:|:------:|
		|7 (VCC)|5VDC|5VDCB|
		|20 (AVCC)|5VDC|5VDCB|
		</div>
	- 5VDC connenction at Pin 3 U2 (VI) to 5VDCL
	- 5VDC connection at pin 4 U5 (OUT+) to 5VDCB
4. Changing hole position 			
5. Changing value of IC-SD to 74HCT125

##### Patch Changes:

1. Eliminating TP4 symbol
2. Adding unit for all values
3. Changing pin connections
	- J7
			<div align="center">
		|J7 PINS|V4.3.1| V5.1.1 |
		|:------:|:------:|:------:|
		|1|GND|5VDCL|
	    |4|5VDC|GND|
		</div>
	- PCA9548A
			<div align="center">
		|PCA9548 PINS|V4.3.1| V5.1.1 |
		|:------:|:------:|:------:|
		|13 (SD2)|SDA2|SDA0|
		|14 (SC2)|SCL2|SCL0|
		|15 (SD3)|SDA1|SDA1|
		|16 (SC3)|SCL1|SCL1|
		|17 (SD4)|SDA0|SDA2|
		|18 (SC4)|SCL0|SCL2|
		|19 (SD5)|SDA5|SDA3|
		|20 (SC5)|SCL5|SCL3|
		|21 (SD6)|SDA3|SDA4|
		|22 (SC6)|SCL3|SCL4|
		|23 (SD7)|SDA4|SDA5|
 		|24 (SC7)|SCL4|SCL5|
		</div>
3. Changing values
		<div align="center">
	|V4.3.1|V4.3.1|
	|:------:|:------:|
	|StepDownLM2596|Step_Down_DCDC|
	|TP3|12V|
	</div>

<a name="V4.4.1"></a>

# V4.4.1
#### Creator: Mr. Haidar
### :package: Description

Versi 4.4.1

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
##### Minor Changes
1. Adding 4 test point symbols:
	- TP1 dengan value GND
	- TP2 dengan value 5 V
	- TP3 dengan value 7,5 V
	- TP4 dengan value 12 V

##### Patch Changes:
1. Changing references
		<div align="center">
	|V4.3.1|V4.4.1|
	|:------:|:------:|
	|J13|J12|
	|J12|J11|
	|J10|J9|
	|J11|J10|
	|C2|C4|
	|C4|C5|
	|C5|C1|
	|C7|C2|
	|J8|J7|
	|J9|J8|
	</div>
2. Eliminating J7 with value I2C
3. Changing pin connections
	- J7
			<div align="center">
		|J7 PINS|V4.3.1|V4.4.1|
		|:---:|:------:|:------:|
		|1|5VDC|GND|
		|2|GND|TX|
		|3|TX|RX|
		|4|RX|5VDC|
		</div>
	- J8
			<div align="center">
		|J8 PINS|V4.3.1|V4.4.1|
		|:---:|:------:|:------:|
		|4|AUX1|SCL|
		|5|AUX2|SDA|
		</div>
	- Exchange MISO label and MISO_L label

#### :zap: PCB:
##### Minor Changes
1. Changing layout as addition of test points, elimination of components, alignment of resistors

##### Patch Changes
1. Changing text layout

<a name="V4.3.1"></a>

# V4.3.1 (Second printed version)
#### Creator: Mr. Haidar
### :package: Description
Versi 4.3.1

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
##### Minor Changes

1. Changing symbol:
	- IC U5 Symbol to step down module U5 with value StepDownLM2596
	- IC U6 symbol to step down module U6 with value StepDownLM2596
2. Eliminating support components of U5 and U6 IC's
3. Adjusting footprint of U5 and U6 symbols

##### Patch Changes
1. Changing symbol:
	- 5 pin J7 to 4 pin J7
	- 4 pin J9 to 5 pin J9
2. Changing values:
	<div align="center">

	|V4.2.1|V4.3.1|
	|:------:|:------:|
	|AUX|I2C|
	|AUX2|AUX|
	</div>

3. Changing pin connections:
	- J7
			<div align="center">
		|J7 PINS|V4.2.1| V4.3.1 |
		|:------:|:------:|:------:|
		|2|GND1|GND|
		|3|GND2|SCL|
		|4|SCL|SDA|
		</div>
	- J9
			<div align="center">
		|J9 PINS|V4.2.1| V4.3.1 |
		|:------:|:------:|:------:|
		|3|AUX1|GND|
		|4|AUX2|AUX1|
		|5|no pin|AUX2|
		</div>
	- J13
			<div align="center">
		|J9 PINS|V4.2.1| V4.3.1 |
		|:------:|:------:|:------:|
		|1 (DAT2)|no connection|GND|
		|10 (MOUNT)|no connection|GND|
		|11 (MOUNT)|no connection|GND|
		</div>

#### :zap: PCB:
##### Minor Changes
1. Changing layout
2. Changing dimension to 105mm x 75 mm
3. Eliminating 1 hole
4. Adding 3D visual for all components


<a name="V4.2.1"></a>

# V4.2.1
#### Creator: Mr. Haidar
### :package: Description

Versi 4.2.1

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
##### Minor Changes
1. Adding support components of U5:

	<div align="center">

	|Symbol| Value |
	|:------:|:------:|
	|R14|330|
	|C8|470|
	|R15|1k|
	|CFF2|3.3 nF|
	</div>

2. Changing Value:
	<div align="center">

	|V4.1.1|V4.2.1|
	|:------:|:------:|
	|I2C|AUX|
	|AUX|AUX2|
	</div>

3. Changing 4 pin J7 symbol to 5 pin with pin connections:
	<div align="center">

	|J7 Pins| Connected to |
	|:------:|:------:|
	|1|7V5DC|
	|2|GND1|
	|3|GND2|
	|4|SCL|
	|5|SDA|

	</div>

##### Patch Changes
1. Changing U5 symbol as fixed stepdown to adjustable stepdown

2. Changing references:
	<div align="center">

	|V4.1.1|V4.2.1|
	|:------:|:------:|
	|D2|D3|
	|D3|D2|
	</div>

#### :zap: PCB:
##### Patch Changes
1. AUX's ground plane separated from main ground plane
2. Dimension of 92 mm x 75 mm with edge cuts layer

<a name="V4.1.1"></a>

# V4.1.1
#### Creator: Mr. Haidar
### :package: Description

Versi 4.1.1

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
##### Major Changes
1. Adding U6 with value OUT-7,5V as power source of 2.5 V sensor and its support components:

	<div align="center">

	| Symbol | Value |
	|:------:|:------:|
	|D2|1N5835|
	|L2|33 uH|
	|C9|680 uF|
	|C10|330 uF|
	|R11|1k|
	|R12|1k|
	|R13|390|
	|CFF1|1.5 nF|

	</div>

##### Minor Changes
1. Changing L1 value to 47 uH 

##### Patch Changes

1. Changing References:

	<div align="center">

	| V3.1.1 | V4.1.1 |
	|:------:|:------:|
	|1N5401|D1|
	|1N5825|D3|
	|LM2596T-5|U5|
	|ATMega328|U1|
	|AMS1117|U2|
	|C1|C7|
	|C2|C5|
	|C3|C2|
	|C5|C6|
	|C6|C1|
	|BufferSD1|U4|
	|VDCIn1|J12|
	|Battery1|J10|
	|SwitchSlot1|J11|
	|R7|R4|
	|R5|R8|
	|R6|R9|
	|R1|R5|
	|R2|R6|
	|R3|R10|
	|I2C1|J7|
	|Nextion1|J8|
	|AUX1|J9|
	|T6|J6|
	|T5|J5|
	|T4|J4|
	|T3|J3|
	|T2|J2|
	|T1|J1|

	</div>

2. Changing value of LM2596T-5 to OUT-5V

3. Changing pin connections:

	- J7
		<div align="center">

		|J7 PINS| V3.1.1 | V4.1.1 |
		|:------:|:------:|:------:|
		|1|5VDC|7V5DC|

		</div>

	- J9
		<div align="center">

		|J9 PINS| V3.1.1 | V4.1.1 |
		|:------:|:------:|:------:|
		|1|5VDC|7V5DC|
		|3|AUX2|AUX1|
		|4|AUX1|AUX2|

		</div>

	- PCA9548A
		<div align="center">

		|PCA9548A PINS| V3.1.1 | V4.1.1 |
		|:------:|:------:|:------:|
		|9 (SD0)|SDA4|unconnected|
		|10 (SC0)|SCL4|unconnected|
		|11 (SD1)|SDA3|unconnected|
		|12 (SC1)|SCL3|unconnected|
		|13 (SD2)|SDA0|SDA2|
		|14 (SC2)|SCL0|SCL2|
		|17 (SD4)|SDA2|SDA0|
		|18 (SC4)|SCL2|SCL0|
		|21 (SD6)|unconnected|SDA3|
		|22 (SC6)|unconnected|SCL3|
		|23 (SD7)|unconnected|SDA4|
		|24 (SC7)|unconnected|SCL4|

		</div>

#### :zap: PCB:
##### Major Changes
1. Changing dimension to 92.00 mm x 75.00 mm with edge cuts

##### Patch Changes 
1. Changing layout
2. Adding 1 mounting hole 
3. Chaging hole position with reference to the top-left corner, with the socket positioned in the bottom-right corner

<a name="V3.1.1"></a>

# V3.1.1
#### Creator: Mr. Haidar
### :package: Description

Versi 3.1.1

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
##### Major Changes
1. Breakdown U5 step down DC-DC module to IC and its support components:

	<div align="center">

	| Symbol | Value |
	|:------:|:------:|
	|LM2596T-5|LM2596T-5|
	|1N5824|1N5824|
	|C7|680 uF|
	|C8|220 uF|
	|L1|47 uH|

	</div>

2. Changing symbol and footprint of 2 pin VDCIn1 symbol to 3 pin Jack DC symbol 
##### Patch Changes
1. Changing references
	
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

2. Changing pin connections
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

		|Nextion1 PINS| V2.1.1 | V3.1.1 |
		|:------:|:------:|:------:|
		|2|5VDC|GND|
		|1|GND|5VDC|

		</div>
		
4. Delete all units of values
3. Change footprint of Battery1 from vertical JST to horizontal JST 

#### :zap: PCB:
##### Major Changes
1. Changing layout as the impact of step down breakdown
2. Changing dimension to 91.00 mm x 65.50 mm

##### Minor Changes
1. Changing hole position

<a name="V2.1.1"></a>

# V2.1.1
#### Creator: Mr. Haidar
### :package: Description

Versi 2.1.1

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
##### Patch Changes
1. Changing References

	<div align="center">

	| V2.0.0 | V2.1.1 |
	|:------:|:------:|
	|U1|ATMEGA328P|
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

2. Changing Values

	<div align="center">

	| V2.0.0 | V2.1.1 |
	|:------:|:------:|
	|74VHC125M|IC-SD|
	|Next|Nextion|

	</div>

3. Changing Pin Connection
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
3. Changing dimension to 94.23 mm x 75.00 mm

##### Patch Changes
1. Changing references, values, nets, and footprints corresponds to schematics
2. Adding ground plane

<a name="V2.0.0"></a>

# V2.0.0
#### Creator: Mr. Haidar
### :package: Description

Versi 2 

### :clipboard: Characteristics
#### :hammer_and_wrench: Schematic:
1. Changing the wiring method from using green wires to global labels
2. Changing symbols, references, and values of all components
3. Changing pin connections between components
4. Assigning new footprint to the new symbols
5. Adding component symbol `74VHC125M` to support data storage to the SD card

#### :zap: PCB:
1. Changing dimension to 93.88 mm x 75,00 mm
2. Changing layout
3. Eliminating dedicated port for uploading program

<a name="V1.0.0"></a>

# V1.0.0 (First printed version)
#### Creator: Mr. Rustanto
### :package: Description

The legacy system version of Fania Ersa's PCB that has features:
1. 6 probes of temperature measurement based on HTU21D
2. 1 Human Machine Interface using Nextion NX4827K043
3. 1 x micro SD slot to store measurement data 
4. Rechargeable device using 12V/2A adapter

### :clipboard: Characteristics

#### :hammer_and_wrench: Schematic:
1. Uses green colored wire to connect between components
#### :zap: PCB:
1. Dimension is 128.5 mm x 74.3 mm
2. Dedicated port for uploading program