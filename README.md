# BABY INCUBATOR TESTER
Proyek ini merupakan kerjasama antara PT. Hana Master Jaya dan PT. Fania Ersa Pratama untuk membuat suatu alat yang digunakan di bidang medis dengan fungsi untuk mengkalibrasi inkubator bayi.

# KOMPATIBILITAS VERSI
<sup>Untuk detail panduan pengelolaan versi [klik disini.](Panduan_Pengelolaan_Versi.md)</sup>

Berikut pasangan versi yang diimplementasikan untuk menghasilkan kinerja alat yang optimal.

| Versi Perangkat |                                 Elektrik                                 |                                     HMI                                      | Koding                                                                    | Mekanik |
|:---------------:|:------------------------------------------------------------------------:|:----------------------------------------------------------------------------:|---------------------------------------------------------------------------|---------|
|   Belum Rilis   | [V5.0.0](Hardware_Development/02_Schematics_and_PCB/PCB_Utama.md#v500-belum-dirilis) | [V3.0.0](Hardware_Development/04_Nextion_HMI/Kode_HMI.md#v300-belum-dirilis) | [V4.0.0](Hardware_Development/03_Code/Kode_Arduino.md#v400-belum-dirilis) | -       |
|     Versi 4     |                                    -                                     |                                      -                                       | -                                                                         | -       |
|     Versi 3     |                                    -                                     |                                      -                                       | -                                                                         | -       |
|     Versi 2     |                                    -                                     |                                      -                                       | -                                                                         | -       |
|     Versi 1     |                                    -                                     |                                      -                                       | -                                                                         | -       |


Untuk dokumentasi skematik dan PCB bisa [klik disini](Hardware_Development/02_Schematics_and_PCB/PCB_Utama.md)!

Untuk dokumentasi koding Arduino bisa [klik disini](Hardware_Development/03_Code/Kode_Arduino.md)!

Untuk dokumentasi UI dari HMI Nextion bisa [klik disini](Hardware_Development/04_Nextion_HMI/Desain_HMI.md)!



## Struktur Direktori Proyek

```bash
project/
│
├── Assembly and Instructions/          # Dokumen untuk produksi
│ ├── 01_Working_Instruction/           # Instruksi untuk produksi
│ └── 02_Checklists/                    # Inspeksi komponen produksi
│
├── Design and Research/                # Data-data terkait riset dalam pengembangan
│ ├── 01_Design_Documents/              # Data rujukan riset dan pengembangan
│ └── 02_Research_Notes/                # Perhitungan nilai komponen
│
├── Final Documentations/               # Dokumentasi terkait pengguna akhir
│ ├── 01_Final_Reports/                 # Laporan akhir setelah produksi
│ ├── 02_User_Manual/                   # Panduan pengguna
│ └── 03_Additional_Resources/          # Sumber tambahan
│
├── Hardware Development/               # Pengembangan terkait perangkat keras
│ ├── 01_BoM_List/                      # Harga pembelian komponen
│ ├── 02_Schematics_and_PCB/            # Desain komponen elektronik
│ ├── 03_Code/                          # Kode firmware untuk PCB
│ └── 04_Nextion_HMI/                   # Desain dan kode untuk HMI
│
├── Past Documents/                     # Data terdahulu sebelum Mei 2023
│
├── Project Management/                 # Manajemen proyek Data-data terkait riset dalam pengembangan
│ ├── 01_Project_Plan/                  # Perencanaan pengerjaan proyek
│ ├── 02_Meetings/                      # Rapat dalam pengerjaan proyek
│ └── 03_Documents/                     # Dokumen terkait manajemen proyek seperti MoM
│
├── Testing and Validation/             # Data-data terkait hasil uji
│ ├── 01_Battery_Testing/               # Data uji baterai
│ ├── 02_Device_Testing/                # Data uji perangkat
│ └── 03_QC_Reports/                    # Laporan QC
│ 
└── README.md # Informasi proyek secara umum, kamu lagi disini!
```
- - - -



