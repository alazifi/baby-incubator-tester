# DOKUMENTASI DESAIN HMI
<sup>Switch to English? [Click here!](HMI_Design.md)</sup>

## Log Versi
- [V3.0.0](#v300-belum-dirilis)
- [V2.1.0](#v210)
- [V2.0.0](#v200)
- [V2.0.0](#v200)
- [V1.0.0](#v100) 

- - - -

# V3.0.0 (belum dirilis)
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang:
- Haidar
- Ayu (menambahkan dukungan untuk halaman `loadingPage` dan `startup`)
  
## Diubah
- **Perubahan besar:** Mengubah metode akuisisi data dari `wavefrom` menjadi `line` dinamis
- **Perubahan besar:** Memisahkan 4 resolusi pengambilan sampel data 
- Mengubah tata letak halaman `startup`
- Mengubah tampilan memuat level baterai menggunakan `...` saat memuat

## Ditambahkan
- Menambahkan halaman `loadingPage` animasi
- Menambahkan 4 tata letak untuk mendukung 4 mode pengambilan sampel data  
- Menambahkan halaman `trendSpeed` untuk memilih interval waktu pengambilan sampel data

- - - -

# V2.1.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Haidar

## Diperbaiki
- Memperbaiki warna sorot dalam pengaturan waktu 

## Ditambahkan
- Menambahkan tombol akses ke halaman `wiringGuide2` di halaman `windSound`
- Menambahkan tombol akses ke halaman `placementGuide2` di halaman `wiringGuide2`
- Menambahkan ikon indikator pengisian daya
- Menambahkan nilai sumbu X dan Y pada grafik suhu
- Menambahkan indikator warna pengukuran suhu

## Berubah
- Mengubah desain halaman `startup`
- Mengubah tata letak tombol pada halaman `home`
- Mengubah `batLev` sebagai indikator baterai dari `local vscope` menjadi `global vscope`
- Mengubah format waktu dari 2 baris menjadi 1 baris `dd/mm/yyyy HH:MM:ss`
- Mengubah tampilan satuan pengukuran pada judul yang sesuai, tidak lagi ada di kotak nilai
- Mengubah nilai terendah penggeser menjadi 0% dengan kecerahan 20%.

## Dihapus
- Menghapus ikon yang tidak perlu

- - - -

# V2.0.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Haidar
## Diubah
- **Perubahan besar:** Mengubah tata letak antarmuka dan tema warna sepenuhnya
- **Perubahan besar:** Gambar-gambar di panel `Picture` dikhususkan untuk satu halaman atau satu halaman efek per gambar, bukan untuk ikon
- **Perubahan besar:** Halaman-halaman di panel `Page` diganti namanya menjadi sesuai dengan fungsinya
- Mengubah nilai terendah penggeser menjadi 20% dengan kecerahan 20%
- Mengubah tampilan waktu dari berjalan menjadi beku saat pengguna menyesuaikan pengaturan waktu

## Ditambahkan
- **Perubahan besar:** Menambahkan opsi untuk menangkap tren suhu dan streaming saja

## Dihapus
- Menghapus fitur indikator pengisian daya
- Menghapus fitur indikator baterai lemah

- - - -

# V1.0.0
<sup>[(Kembali ke atas)](#log-versi)</sup>

#### Pengembang: Rustanto
### :package: Deskripsi
Desain pertama yang dibuat untuk mendukung antarmuka pengguna Baby Incubator Tester.