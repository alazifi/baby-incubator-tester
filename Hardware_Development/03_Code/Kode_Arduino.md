# DOKUMENTASI KODING ARDUINO
<sup>Switch to English? [Click here!](Arduino_Code.md)</sup>

## Log Versi
- [V4.0.0](#v400-belum-dirilis)
- [V3.0.0](#v300)
- [V2.1.0](#v210)
- [V2.0.0](#v200)
- [V1.1.0](#v110)
- [V1.0.0](#v100) 

- - - -

# V4.0.0 (belum dirilis)
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Haidar
## Ditambahkan
- **Perubahan besar:** Menambahkan pin `sensIndicator`
- **Perubahan besar:** Menambahkan pin `limiter`

- - - -

# V3.0.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Haidar
## Diubah
- **Perubahan besar:** Mengubah metode penghitungan dari `metode pemetaan` menjadi `metode konversi analog ke digital` untuk fungsi `soundLevel()` dan `airSpeed()` 
- Mengubah nilai awal `count` dari `-3` menjadi `-4`
- Mengubah nomor pin `CS` dari `4` menjadi `10`
- Mengubah waktu pembaruan data pertama ke HMI Nextion menjadi `8000 ms` setelah perangkat dinyalakan
- Mengubah interval waktu untuk menyimpan data dari `3000 ms` menjadi `1000 ms`
- Mengubah alamat SPI `HTU21D`
- Mengubah logika dalam fungsi `dataCore()` mengikuti nilai `count`

## Ditambahkan
- Menambahkan pustaka `"ADS1X15.h"` untuk mengantarmuka sensor `AUX`
- Menambahkan variabel dengan tipe `unsigned long` 
- Menambahkan variabel `logTime`
- Menambahkan karakter khusus `\n` ke fungsi `dataLable()`

## Dihapus
- Menghapus pustaka `"MultiMap.h"`

- - - -

# V2.1.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Haidar
## Diubah
- Mengubah nilai awal `count` menjadi `-3`
- Mengubah variabel global `dataFile` menjadi variabel lokal
- Mengubah baud rate dari `9600` menjadi `115200`
- Mengubah alamat SPI `HTU21D`
- Mengubah tipe data `soundLevel` dari `int` menjadi `byte`
- Mengubah tipe data `airSpeed` dari `int` menjadi `float`
- Mengganti semua nama fungsi yang memperbarui data pengukuran ke HMI Nextion dari `updateXX` menjadi `upXX`

## Ditambahkan
- Menambahkan variabel integer `batVal` dengan nilai `409` sebagai nilai default pengendali kesalahan baterai
- Menambahkan variabel `unsigned long` untuk menangani waktu interval untuk memperbarui data yang ditampilkan ke Nextion selama `1000 ms` dan menulis data ke kartu SD selama `3000 ms`
- Menggabungkan beberapa fungsi pembaruan HMI untuk setiap sensor menjadi satu fungsi `printNextion()`
- Menambahkan 6 fungsi untuk menangani proses pencarian suhu maksimum HTU21D `mTempX()` dan fungsi pembaruan HMI `upMaxTempX()`
- Menambahkan alternatif logika untuk metode pelevelan baterai
- Nilai default sembarang untuk `airSpeed()`
- Menambahkan fungsi `upBatLev()` untuk memperbarui persentase baterai
- Menambahkan fungsi `upChgState()` untuk menunjukkan proses pengisian daya
- Menambahkan fungsi tipe char `decToChar()`, `intToChar()`, dan `strToChar()` untuk mendukung pemrosesan karakter
- Menambahkan fungsi tipe char `dataHeader()`, `dataLable()`, `dataCore()` dan `timestamp()` untuk mendukung penulisan data ke Kartu SD

## Dihapus
- Menghapus fungsi `chgFlag()`

- - - -

# V2.0.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Haidar
## Diubah
- **Perubahan besar:** Mengganti nama semua variabel, konstanta dan fungsi
- **Perubahan besar:** Mengubah beberapa variabel menjadi fungsi
## Dihapus
- Menghapus pustaka `"String.h"`
- Menghapus beberapa variabel dan fungsi

- - - -

# V1.1.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Haidar
## Diubah
- Mengganti penggunaan variabel untuk `konstanta string header` dengan string literal langsung di `Serial.println()` untuk mengoptimalkan penggunaan memori dan meningkatkan efisiensi kode.
- Mengoptimalkan penggunaan memori dengan beralih dari `metode penggabungan string` ke `MyFile.print()` untuk penulisan data kartu SD

## Dihapus
- Menghapus fungsi `floatToString()`

- - - -

# V1.0.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Rustanto
### :package: Deskripsi

Kode pertama yang dibuat untuk mendukung perangkat PCB yang memiliki fitur:
1. Mengukur 6 suhu dalam Celcius, 1 kelembapan dalam %RH, dan nilai maksimumnya, serta tingkat kebisingan dalam dB dan aliran udara dalam m/s
2. Menampilkan hasil pengukuran ke HMI Nextion setiap `6000 ms`
3. Menyimpan hasil pengukuran ke Kartu SD setiap `3000 ms`
4. Indikator level baterai