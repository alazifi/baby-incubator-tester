# BABY INCUBATOR TESTER
Proyek ini merupakan kerjasama antara PT. Hana Master Jaya dan PT. Fania Ersa Pratama untuk membuat suatu alat yang digunakan di bidang medis dengan fungsi untuk mengkalibrasi inkubator bayi.

# KOMPATIBILITAS VERSI
Berikut pasangan versi yang diimplementasikan untuk menghasilkan kinerja alat yang optimal.

| Versi Perangkat |                                 Elektrik                                 |                                     HMI                                      | Koding                                                                    | Mekanik |
|:---------------:|:------------------------------------------------------------------------:|:----------------------------------------------------------------------------:|---------------------------------------------------------------------------|---------|
|   Belum Rilis   | [V5.0.0](Hardware_Development/02_Schematics_and_PCB/PCB_Utama.md#v500-belum-dirilis) | [V3.0.0](Hardware_Development/04_Nextion_HMI/Kode_HMI.md#v300-belum-dirilis) | [V4.0.0](Hardware_Development/03_Code/Kode_Arduino.md#v400-belum-dirilis) | -       |
|     Versi 4     |                                    -                                     |                                      -                                       | -                                                                         | -       |
|     Versi 3     |                                    -                                     |                                      -                                       | -                                                                         | -       |
|     Versi 2     |                                    -                                     |                                      -                                       | -                                                                         | -       |
|     Versi 1     |                                    -                                     |                                      -                                       | -                                                                         | -       |


Untuk dokumentasi skematik dan PCB bisa [klik disini](Hardware_Development/02_Schematics_and_PCB/Main_PCB-en.md)!

Untuk dokumentasi koding Arduino bisa [klik disini](Hardware_Development/03_Code/Arduino_Code-en.md)!

Untuk dokumentasi UI dari HMI Nextion bisa [klik disini](Hardware_Development/04_Nextion_HMI/HMI_Code-en.md)!

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

<a name="directory_structure"></a>

## Directory Structure

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



