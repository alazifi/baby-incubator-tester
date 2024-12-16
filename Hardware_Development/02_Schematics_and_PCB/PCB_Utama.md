# DOKUMENTASI PCB UTAMA
<sup>Switch to English? [Click here!](Main_PCB.md)</sup>

## Log Versi
- [V5.0.0](#v500-belum-dirilis)
- [V4.3.0](#v430)
- [V4.2.0](#v420-versi-tercetak-kedua)
- [V4.1.0](#v410)
- [V4.0.0](#v400)
- [V3.0.0](#v300)
- [V2.1.0](#v210)
- [V2.0.0](#v200)
- [V1.0.0](#v100-versi-tercetak-pertama) 

- - - -

# V5.0.0 (belum dirilis)
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Haidar
### :package: Deskripsi
Perangkat yang lebih andal diperkenalkan dalam versi ini:
1. Memusatkan daya semua komponen ke dalam satu sumber daya `5VDC`, sehingga sensor `7,5 VDC` tidak lagi diperkenalkan di versi ini.
2. Menambahkan indikator koneksi sensor `AUX` yang berguna untuk pekerjaan pengguna.
3. Sakelar daya yang lebih ramah pengguna yang memberi tahu Anda bahwa perangkat dihidupkan/dimatikan
4. Memperkenalkan penghemat baterai yang akan mematikan perangkat sebelum batas daya baterai terendah untuk menjaga kinerja dan efisiensi baterai. Menjadikan perangkat Anda didukung oleh baterai yang tahan lama.

### :clipboard: Karakteristik
#### :hammer_and_wrench: Skematika:
##### Perubahan Major
1. Mengubah modul stepdown `U6` menjadi modul `ADS1115` untuk memusatkan daya pada satu module stepdown dan mendukung pembacaan sensor `AUX`
2. Mengubah `J10` 2 pin menjadi `J10` 3 pin untuk mendukung fungsi lampu indikator dari tombol saklar
3. Menambahkan resistor *pull up* `R11` dengan nilai `10k` pada pin 14 `U1` (`PB0`) untuk mendukung fitur indikator koneksi sensor `AUX` pada `J8`
4. Menambahkan fitur pembatas daya dengan komponen: 
	- Simbol `Q1` dengan nilai `BD140`
		- Basis sebagai trigger dari pin input 15 `U1` (`PB1`) 
		- Emitor sebagai `5VDCB`
		- Kolektor sebagai `5VDCL`
	- Simbol `R12` dengan nilai `200` sebagai resistor basis
5. Kabel `5VDC` dibagi menjadi:
	- `5VDCB` untuk komponen yang tidak terpengaruh oleh pembatas daya
	- `5VDCL` untuk komponen yang terpengaruh oleh pembatas daya

##### Perubahan Minor
1. Mengubah koneksi pin dari `J8`:
	| PIN `J8` | V4.2.0  |      V5.0.0      |
	|:--------:|:-------:|:----------------:|
	|    1     | `75VDC` |     `GAIN1`      |
	|    2     |  `GND`  |     `GAIN0`      |
	|    3     |  `GND`  | `Sens_Indicator` |
	|    4     |  `SCL`  |      `GND`       |
	|    5     |  `SDA`  |     `5VDCL`      |
2. Mengubah tata letak teks
3. Changed connections
	- `U1`
		|  `U1` PINS  | V4.2.0 | V5.0.0  |
		|:-----------:|:------:|:-------:|
		|  7 (`VCC`)  | `5VDC` | `5VDCB` |
		| 20 (`AVCC`) | `5VDC` | `5VDCB` |
	- `5VDC` connection at pin 3 `U2` (`VI`) to `5VDCL`
	- `5VDC` connection at pin 4 `U5` (`OUT+`) to `5VDCB`
4. Changed hole position 			
5. Changed value of `IC-SD` to `74HCT125`

##### Perubahan Patch:

1. Eliminated `TP4` symbol
2. Added unit for all values
3. Mengubah koneksi pin dari simbol:
	- `J7`
		| `J7` PINS | V4.2.0 | V5.0.0  |
		|:---------:|:------:|:-------:|
		|     1     | `GND`  | `5VDCL` |
		|     4     | `5VDC` |  `GND`  |
	- `PCA9548A`
		| `PCA9548A` PINS | V4.2.0 | V5.0.0 |
		|:---------------:|:------:|:------:|
		|   13 (`SD2`)    | `SDA2` | `SDA0` |
		|   14 (`SC2`)    | `SCL2` | `SCL0` |
		|   15 (`SD3`)    | `SDA1` | `SDA1` |
		|   16 (`SC3`)    | `SCL1` | `SCL1` |
		|   17 (`SD4`)    | `SDA0` | `SDA2` |
		|   18 (`SC4`)    | `SCL0` | `SCL2` |
		|   19 (`SD5`)    | `SDA5` | `SDA3` |
		|   20 (`SC5`)    | `SCL5` | `SCL3` |
		|   21 (`SD6`)    | `SDA3` | `SDA4` |
		|   22 (`SC6`)    | `SCL3` | `SCL4` |
		|   23 (`SD7`)    | `SDA4` | `SDA5` |
		|   24 (`SC7`)    | `SCL4` | `SCL5` |
1. Mengubah nilai
	|      V4.2.0      |      V4.2.0      |
	|:----------------:|:----------------:|
	| `StepDownLM2596` | `Step_Down_DCDC` |
	|      `TP3`       |      `12V`       |

- - - -

# V4.3.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Mr. Haidar
### :package: Deskripsi
Memperkenalkan 4 titik uji pada PCB dalam versi ini untuk mempersingkat waktu produksi dan inspeksi. Jadikan biaya produksi lebih berkurang pada versi ini!

### :clipboard: Karakteristik
#### :hammer_and_wrench: Skematika:
##### Perubahan Minor
1. Menambahkan 4 simbol titik uji:
	| Simbol |  Nilai  |
	|:------:|:-------:|
	| `TP1`  |  `GND`  |
	| `TP2`  |  `5 V`  |
	| `TP3`  | `7,5 V` |
	| `TP4`  | `12 V`  |

##### Perubahan Patch:
1. Mengubah referensi
	| V4.2.0 | V4.3.0 |
	|:------:|:------:|
	| `J13`  | `J12`  |
	| `J12`  | `J11`  |
	| `J10`  |  `J9`  |
	| `J11`  | `J10`  |
	|  `C2`  |  `C4`  |
	|  `C4`  |  `C5`  |
	|  `C5`  |  `C1`  |
	|  `C7`  |  `C2`  |
	|  `J8`  |  `J7`  |
	|  `J9`  |  `J8`  |
2. Mengeliminasi `J7` dengan nilai `I2C`
3. Mengubah koneksi pin dari simbol
	- `J7`
		| PIN `J7` | V4.2.0 | V4.3.0 |
		|:--------:|:------:|:------:|
		|    1     | `5VDC` | `GND`  |
		|    2     | `GND`  |  `TX`  |
		|    3     |  `TX`  |  `RX`  |
		|    4     |  `RX`  | `5VDC` |
	- `J8`
		| PIN `J8` | V4.2.0 | V4.3.0 |
		|:--------:|:------:|:------:|
		|    4     | `AUX1` | `SCL`  |
		|    5     | `AUX2` | `SDA`  |
	- Menukar label `MISO` dengan label `MISO_L`

#### :zap: PCB:
##### Perubahan Minor
1. Mengubah tata letak seperti penambahan titik uji, penghapusan komponen, penyelarasan resistor

##### Perubahan Patch
1. Mengubah tata letak teks

- - - -

# V4.2.0 (versi tercetak kedua)
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Mr. Haidar
### :package: Deskripsi
Representasi visual komponen dan PCB yang lebih realistis diperkenalkan dalam versi ini untuk menyederhanakan pemasangan pada desain mekanis. Arsitektur sumber daya pada versi ini disesuaikan untuk mengurangi biaya pembelian komponen ke dalam papan yang siap diintegrasikan ke dalam PCB.

### :clipboard: Karakteristik
#### :hammer_and_wrench: Skematika:
##### Perubahan Minor

1. Mengubah simbol:
	- Simbol IC `U5` menjadi modul stepdown `U5` dengan nilai `StepDownLM2596`
	- Simbol IC `U6` menjadi modul stepdown `U6` dengan nilai `StepDownLM2596`
2. Mengeliminasi komponen pendukung IC `U5` dan IC `U6`
3. Menyesuaikan *footprint* dari simbol `U5` dan `U6`

##### Perubahan Patch
1. Mengubah simbol:
	- `J7` 5 pin menjadi `J7` 4 pin
	- `J9` 4 pin menjadi `J9` 5 pin
2. Mengubah nilai:
	| V4.1.0 | V4.2.0 |
	|:------:|:------:|
	| `AUX`  | `I2C`  |
	| `AUX2` | `AUX`  |
3. Mengubah koneksi pin dari simbol:
	- `J7`
		| PIN `J7` | V4.1.0 | V4.2.0 |
		|:--------:|:------:|:------:|
		|    2     | `GND1` | `GND`  |
		|    3     | `GND2` | `SCL`  |
		|    4     | `SCL`  | `SDA`  |
	- `J9`
		| PIN `J9` |    V4.1.0     | V4.2.0 |
		|:--------:|:-------------:|:------:|
		|    3     |    `AUX1`     | `GND`  |
		|    4     |    `AUX2`     | `AUX1` |
		|    5     | tidak ada pin | `AUX2` |
	- `J13`
		|  PIN `J13`   |     V4.1.0      | V4.2.0 |
		|:------------:|:---------------:|:------:|
		|  1 (`DAT2`)  | tidak terhubung | `GND`  |
		| 10 (`MOUNT`) | tidak terhubung | `GND`  |
		| 11 (`MOUNT`) | tidak terhubung | `GND`  |
#### :zap: PCB:
##### Perubahan Minor
1. Mengubah tata letak
2. Mengubah dimensi menjadi 105,00 mm x 75,00 mm
3. Mengeliminasi 1 lubang
4. Menambahkan tampilan 3D untuk semua komponen

- - - -

# V4.1.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Mr. Haidar
### :package: Deskripsi
Penyempurnaan versi keempat yang mengantisipasi Interferensi Elektromagnetik dengan memisahkan *ground plane* dari `AUX` dan seluruh komponen utama.

### :clipboard: Karakteristik
#### :hammer_and_wrench: Skematika:
##### Perubahan Minor
1. Menambah komponen pendukung `U5`:
	| Symbol |  Value   |
	|:------:|:--------:|
	| `R14`  |  `330`   |
	|  `C8`  |  `470`   |
	| `R15`  |   `1k`   |
	| `CFF2` | `3.3 nF` |
2. Mengubah nilai:
	| V4.0.0 | V4.1.0 |
	|:------:|:------:|
	| `I2C`  | `AUX`  |
	| `AUX`  | `AUX2` |
3. Mengubah simbol `J7` 4 pin menjadi 5 pin dengan koneksi:
	| PIN `J7` | Terhubung ke |
	|:--------:|:------------:|
	|    1     |   `7V5DC`    |
	|    2     |    `GND1`    |
	|    3     |    `GND2`    |
	|    4     |    `SCL`     |
	|    5     |    `SDA`     |
##### Perubahan Patch
1. Mengubah simbol `U5` sebagai stepdown keluaran tetap menjadi stepdown dengan keluaran yang bisa disesuaikan
2. Mengubah referensi:
	| V4.0.0 | V4.1.0 |
	|:------:|:------:|
	|  `D2`  |  `D3`  |
	|  `D3`  |  `D2`  |
#### :zap: PCB:
##### Perubahan Patch
1. *Ground plane* `AUX` terpisah dari *ground* utama
2. Dimensi 92,00 mm x 75,00 mm dengan potongan tepi *edge-cuts*

- - - -

# V4.0.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Mr. Haidar
### :package: Deskripsi
Lebih banyak sumber daya untuk sensor ditambahkan dan didedikasikan untuk memberi daya pada sensor di *Baby Incubator Tester* versi keempat ini. Peningkatan ini memungkinkan peningkatan kinerja sensor dan meningkatkan kerjanya!

### :clipboard: Karakteristik
#### :hammer_and_wrench: Skematika:
##### Perubahan Major
1. Menambahkan simbol `U6` dengan nilai `OUT-7,5V` sebagai sumber daya sensor `7.5 V` dan komponen-komponen pendukungnya:
	| Simbol |  Nilai   |
	|:------:|:--------:|
	|  `D2`  | `1N5835` |
	|  `L2`  | `33 uH`  |
	|  `C9`  | `680 uF` |
	| `C10`  | `330 uF` |
	| `R11`  |   `1k`   |
	| `R12`  |   `1k`   |
	| `R13`  |  `390`   |
	| `CFF1` | `1.5 nF` |
##### Perubahan Minor
1. Mengubah nilai dari simbol `L1` menjadi `47 uH` 

##### Perubahan Patch
1. Mengubah referensi:
	|    V3.0.0     | V4.0.0 |
	|:-------------:|:------:|
	|   `1N5401`    |  `D1`  |
	|   `1N5825`    |  `D3`  |
	|  `LM2596T-5`  |  `U5`  |
	|  `ATMega328`  |  `U1`  |
	|   `AMS1117`   |  `U2`  |
	|     `C1`      |  `C7`  |
	|     `C2`      |  `C5`  |
	|     `C3`      |  `C2`  |
	|     `C5`      |  `C6`  |
	|     `C6`      |  `C1`  |
	|  `BufferSD1`  |  `U4`  |
	|   `VDCIn1`    | `J12`  |
	|  `Battery1`   | `J10`  |
	| `SwitchSlot1` | `J11`  |
	|     `R7`      |  `R4`  |
	|     `R5`      |  `R8`  |
	|     `R6`      |  `R9`  |
	|     `R1`      |  `R5`  |
	|     `R2`      |  `R6`  |
	|     `R3`      | `R10`  |
	|    `I2C1`     |  `J7`  |
	|  `Nextion1`   |  `J8`  |
	|    `AUX1`     |  `J9`  |
	|     `T6`      |  `J6`  |
	|     `T5`      |  `J5`  |
	|     `T4`      |  `J4`  |
	|     `T3`      |  `J3`  |
	|     `T2`      |  `J2`  |
2. Mengubah nilai dari simbol `LM2596T-5` menjadi `OUT-5V`
3. Mengubah koneksi pin dari simbol:
	- `J7`
		| PIN `J7` | V3.0.0 | V4.0.0  |
		|:--------:|:------:|:-------:|
		|    1     | `5VDC` | `7V5DC` |
	- `J9`
		| PIN `J9` | V3.0.0 | V4.0.0  |
		|:--------:|:------:|:-------:|
		|    1     | `5VDC` | `7V5DC` |
		|    3     | `AUX2` | `AUX1`  |
		|    4     | `AUX1` | `AUX2`  |
	- `PCA9548A1`
		| PIN `PCA9548A1` |     V3.0.0      |     V4.0.0      |
		|:---------------:|:---------------:|:---------------:|
		|    9 (`SD0`)    |     `SDA4`      | tidak terhubung |
		|   10 (`SC0`)    |     `SCL4`      | tidak terhubung |
		|   11 (`SD1`)    |     `SDA3`      | tidak terhubung |
		|   12 (`SC1`)    |     `SCL3`      | tidak terhubung |
		|   13 (`SD2`)    |     `SDA0`      |     `SDA2`      |
		|   14 (`SC2`)    |     `SCL0`      |     `SCL2`      |
		|   17 (`SD4`)    |     `SDA2`      |     `SDA0`      |
		|   18 (`SC4`)    |     `SCL2`      |     `SCL0`      |
		|   21 (`SD6`)    | tidak terhubung |     `SDA3`      |
		|   22 (`SC6`)    | tidak terhubung |     `SCL3`      |
		|   23 (`SD7`)    | tidak terhubung |     `SDA4`      |
		|   24 (`SC7`)    | tidak terhubung |     `SCL4`      |
#### :zap: PCB:
##### Perubahan Major
1. Mengubah dimensi menjadi 92,00 mm x 75,00 mm dengan potongan tepi *edge-cuts*

##### Perubahan Patch 
1. Mengubah tata letak
2. Menambah 1 lubang pemasangan
3. Mengubah posisi lubang dengan mengacu pada pojok kiri atas, dengan posisi soket di pojok kanan bawah

- - - -

# V3.0.0
<sup>[(Kembali ke atas)](#log-Versi)</sup>

#### Pengembang: Mr. Haidar
### :package: Deskripsi
Versi ketiga dari Baby Incubator Tester menyediakan port pengisian daya yang lebih kokoh yang memungkinkan plug and play yang lebih sederhana untuk mengisi ulang perangkat.
Perangkat ini juga mengintegrasikan komponen daya dalam satu papan sehingga menyederhanakan proses produksi massal.

### :clipboard: Karakteristik
#### :hammer_and_wrench: Skematika:
##### Perubahan Major
1. Mengurai modul stepdown DC-DC `U5` menjadi IC dan komponen  pendukungnya:
	|   Simbol    |    Nilai    |
	|:-----------:|:-----------:|
	| `LM2596T-5` | `LM2596T-5` |
	|  `1N5824`   |  `1N5824`   |
	|    `C7`     |  `680 uF`   |
	|    `C8`     |  `220 uF`   |
	|    `L1`     |   `47 uH`   |
2. Mengubah simbol dan *footprint* dari `VDCIn1` 2 pin menjadi simbol `Jack DC` 3 pin 
##### Perubahan Patch
1. Mengubah referensi
	|   V2.1.0   |    V3.0.0     |
	|:----------:|:-------------:|
	| `Nextion`  |  `Nextion1`   |
	|   `I2C`    |    `I2C1`     |
	|   `AUX`    |    `AUX1`     |
	| `BufferSD` |  `BufferSD1`  |
	| `PCA9548A` |  `PCA9548A1`  |
	|    `J1`    |   `VDCIn1`    |
	|    `J2`    |  `Battery1`   |
	|    `J3`    | `SwitchSlot1` |
	|    `U3`    |   `AMS1117`   |
2. Mengubah koneksi pin dari simbol:
	- `PCA9548A1`
		| PIN `PCA9548A1` |     V2.1.0      |     V3.0.0      |
		|:---------------:|:---------------:|:---------------:|
		|    9 (`SD0`)    | tidak terhubung |     `SDA4`      |
		|   10 (`SC0`)    | tidak terhubung |     `SCL4`      |
		|   11 (`SD1`)    | tidak terhubung |     `SDA3`      |
		|   12 (`SC1`)    | tidak terhubung |     `SCL3`      |
		|   21 (`SD6`)    |     `SDA3`      | tidak terhubung |
		|   22 (`SC6`)    |     `SCL3`      | tidak terhubung |
		|   23 (`SD7`)    |     `SDA4`      | tidak terhubung |
		|   24 (`SC7`)    |     `SCL4`      | tidak terhubung |
	- `Nextion1`
		| PIN `Nextion1` | V2.1.0 | V3.0.0 |
		|:--------------:|:------:|:------:|
		|       2        | `5VDC` | `GND`  |
		|       1        | `GND`  | `5VDC` |
3. Menghapus semua satuan nilai
4. Mengubah *footprint* `Battery1` dari JST vertical menjadi JST horizontal 

#### :zap: PCB:
##### Perubahan Major
1. Mengubah tata letak sebagai akibat dari penguraian stepdown
2. Mengubah dimensi menjadi 91,00 mm x 65,50 mm

##### Perubahan Minor
1. Mengubah posisi lubang

- - - -

# V2.1.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Mr. Haidar
### :package: Deskripsi
Penyempurnaan versi kedua yang memungkinkan pemasangan lebih kuat pada perangkat sebagai dampak penambahan 1 lubang pemasangan tambahan

### :clipboard: Karakteristik
#### :hammer_and_wrench: Skematika:
##### Perubahan Patch
1. Mengubah referensi
	| V2.0.0 |    V2.1.0    |
	|:------:|:------------:|
	|  `U1`  | `ATMEGA328P` |
	|  `U2`  |  `BufferSD`  |
	|  `U4`  |  `StepDown`  |
	|  `U5`  |  `PCA9548A`  |
	|  `J4`  |     `T6`     |
	|  `J5`  |     `T5`     |
	|  `J6`  |     `T4`     |
	|  `J7`  |     `T3`     |
	|  `J8`  |     `T2`     |
	|  `J9`  |     `T1`     |
	| `J10`  |    `I2C`     |
	| `J12`  |  `Nextion`   |
	| `J13`  |    `AUX`     |
2. Mengubah nilai
	|   V2.0.0    |  V2.1.0   |
	|:-----------:|:---------:|
	| `74VHC125M` |  `IC-SD`  |
	|   `Next`    | `Nextion` |
3. Mengubah koneksi pin dari simbol:
	- `AUX` 
		| PIN `AUX` | V2.0.0 | V2.1.0 |
		|:---------:|:------:|:------:|
		|     3     | `AUX1` | `AUX2` |
		|     4     | `AUX2` | `AUX1` |
	- `I2C`
		| PIN `I2C` | V2.0.0 | V2.1.0 |
		|:---------:|:------:|:------:|
		|     3     | `SDA`  | `SCL`  |
		|     4     | `SCL`  | `SDA`  |
	- `Nextion`
		| PIN `I2C` | V2.0.0 | V2.1.0 |
		|:---------:|:------:|:------:|
		|     1     | `5VDC` | `SCL`  |
		|     2     |  `RX`  | `5VDC` |
		|     4     | `GND`  |  `RX`  |
	- `PCA9548A`
		| PIN `PCA9548A` |     V2.0.0      |     V2.1.0      |
		|:--------------:|:---------------:|:---------------:|
		|   9 (`SD0`)    |     `SDA0`      | tidak terhubung |
		|   10 (`SC0`)   |     `SCL0`      | tidak terhubung |
		|   11 (`SD1`)   |     `SDA1`      | tidak terhubung |
		|   12 (`SC1`)   |     `SCL1`      | tidak terhubung |
		|   13 (`SD2`)   |     `SDA2`      |     `SDA0`      |
		|   14 (`SC2`)   |     `SCL2`      |     `SCL0`      |
		|   15 (`SD3`)   |     `SDA3`      |     `SDA1`      |
		|   16 (`SC3`)   |     `SCL3`      |     `SCL1`      |
		|   17 (`SD4`)   |     `SDA4`      |     `SDA2`      |
		|   18 (`SC4`)   |     `SCL4`      |     `SCL2`      |
		|   19 (`SD6`)   | tidak terhubung |     `SDA3`      |
		|   20 (`SC6`)   | tidak terhubung |     `SCL3`      |
		|   21 (`SD7`)   | tidak terhubung |     `SDA4`      |
		|   22 (`SC7`)   | tidak terhubung |     `SCL4`      |
#### :zap: PCB:
##### Perubahan Minor
1. Menambah 1 lubang untuk pemasangan
2. Menambah tata letak
3. Mengubah dimensi menjadi 94,23 mm x 75,00 mm

##### Perubahan Patch
1. Mengubah referensi, nilai, net, dan *footprint* berdasarkan skematika
2. Menambahkan *ground plane*

- - - -

# V2.0.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Mr. Haidar
### :package: Deskripsi
Baby Incubator Tester versi kedua yang memiliki fitur berikut:
1. Firmware lebih aman karena port pengembangan tidak lagi tersedia sejak versi ini diluncurkan
2. Pelacakan data lebih stabil akibat buffer kartu SD
3. Lebih mudah untuk memeriksa dokumen skematika

### :clipboard: Karakteristik
#### :hammer_and_wrench: Skematika:
1. Mengubah metode pengkabelan dari menggunakan kabel hijau menjadi label global
2. Mengubah simbol, acuan, dan nilai seluruh komponen
3. Perubahan pin koneksi antar komponen
4. Menetapkan jejak baru pada simbol baru
5. Menambahkan simbol komponen `74VHC125M` untuk mendukung penyimpanan data ke kartu SD

#### :zap: PCB:
1. Mengunah dimensi menjadi 93,88 mm x 75,00 mm
2. Mengubah tata letak
3. Menghilangkan port khusus untuk mengunggah program

- - - -

# V1.0.0 (versi tercetak pertama)
<sup>[(Kembali ke atas)](#log-versi)</sup>
#### Pengembang: Rustanto
### :package: Deskripsi

Versi sistem lama dari PCB Fania Ersa yang memiliki fitur:
1. 6 probe pengukuran suhu berbasis `HTU21D`
2. 1 Antarmuka Mesin Manusia menggunakan Nextion `NX4827K043`
3. 1 x slot micro SD untuk menyimpan data pengukuran 
4. Perangkat isi ulang menggunakan adaptor 12V/2A

### :clipboard: Karakteristik

#### :hammer_and_wrench: Skematika:
1. Menggunakan kabel berwarna hijau untuk menghubungkan antar komponen
#### :zap: PCB:
1. Dimensi PCB adalah 128,5 mm x 74,3 mm
2. Terdapat port khusus untuk mengunggah program