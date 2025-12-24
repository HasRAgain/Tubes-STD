# 🎶 Tubes- STD: Program Pemutar Musik Sederhana
## Deskripsi Program
Program Pemutar musik adalah aplikasi sederhana yang dibuat menggunakan bahasa C++. Program ini mengimplementasikan struktur data Double Linked List dan Multi Linked List untuk mengelola:
1. Akun pengguna
2. Library Lagu
3. Playlist
4. Relasi akun-playlist
5. Relasi plyalist-lagu

Program ini menggunakan tipe multi linked list M-N
![Desain tanpa judul](https://github.com/user-attachments/assets/c1d7c78c-c599-41e4-ad7c-44b1a1f34a0e)


Program mendukung dua jenis pengguna, yaitu admin dan user, dengan hak akses yang berbeda
## 🔗Struktur Data yang Digunakan
### Double Linked List
- List akun
- List lagu
- List playlist
- List playlistToAkun
- List PlaylistToLagu 

Setiap node memiliki pointer: prev <- data -> next
### Multi Linked List
- PlaylistToAkun --> menghubungkan akun dengan playlist
- PlaylistToLagu --> menghubungkan playist dengan lagu

## 👥 Jenis Pengguna
### 🔑 Admin
Admin memiliki akses penuh terhadap library lagu
#### Fitur Admin
1. Menambahkan lagu
2. Melihat semua lagu
3. Mengedit data lagu
4. Menghapus lagu (otomatis terhapus dari semua playlist)
5. Melihat seluruh akun
### 👤 User
User dapat mengelola playlist, memutar lagu, dan update akunnya
#### Fitur User
1. Melihat library lagu
2. Mencari lagu berdasarkan judul
3. Memutar lagu dari library
4. Memutar lagu dari playlist
5. Mengelola playlist:
 - Membuat playlist
 - Menghapus playlist
 - Menampilkan playlist
 - Menambahkan lagu ke playlist
 - Menghapus lagu dari playlist
 - Mengubah nama playlist
6. Melihat playlist milik akun lain
7. Update akun (username & password sendiri)
## 🎧🎶 Fitur Pemutar Lagu ⏮️⏭️
### ▶️ Play dari Library
User dapat memutar lagu sebelum maupun selanjutnya atau berhenti dengan menggunakan navigasi:
- p --> lagu sebelumnya
- n --> lagu selanjutnya
- s --> stop
### ▶️ Play dari Library
Lagu diputar berdasarkan urutan dalam playlist. Navigasi yang digunakan sama dengan play lagu dari library. 

## 📂Struktur File
```text
📁 Tubes-STD
│
├── 📁 pemutarMusik
│   ├── main.cpp
│   ├── pemutarMusik.cpp
│   └── pemutarMusik.h
│
└──README.md
```
## Data Dummy
Terdapat tiga user:
1. rai - admin
2. hasna - user
3. irfan - user

terdapat tiga playlist
1. asik
2. nostalgic
3. mixed

terdapat 15 lagu di dalam library

## ⚙️ Cara Menjalankan Program 
1. Pastikan compiler C++ tersedia (contoh: g++)
2. Comple program
``` text
g++ main.cpp pemutarMusik.cpp -o Tubes-STD
```
3. Jalankan
``` text
.\pemutarMusik
