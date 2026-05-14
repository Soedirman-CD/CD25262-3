## Logbook Kelompok 3

Mata kuliah: Capstone Design

Semester: Genap 2025/2026

Anggota

1. Mahasiswa: @gdysidik
2. Mahasiswa: @dikaaditya486-cyber
3. Mahasiswa: @aliyakp05

### 30 April 2026

#### Yang sudah dilakukan

- Pembelian sensor pzem004t.
- Pembelian hilink 220 VAC-5 VDC converter.

#### Masalah yang dihadapi

- Belum ada.

#### Yang akan dilakukan

- [ ] Melengkapi pembelian barang. PIC: @aliyakp05
- [ ] Merancang program pengujian sensor. PIC: @gdysidik

#### Catatan

- Belum ada :drooling_face:

### 04 Mei 2026

#### Yang sudah dilakukan

- Melengkapi pembelian komponen baik online maupun offline.
- Testing kirim data dari ESP32 ke Google Sheets.

#### Masalah yang dihadapi

- Ada beberapa barang yang ingin dicari offline tetapi ternyata tidak tersedia/habis.
- Ada tambahan pembelian barang yaitu panel box.
- Delay cukup besar saat kirim data.

#### Yang akan dilakukan

- [x] Membeli panel box. PIC: @aliyakp05
- [ ] Mencari kembali barang yang tidak tersedia ke toko lain. PIC: @dikaaditya486-cyber dan @gdysidik

#### Catatan

- Kirim data ke Google Sheets baik data konstan maupun variabel sudah berhasil tetapi masih ada kendala.

### 6 Mei 2026

#### Yang sudah dilakukan

- Membeli panel box.

### Masalah yang dihadapi

- Ukuran panel box yang sesuai cukup sulit ditemui.

#### Yang akan dilakukan

- [ ] Membeli lcd i2c. PIC: @aliyakp05
- [ ] Mencari kembali barang yang tidak tersedia ke toko lain. PIC: @dikaaditya486-cyber dan @gdysidik

#### Catatan

- Nothing :grimacing:

### 8 Mei 2026

### Yang sudah dilakukan

- Merencanakan placement.

### Masalah yang dihadapi

- Masih belum menemukan placement yang sesuai dengan ukuran panel box.

#### Yang akan dilakukan

- [ ] Menentukan placement yang sesuai dengan ukuran panel box. PIC: @all
- [x] Membeli MCB dan skun. PIC: @dikaaditya486-cyber

#### Catatan

- Nothing :grimacing:

### 9 Mei 2026

#### Yang sudah dilakukan

- Membeli MCB 4 A.
- Membuat PCB daya dan PCB kontrol.
- Tes koneksi tiap jalur pada PCB dengan menggunakan multimeter.

#### Masalah yang dihadapi

- PCB daya dan kontrol terlalu besar sehingga memakan ruang di dalam panel box.

#### Yang akan dilakukan

- [ ] Menyesuaikan ukuran PCB daya dengan memotong bagian sisa semaksimal mungkin. PIC: @gdysidik
- [x] _Wiring_ komponen untuk pengujian. PIC: @all

#### Catatan

- PCB kontrol juga sisa banyak, tapi _space_-nya bisa digunakan untuk tempat _current transformer_.

### 11 Mei 2026

#### Yang sudah dilakukan

- Membuat dashboard monitoring 

#### Masalah yang dihadapi

- Masih belom mengetahui batas limit database

#### Yang akan dilakukan

- [ ] Menyempurnakan dashboard agar sesuai dengan dashboard monitoring. PIC: @dikaaditya486-cyber
- [ ] Pengujian dashboard. PIC : @all

#### Catatan

- Nothing :grimacing:

### 12 Mei 2026

#### Yang sudah dilakukan

- _Wiring_ komponen untuk pengujian sensor.

#### Masalah yang dihadapi

- Konektor AC gosong :sweat_smile: :upside_down_face:.
- Sensor tidak menerima command dari ESP32 ketika menggunakan input daya terpisah/beda sumber.

#### Yang akan dilakukan

- [x] Pengujian Sensor PZEM. PIC : @all
- [x] Mengatur ulang rangkaian daya ESP32 dan komunikasi sensor lewat satu jalur (laptop) agar serial monitor terpantau.
- [x] _Wiring_ bagian beban agar sensor bisa melakukan metering.

#### Catatan

- Selalu pastikan mengecek dulu biar semua aman :ghost:.


### 13 Mei 2026

#### Yang sudah dilakukan

- _Wiring_ bagian beban.
- Mengatur ulang rangkaian daya ESP32 dan komunikasi sensor lewat satu jalur (laptop) agar serial monitor terpantau.
- Menguji sensor PZEM-004T.

#### Masalah yang dihadapi

- Kabel bagian beban sedikit kurang terancang dengan baik sehingga _current transformer_ sulit terinstal.

#### Yang akan dilakukan

- [ ] Rekonstruksi _wiring_ bagian beban.
- [ ] Mulai _wiring_ komponen yang disesuaikan dengan panel box.

#### Catatan

- Pengujian sensor berhasil dengan hasil sebagai berikut:

|               BEBAN              | TEGANGAN TERUKUR (V) | ARUS TERUKUR (A) | DAYA TERUKUR (W) |
|:---------------------------------|---------------------:|-----------------:|-----------------:|
| Charger 10 Wdc                   | 236.6                | 0.04             | 4.8              |
| Charger 10 Wdc + Charger 45 Wdc  | 235.3                | 0.34             | 45.6             |
| Solder                           | 236.5                | 0.13             | 31.1             |

Lampiran output pengujian:
![output testPZEM_1](output_testPZEM_1.png)

<!-- ### 25 Nov 2025

#### Yang sudah dilakukan

#### Masalah yang dihadapi

#### Yang akan dilakukan

#### Catatan

### 02 Des 2025

#### Yang sudah dilakukan

#### Masalah yang dihadapi

#### Yang akan dilakukan

#### Catatan

### 09 Des 2025

#### Yang sudah dilakukan

#### Masalah yang dihadapi

#### Yang akan dilakukan

#### Catatan --> -->
