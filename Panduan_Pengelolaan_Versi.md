# Panduan Pengelolaan Versi

<sup>Switch to English? [Click here!](Versioning_Guide.md)</sup>

Semua perubahan penting pada proyek ini akan mengikuti panduan pengelolaan versi ini. Untuk informasi detailnya, cek [pengelolaan versi semantik](https://semver.org/lang/id/).

Pengelolaan versi semantik dalam proyek ini menggunakan format ini:
``` bash
X.Y.Z
```
yang sesuai dengan
``` bash
MAJOR.MINOR.PATCH
```
Detail:
1. **MAJOR** menunjukkan perubahan besar yang tidak kompatibel dengan versi sebelumnya.
	- Contoh: Mendesain ulang arsitektur baru dan mengubah fungsionalitas inti
	- Peningkatan versi: `1.0.0` &rarr; `2.0.0`

2. **MINOR** menunjukkan perubahan yang kompatibel dengan penambahan fitur baru
	- Contoh: Menambahkan sensor baru
	- Peningkatan versi: `1.1.0` &rarr; `1.2.0`

3. **PATCH** menunjukkan perubahan kecil yang tidak menambah fitur baru tetapi menyelesaikan masalah atau mengoptimalkan fungsi yang ada
	- Contoh: Perbaikan bug, penggantian komponen yang rusak
	- Peningkatan versi: `1.1.1` &rarr; `1.1.2`