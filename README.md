# Sisop-8-2025-IT08

## Kelompok 8

| Nama | NRP |
| ---------------------- | ---------- |
| Arya Bisma Putra Refman | 5027241036 |
| Moch. Rizki Nasrullah | 5027241038 |
| Nadia Fauziazahra Kusumastuti | 5027241094 |
----

## Daftar Isi

- [Kelompok](#kelompok)
- [Daftar Isi](#daftar-isi)
- [Soal](#soal)
- [Petunjuk Soal](#petunjuk-soal)
  - [Source](#source)
  - [Headers](#headers)
  - [Makefile](#makefile)
  - [Video Demonstrasi](#video-demonstrasi)
- [Laporan](#laporan)

## Soal

Pada suatu hari, anda merasa sangat lelah dari segala macam praktikum yang sudah ada, sehingga anda berencana untuk tidur yang nyenyak di sebuah jam 3:34AM yang cerah. Tetapi, anda terbangun di dalam dunia berbeda yang bernama "Eorzea". Ada sesuatu yang mengganggu pikiran anda sehingga anda diharuskan membuat sebuah operating system bernama "EorzeOS" untuk mendampingi diri anda dalam dunia ini.

1. Sebagai seorang main character dari dunia ini, ternyata anda memiliki kekuatan yang bernama "The Echo", kekuatan ini memungkinkan anda untuk berbicara pada Operating System ini (mungkin sebenarnya bukan ini kekuatannya, tetapi ini cukup kuat juga), dengan tujuan agar semua hal yang anda katakan, bila bukan merupakan sebuah command yang valid, akan mengulang hal yang anda katakan.

   Ilustrasi:
   ```
   user> Hello!
   Hello!
   user> I have the Echo
   I have the Echo
   ```

2. gurt: yo

   Ilustrasi:
   ```
   user> yo
   gurt
   user> gurt
   yo
   ```

3. Seorang main character memerlukan sebuah nama yang semua orang bisa ingat dengan baik. Buatlah sebuah command yang memungkinkan pengguna untuk mengubah nama user pada shell yang digunakan:
   * `user <username>` = mengubah username menjadi `<username>`
   * `user` = mengubah username menjadi default `user`
   
   Ilustrasi:
   ```
   user> user Tia
   Username changed to Tia
   Tia> user
   Username changed to user
   user>
   ```

4. Tiga negara besar dari Eorzean Alliance butuh bantuan anda untuk ikut serta dalam "Grand Company" mereka sehingga anda bisa mengubah warna terminal ajaib anda sesuai warna utama dari company mereka:
   * `grandcompany maelstrom` = clear terminal, ubah semua teks berikutnya jadi merah
   * `grandcompany twinadder` = clear terminal, ubah semua teks berikutnya jadi kuning
   * `grandcompany immortalflames` = clear terminal, ubah semua teks berikutnya jadi biru
   * `grandcompany <selain atau kosong>` = tunjukkan error message
   * `clear` = clear terminal, ubah semua teks berikutnya kembali jadi awal (para Grand Company sedih kamu netral)

   Selain mengubah seluruh warna terminal, nama anda di dalam terminal akan diberikan tambahan nama judul Grand Company:
   * Maelstrom = `user@Storm`
   * Twin Adder = `user@Serpent`
   * Immortal Flames = `user@Flame`
   * `clear` = menghapus nama grand company

   Ilustrasi:
   ```
   gurt> grandcompany maelstrom
   -- terminal clear menjadi warna merah --
   gurt@Storm> clear
   -- terminal clear menjadi warna putih --
   ```

5. Sebagai pahlawan terkenal di antara ketiga negara besar Eorzean Alliance, salah satu supplier senjata terbesar di seluruh Eorzea bernama "Rowena's House of Splendors" tiba-tiba memerlukan bantuan anda untuk membuat sebuah sistem kalkulator sederhana melalui command karena pemimpin mereka tertidur setelah mengurus semua orang di dalam Eorzea:
   * `add <x> <y>` = x + y
   * `sub <x> <y>` = x - y
   * `mul <x> <y>` = x * y
   * `div <x> <y>` = x / y

   Ilustrasi:
   ```
   user> add 4 2
   6
   user> sub 4 2
   2
   user> mul 3 -2
   -6
   user> div -6 -2
   3
   ```

6. me: yogurt
   
   gurt:
   * `yo`
   * `ts unami gng </3`
   * `sygau`

   pilih secara *random*

   Ilustrasi:
   ```
   user> yogurt
   gurt> yo
   user> yogurt
   gurt> ts unami gng </3
   user> yogurt
   gurt> sygau
   ```

8. Perusahaan mesin "Garlond Ironworks" tiba-tiba lelah mengurus permintaan senjata perang untuk orang ke-148649813234 yang berusaha menghadapi final boss yang sama, sehingga mereka perlu bantuan kamu untuk melengkapi `Makefile` yang diberikan dengan command-command yang sesuai untuk compile seluruh operating system ini.

## Petunjuk Soal

### Source

* [kernel.asm](src/kernel.asm)
  * `_putInMemory`: penjelasan terdapat dalam modul
  * `_interrupt`: fungsi untuk interrupt
    * `number`: interrupt vector number
    * `AX`,`BX`,`CX`,`DX`: register untuk diisi
    * `AX` merupakan kombinasi dari `AH` dan `AL`, pola ini juga berlaku untuk `BX`,`CX`, dan `DX`
    * Untuk menggabungkan jenis register `H` dan `L` menjadi `X` bisa menggunakan salah satu metode berikut:
      ```c
      AX = AH << 8 | AL    // first method
      AX = AH * 256 + AL   // second method
      ```
   * `getBiosTick`: fungsi untuk mendapatkan tick dari BIOS
* [kernel.c](src/kernel.c)
  * Diisi penerapan fungsi `printString`, `readString`, dan `clearScreen` dengan bantuan `kernel.asm`
    * untuk `printString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk _teletype output_. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (_null-terminated_) ke layar.
    * untuk `readString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk _keyboard input_. Fungsi ini akan membaca karakter ASCII (_non-control_) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan.
    * untuk `clearScreen`: Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video.
* [shell.c](src/shell.c)
  * Diisi penerapan shell yang menggunakan fungsi kernel untuk parsing keseluruhan command yang diinput

### Headers

* [std_type.h](include/std_type.h)
  * `byte`: unsigned char data type, untuk angka 0-255 (`0x00`-`0xFF`)
  * `bool`: untuk boolean (true/false), karena boolean tidak built-in
* [std_lib.h](include/std_lib.h)
  * `div`: division
  * `mod`: modulo
  * Pembagian dan modulo tidak ada dalam assembly, sehingga harus dilengkapi dengan operator yang tersedia (`+`,`-`,`*`,`<<`,`>>`)
  * `strcmp`: membandingkan dua string
  * `strcpy`: copy string
  * `clear`: fill memory dengan `0`
  * `atoi`: alphanumeric to integer (string menjadi angka)
  * `itoa`: integer to alphanumeric (angka menjadi string)
* [kernel.h](include/kernel.h)
  * Deklarasi header untuk fungsi-fungsi dalam `kernel.c`
* [shell.h](include/shell.h)
  * Deklarasi header untuk fungsi-fungsi dalam `shell.c`

### Makefile

* [makefile](./makefile)
   * `prepare` : membuat disk image baru `floppy.img` pada direktori `bin/` dengan ukuran 1.44 MB.
   * `bootloader` : mengkompilasi `bootloader.asm` menjadi `bootloader.bin` pada direktori `bin/`.
   * `stdlib` : mengkompilasi `std_lib.c` menjadi `std_lib.o` pada direktori `bin/`.
   * `shell`: mengkompilasi `shell.c` menjadi `shell.o` pada direktori `bin/`.
   * `kernel` : mengkompilasi `kernel.c` menjadi `kernel.o` pada direktori `bin/` dan mengkompilasi `kernel.asm` menjadi `kernel_asm.o` pada direktori `bin/`.
   * `link` : menggabungkan `bootloader.bin`, `kernel.o`, `kernel_asm.o`, dan `std_lib.o` menjadi `floppy.img`.
   * `build` : menjalankan perintah `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link`.

### Video Demonstrasi

[Akses Video dalam Assets](./assets/demo.mp4)

https://github.com/user-attachments/assets/1cfa66b1-b2f5-4e3e-a4b2-ec8b012f6fbb


## Laporan

A. include
1. shell.h
```bash
#ifndef __SHELL_H__
#define __SHELL_H__

#include "std_type.h"

void shell();
void parseCommand(char *buf, char *cmd, char arg[2][64]);
void printPrompt();

extern char username[64];
extern char grandcompany[16];
extern char color;

#endif // __SHELL_H__
```
- `#ifndef __SHELL_H__` memeriksa apakah simbol `__SHELL_H__` belum didefinisikan.
- Jika belum didefinisikan, `#define __SHELL_H__` mendefinisikan simbol tersebut, dan kode di antara `#ifndef` dan `#endif` akan di proses.
- Jika simbol sudah didefinisikan (karena file sudah di-include sebelumnya), kompiler akan mengabaikan isi file ini.
- Meng-include file header `std_type.h` yang mendefinisikan tipe data kustom seperti `byte (unsigned char)` dan `bool (char, dengan nilai true dan false)` dengan tujuan memberikan akses ke tipe data yang diperlukan oleh fungsi-fungsi dalam `shell.h`, seperti `bool` yang digunakan dalam fungsi seperti `strcmp` di modul lain (`std_lib.c`).
- `void shell();`
  - Mendeklarasikan fungsi `shell` yang merupakan fungsi utama untuk menjalankan shell interaktif `EorzeOS`.
  - Fungsi ini bertanggung jawab untuk menampilkan prompt, membaca input pengguna, mem-parsing perintah, dan menjalankan aksi sesuai perintah seperti `user`, `grandcompany`, `clear`, atau operasi aritmatika (`add`, `sub`, `mul`, `div`).
  - Tidak memiliki parameter atau nilai kembalian (`void`) karena berjalan dalam loop tak terbatas untuk menangani input pengguna.
- `void parseCommand(char *buf, char *cmd, char arg[2][64]);`
  - Mendeklarasikan fungsi parseCommand yang mem-parsing string input pengguna menjadi perintah (cmd) dan hingga dua argumen (arg[0] dan arg[1]).
  - Parameter:
    - `char *buf`: Buffer yang berisi string input pengguna.
    - `char *cmd`: Buffer untuk menyimpan perintah yang diambil dari input (misalnya, "user", "add").
    - `char arg[2][64]`: Array dua dimensi untuk menyimpan hingga dua argumen, masing-masing maksimal 64 karakter.
  - Fungsi ini memisahkan input berdasarkan spasi dan menyimpan hasilnya untuk diproses lebih lanjut oleh shell.
- `void printPrompt();`
  - Mendeklarasikan fungsi `printPrompt` yang menampilkan prompt shell seperti `user>` atau `user@Storm>` tergantung pada nama pengguna dan afiliasi Grand Company.
  - Tidak memiliki parameter atau nilai kembalian karena hanya menampilkan teks ke layar.
- `extern char username[64];`
  - Mendeklarasikan variabel global username, sebuah array karakter berukuran 64 byte untuk menyimpan nama pengguna (default: "user").
  - Kata kunci extern menunjukkan bahwa variabel ini didefinisikan di file lain (misalnya, `shell.c`) dan hanya dideklarasikan di sini untuk digunakan di file lain yang meng-include `shell.h`.
  - Digunakan untuk menyimpan nama pengguna yang dapat diubah melalui perintah `user <username>` atau direset ke "user" dengan perintah user.
- `extern char grandcompany[16];`
  - Mendeklarasikan variabel global `grandcompany`, sebuah array karakter berukuran 16 byte untuk menyimpan nama afiliasi Grand Company (misalnya, "`Storm`", "`Serpent`", atau "`Flame`").
  - Variabel ini diatur oleh perintah `grandcompany <company>` dan dihapus oleh perintah `clear`.
  - Juga bersifat extern, didefinisikan di `shell.c`.
- `extern char color;`
  - Mendeklarasikan variabel global `color`, sebuah variabel bertipe char untuk menyimpan kode warna terminal (misalnya, `0x07` untuk putih, `0x04` untuk merah, `0x0E` untuk kuning, `0x01` untuk biru).
  - Digunakan untuk mengatur warna teks terminal berdasarkan perintah `grandcompany` atau `clear`.
- `#endif` memastikan bahwa kode di dalam `#ifndef __SHELL_H__` hanya di proses sekali selama kompilasi

2. std_type.h
```bash
#ifndef __STD_TYPE_H__
#define __STD_TYPE_H__

typedef unsigned char byte;

typedef char boolean;
typedef char bool;
#define true 1
#define false 0

#endif // __STD_YPE_H__
```
- `typedef unsigned char byte;`
  - Mendefinisikan tipe data kustom byte sebagai alias untuk `unsigned char`.
    - `unsigned char` adalah tipe data 8-bit (1 byte) yang dapat menyimpan nilai dari 0 hingga 255 (`0x00` hingga `0xFF`).
    - Tipe byte digunakan untuk operasi yang memerlukan manipulasi data pada level rendah, seperti pengisian memori video (misalnya, dalam fungsi `clearScreen` di `kernel.c`) atau pengelolaan buffer dalam `std_lib.c`.
    - Memberikan nama yang lebih deskriptif dan konsisten untuk operasi berbasis byte, meningkatkan keterbacaan kode dan kompatibilitas dengan kebutuhan sistem operasi.
- `typedef char boolean;` dan `typedef char bool;`
  - Baris ini mendefinisikan dua tipe data kustom, `boolean` dan `bool`, sebagai alias untuk `char`.
    - Dalam C, tipe data `boolean` atau `bool` tidak tersedia secara bawaan (tidak seperti di C++ atau bahasa lain), sehingga perlu didefinisikan secara eksplisit untuk sistem operasi ini.
    - Keduanya menggunakan `char` (8-bit) untuk menyimpan nilai `boolean` yang nantinya diwakili oleh konstanta `true` (1) dan `false` (0).
    - Penggunaan dua nama (boolean dan bool) bertujuan untuk fleksibilitas atau kompatibilitas dengan konvensi penamaan yang berbeda di berbagai modul dan menyediakan tipe data untuk operasi logika, seperti perbandingan string (`strcmp` di `std_lib.c`) atau pengambilan keputusan dalam logika `shell`.
- `#define true 1` dan `#define false 0`
  - Baris ini mendefinisikan dua konstanta makro, true dan false, untuk mewakili nilai boolean.
    - `#define true 1` menetapkan nilai 1 sebagai representasi logika "benar".
    - `#define false 0` menetapkan nilai 0 sebagai representasi logika "salah".
    - Konstanta ini digunakan bersama tipe `boolean` atau `bool` untuk operasi logika, misalnya dalam fungsi `strcmp` di `std_lib.c` yang mengembalikan `true` jika dua string sama dan `false` jika berbeda.
    - Bertujuan untuk memberikan cara standar untuk menangani logika boolean dalam kode, serta memastikan konsistensi dan keterbacaan.

B. src
1. kernel.c
```bash
#include "../include/shell.h"
#include "../include/kernel.h"

extern char color;

int main() {
    clearScreen();
    shell();
}

void printString(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        interrupt(0x10, 0x0E00 | str[i], 0, 0, 0);
        i++;
    }
}


void readString(char *buf) {
    int index = 0;
    char c;
    do {
        c = (char)interrupt(0x16, 0x0000, 0, 0, 0);
        
        if (c == 0x0D) {
            buf[index] = '\0';
            interrupt(0x10, 0x0E00 | '\r', 0, 0, 0); 
            interrupt(0x10, 0x0E00 | '\n', 0, 0, 0); 
            break;
        } else if (c == 0x08 && index > 0) {
            index--;
            interrupt(0x10, 0x0E00 | 0x08, 0, 0, 0);
            interrupt(0x10, 0x0E00 | ' ', 0, 0, 0);
            interrupt(0x10, 0x0E00 | 0x08, 0, 0, 0);
        } else if (c >= 0x20 && index < 127) {
            buf[index] = c;
            index++;
            interrupt(0x10, 0x0E00 | c, 0, 0, 0);
        }
    } while (true);
}

void clearScreen() {
    int i;
    for (i = 0; i < 80 * 25 * 2; i += 2) {
        putInMemory(0xB800, i, ' ');
        putInMemory(0xB800, i + 1, color);
    }
    interrupt(0x10, 0x0200, 0, 0, 0);
}
```
- `#include "../include/shell.h" dan #include "../include/kernel.h"`
  - Meng-include file header `shell.h` dan `kernel.h` untuk menyediakan deklarasi fungsi dan variabel yang diperlukan.
    - `shell.h` mendeklarasikan fungsi `shell()` dan variabel seperti `username`, `grandcompany`, dan `color`.
    - `kernel.h` mendeklarasikan fungsi seperti `_putInMemory`, `_interrupt`, `_getBiosTick`, serta fungsi lokal `printString`, `readString`, dan `clearScreen`.
    - Path `../include/` menunjukkan lokasi file header di direktori include relatif terhadap `src`.
    - Bertujuan untuk memungkinkan akses ke fungsi dan variabel dari modul lain.
- `extern char color;`
  - Mendeklarasikan variabel global `color` sebagai variabel eksternal yang didefinisikan di `shell.c`.
    - Variabel ini menyimpan kode warna terminal (misalnya, 0x07 untuk putih, 0x04 untuk merah) untuk pengaturan atribut teks di memori video VGA.
    - Digunakan oleh `clearScreen` untuk mengatur warna layar sesuai status `shell`.
    - Bertujuan untuk menjaga konsistensi warna antar modul `kernel` dan `shell`.
- `int main() { clearScreen(); shell(); }`
  - Mendefinisikan fungsi `main` sebagai titik masuk `kernel` setelah `bootloader` memuat `kernel` ke memori.
    - Memanggil `clearScreen()` untuk mengosongkan layar teks `80x25` dan mengatur kursor ke `(0,0)`.
    - Memanggil `shell()` untuk memulai loop interaktif `shell`, memungkinkan interaksi pengguna.
    - Dideklarasikan sebagai `int`, akan tetapi tidak mengembalikan nilai karena berjalan di lingkungan bare-metal tanpa sistem operasi yang menangani nilai kembalian.
    - Bertujuan untuk menginisialisasi sistem dan memulai antarmuka pengguna.
- `void printString(char *str) { ... }`
  - Mendefinisikan fungsi `printString` untuk menampilkan `string` ke layar menggunakan `BIOS interrupt 0x10` (mode teletype).
    - Parameter `char *str` adalah pointer ke string yang diakhiri null (\0).
    - `Loop while (str[i] != '\0')` mengiterasi setiap karakter dan memanggil `interrupt(0x10, 0x0E00 | str[i], 0, 0, 0)` untuk menampilkan karakter ke layar.
    - `Interrupt 0x10` dengan `AH=0x0E` menulis karakter di `AL (str[i])` ke layar tanpa mengubah posisi kursor.
    - Bertujuan untuk menyediakan fungsi penulisan teks, digunakan oleh `shell` untuk menampilkan prompt, pesan, atau hasil perintah.
- `void readString(char *buf) { ... }`
  - Mendefinisikan fungsi `readString` untuk membaca input pengguna dari keyboard ke buffer.
    - Parameter `char *buf` adalah buffer untuk menyimpan string input (maksimal 127 karakter).
    - Menggunakan `interrupt(0x16, 0x0000, 0, 0, 0)` untuk membaca karakter dari keyboard (`BIOS interrupt 0x16, AH=0x00`).
    - Menangani tiga kasus:
      - `Enter (0x0D)`: Menambahkan null terminator, menampilkan carriage return dan newline, lalu keluar.
      - `Backspace (0x08)`: Menghapus karakter terakhir dari buffer dan layar jika buffer tidak kosong.
      - `Karakter printable (0x20 hingga 0x7E)`: Menyimpan karakter ke buffer dan menampilkannya ke layar jika buffer belum penuh.
    - Bertujuan untuk mendukung input pengguna, seperti perintah `shell (add 4 2)`.
- `void clearScreen() { ... }`
  - Mendefinisikan fungsi `clearScreen` untuk mengosongkan layar teks VGA dan mengatur kursor.
    - Loop `for (i = 0; i < 80 * 25 * 2; i += 2)` mengisi memori video (`0xB800`) dengan spasi (' ') dan atribut warna (`color`).
    - Setiap karakter menggunakan 2 byte (karakter dan atribut), sehingga i += 2 mengakses pasangan karakter-atribut.
    - Memanggil `interrupt(0x10, 0x0200, 0, 0, 0)` untuk mengatur kursor ke (0,0).
    - Bertujuan untuk menginisialisasi atau mengosongkan layar yang digunakan saat `boot` atau perintah `clear`.

2. std_lib.c
```bash
#include "../include/std_lib.h" 
#include "../include/std_type.h"

int div(int a, int b) {
  int quotient = 0;
  int sign = 1;

  if (a < 0) {
    a = -a;
    sign = -sign;
  }
  if (b < 0) {
    b = -b;
    sign = -sign;
  }

  while (a >= b) {
    a -= b;
    quotient++;
  }

  return sign * quotient;
}

int imod(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (a >= b) a -= b;
    return a;
}


bool strcmp(char *str1, char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) return false;
    i++;
  }
  return str1[i] == str2[i];
}

void strcpy(char *dst, char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
}

void clear(byte *buf, unsigned int size) {
  int i;
  for (i = 0; i < size; i++) {
    buf[i] = 0;
  }
}

void atoi(char *str, int *num) {
  int result = 0;
  int sign = 1;
  int i = 0;

  if (str[0] == '-') {
    sign = -1;
    i++;
  }

  while (str[i] != '\0') {
    result = result * 10 + (str[i] - '0');
    i++;
  }

  *num = sign * result;
}

void itoa(int num, char *str) {
  int i = 0;
  int sign = 0;
  int temp = num;

  if (num < 0) {
    sign = 1;
    num = -num;
  }

  do {
    str[i++] = imod(num, 10) + '0';   
    num = div(num, 10);             
  } while (num > 0);

  if (sign) {
    str[i++] = '-';
  }

  str[i] = '\0';

  // Reverse string
  {
    int start = 0;
    int end = i - 1;
    char c;
    while (start < end) {
      c = str[start];
      str[start] = str[end];
      str[end] = c;
      start++;
      end--;
    }
  }
}
```
- `#include "../include/std_lib.h" dan #include "../include/std_type.h"`
  - Meng-include file header `std_lib.h` dan `std_type.h` untuk menyediakan deklarasi fungsi dan tipe data yang diperlukan.
    - `std_lib.h` mendeklarasikan fungsi-fungsi seperti `div`, `imod`, `strcmp`, `strcpy`, `clear`, `atoi`, dan `itoa` yang diimplementasikan dalam file ini.
    - `std_type.h` mendefinisikan tipe data kustom seperti `byte`, `boolean`, `bool`, serta konstanta `true` dan `false` yang digunakan dalam fungsi seperti `strcmp` (mengembalikan bool) dan `clear` (menggunakan byte).
    - Path `../include/` menunjukkan lokasi file header di direktori include relatif terhadap direktori `src`.
    - Bertujuan untuk memastikan akses ke deklarasi fungsi dan tipe data yang konsisten di seluruh sistem operasi `EorzeOS`.
- `int div(int a, int b) { ... }`
  - Mendefinisikan fungsi `div` untuk melakukan pembagian `integer` dengan menghasilkan hasil bagi (`quotient`).
    - Parameter `int a` adalah pembilang dan `int b` adalah penyebut.
    - Variabel `sign` melacak tanda hasil (positif atau negatif) berdasarkan tanda input.
    - Mengubah a dan b menjadi positif jika negatif, lalu menggunakan loop `while (a >= b)` untuk mengurangi b dari a dan menambah `quotient` hingga a lebih kecil dari b.
    - Mengembalikan `sign * quotient` untuk memperhitungkan tanda asli input.
    - Bertujuan untuk mendukung operasi pembagian dalam perintah `shell` seperti `div 10 2` yang menghasilkan 5.
- `int imod(int a, int b) { ... }`
  - Mendefinisikan fungsi `imod` untuk menghitung sisa (modulus) dari pembagian integer.
    - Parameter `int a` adalah pembilang dan `int b` adalah penyebut.
    - Mengubah a dan b menjadi positif jika negatif, lalu menggunakan loop `while (a >= b)` untuk mengurangi b dari a hingga a lebih kecil dari b.
    - Mengembalikan nilai a yang tersisa sebagai hasil `modulus`.
    - Bertujuan untuk mendukung operasi modulus yang digunakan dalam fungsi `itoa` untuk mengonversi digit integer ke karakter.
- `bool strcmp(char *str1, char *str2) { ... }`
  - Mendefinisikan fungsi `strcmp` untuk membandingkan dua string dan mengembalikan nilai `bool` (`true` jika sama, `false` jika berbeda).
    - Parameter `char *str1` dan `char *str2` adalah pointer ke string yang akan dibandingkan.
    - Loop `while (str1[i] != '\0' && str2[i] != '\0')` memeriksa karakter pada indeks i dari kedua string; jika berbeda, mengembalikan false.
    - Setelah loop, memeriksa apakah kedua string berakhir bersamaan `(str1[i] == str2[i])`, mengembalikan true jika sama, false jika tidak.
    - Bertujuan untuk mendukung perbandingan string di shell, misalnya memeriksa apakah perintah adalah `user` atau `grandcompany`.
- `void strcpy(char *dst, char *src) { ... }`
  - Mendefinisikan fungsi `strcpy` untuk menyalin string dari sumber ke tujuan.
    - Parameter `char *dst` adalah buffer tujuan, dan `char *src` adalah string sumber.
    - Loop `while (src[i] != '\0')` menyalin setiap karakter dari src ke dst, lalu menambahkan null terminator (\0) di akhir.
    - Bertujuan untuk mendukung operasi penyalinan string, digunakan di `shell` untuk mengatur `username` atau `grandcompany`.
- `void clear(byte *buf, unsigned int size) { ... }`
  - Mendefinisikan fungsi `clear` untuk mengosongkan buffer dengan mengisi semua byte dengan nilai 0.
    - Parameter `byte *buf` adalah pointer ke buffer, dan `unsigned int size` adalah ukuran buffer dalam byte.
    - Loop `for (i = 0; i < size; i++)` mengatur setiap byte di buf ke 0.
    - Menggunakan tipe `byte` dari `std_type.h` untuk manipulasi data tingkat rendah.
    - Bertujuan untuk menginisialisasi buffer, digunakan di `parseCommand` untuk mengosongkan `cmd` dan `arg` sebelum parsing.
- `void atoi(char *str, int *num) { ... }`
  - Mendefinisikan fungsi `atoi` untuk mengonversi `string` ke `integer`.
    - Parameter `char *str` adalah string yang berisi angka (misalnya, "123" atau "-123"), dan `int *num` adalah pointer untuk menyimpan hasil konversi.
    - Memeriksa tanda negatif (-) untuk menentukan `sign`, lalu mengiterasi karakter untuk membangun nilai integer dengan mengalikan result dengan 10 dan menambahkan digit (str[i] - '0').
    - Menyimpan hasil akhir (`sign * result`) ke `*num`.
    - Bertujuan untuk mendukung konversi input string ke angka, digunakan di shell untuk operasi seperti `add 4 3`.
- `void itoa(int num, char *str) { ... }`
  - Mendefinisikan fungsi `itoa` untuk mengonversi `integer` ke `string`.
    - Parameter `num` adalah angka yang akan dikonversi, dan `char *str` adalah buffer untuk menyimpan string hasil.
    - Menangani tanda negatif dengan variabel `sign` dan mengubah `num` menjadi positif jika negatif.
    - Loop `do-while` menggunakan `imod(num, 10)` untuk mendapatkan `digit` dan `div(num, 10)` untuk memproses digit berikutnya, menyimpan karakter `digit` ke str`.
    - Menambahkan tanda - jika diperlukan dan null terminator (\0).
    - Membalikkan string menggunakan loop `while (start < end)` untuk mendapatkan urutan digit yang benar.
    - Bertujuan untuk mendukung konversi angka ke string untuk output `shell`, misalnya menampilkan hasil operasi `add 4 2`.

3. shell.c
```bash
#include "../include/shell.h"
#include "../include/kernel.h"
#include "../include/std_lib.h"

char username[64] = "user";
char grandcompany[16] = "";
char color = 0x07; 

static char *random_responses[] = {"yo", "ts unami gng </3", "sygau"};

void shell() {
    char buf[128];
    char cmd[64];
    char arg[2][64];
    int random_index;

    printString("Welcome to EorzeOS!\r\n");
    while (true) {
        printPrompt();
        readString(buf);

        parseCommand(buf, cmd, arg);

        if (strcmp(cmd, "user") == true) {
            if (arg[0][0] == '\0') {
                strcpy(username, "user");
                printString("Username changed to user\n");
            } else {
                strcpy(username, arg[0]);
                printString("Username changed to ");
                printString(username);
                printString("\n");
            }
        } else if (strcmp(cmd, "grandcompany") == true) {
            if (strcmp(arg[0], "maelstrom") == true) {
                strcpy(grandcompany, "Storm");
                color = 0x04; // Merah
                clearScreen();
            } else if (strcmp(arg[0], "twinadder") == true) {
                strcpy(grandcompany, "Serpent");
                color = 0x0E; // Kuning
                clearScreen();
            } else if (strcmp(arg[0], "immortalflames") == true) {
                strcpy(grandcompany, "Flame");
                color = 0x01; // Biru
                clearScreen();
            } else {
                printString("Invalid Grand Company\n");
            }
        } else if (strcmp(cmd, "clear") == true) {
            strcpy(grandcompany, "");
            color = 0x07; // Putih
            clearScreen();
        } else if (strcmp(cmd, "add") == true) {
            int x, y, result;
            char result_str[16];
            atoi(arg[0], &x);
            atoi(arg[1], &y);
            result = x + y;
            itoa(result, result_str);
            printString(result_str);
            printString("\n");
        } else if (strcmp(cmd, "sub") == true) {
            int x, y, result;
            char result_str[16];
            atoi(arg[0], &x);
            atoi(arg[1], &y);
            result = x - y;
            itoa(result, result_str);
            printString(result_str);
            printString("\n");
        } else if (strcmp(cmd, "mul") == true) {
            int x, y, result;
            char result_str[16];
            atoi(arg[0], &x);
            atoi(arg[1], &y);
            result = x * y;
            itoa(result, result_str);
            printString(result_str);
            printString("\n");
        } else if (strcmp(cmd, "div") == true) {
            int x, y, result;
            char result_str[16];
            atoi(arg[0], &x);
            atoi(arg[1], &y);
            if (y == 0) {
                printString("Division by zero\n");
            } else {
                result = div(x, y);
                itoa(result, result_str);
                printString(result_str);
                printString("\n");
            }
        } else if (strcmp(cmd, "yogurt") == true) {
            random_index = imod(getBiosTick(), 3);
            printString(random_responses[random_index]);
            printString("\n");
        } else if (strcmp(cmd, "yo") == true) {
            printString("gurt\n");
        } else if (strcmp(cmd, "gurt") == true) {
            printString("yo\n");
        } else {
            printString(buf);
            printString("\n");
        }
    }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
    int i = 0, j = 0, arg_idx = 0;
    clear((byte *)cmd, 64);
    clear((byte *)arg[0], 64);
    clear((byte *)arg[1], 64);

    while (buf[i] == ' ') i++;

    while (buf[i] != ' ' && buf[i] != '\0' && j < 63) {
        cmd[j] = buf[i];
        i++;
        j++;
    }
    cmd[j] = '\0';

    while (buf[i] == ' ') i++;

    j = 0;
    while (buf[i] != ' ' && buf[i] != '\0' && j < 63) {
        arg[0][j] = buf[i];
        i++;
        j++;
    }
    arg[0][j] = '\0';

    while (buf[i] == ' ') i++;

    j = 0;
    while (buf[i] != ' ' && buf[i] != '\0' && j < 63) {
        arg[1][j] = buf[i];
        i++;
        j++;
    }
    arg[1][j] = '\0';
}

void printPrompt() {
printString("\r\n");
printString(username);
    if (grandcompany[0] != '\0') {
        printString("@");
        printString(grandcompany);
    }
    printString("> ");
}
```
- `#include "../include/shell.h"`, `#include "../include/kernel.h"`, dan `#include "../include/std_lib.h"`
  - Meng-include file header `shell.h`, `kernel.h`, dan `std_lib.h` untuk menyediakan deklarasi fungsi, variabel, dan tipe data yang diperlukan.
    - `shell.h` mendeklarasikan fungsi seperti `shell`, `parseCommand`, `printPrompt`, serta variabel global `username`, `grandcompany`, dan `color`.
    - `kernel.h` mendeklarasikan fungsi seperti `_putInMemory`, `_interrupt`, `_getBiosTick`, `printString`, `readString`, dan `clearScreen`.
    - `std_lib.h` mendeklarasikan fungsi seperti `div`, `imod`, `strcmp`, `strcpy`, `clear`, `atoi`, dan `itoa`.
    - Path `../include/` menunjukkan lokasi file header di direktori include relatif terhadap direktori `src`.
    - Bertujuan untuk memastikan akses ke fungsi dan tipe data dari modul lain dalam sistem operasi `EorzeOS`.
- `char username[64] = "user";`
  - Mendefinisikan dan menginisialisasi variabel global `username` sebagai array karakter berukuran 64 byte dengan nilai awal "user".
    - Digunakan untuk menyimpan nama pengguna yang ditampilkan di prompt `shell`, dapat diubah melalui perintah `user <username>` atau direset ke "user".
    - Deklarasi ini sesuai dengan `extern char username[64]` di `shell.h` yang memungkinkan akses lintas modul.
    - Bertujuan untuk menyimpan status nama pengguna yang memengaruhi tampilan prompt.
- `char grandcompany[16] = "";`
  - Mendefinisikan dan menginisialisasi variabel global `grandcompany` sebagai array karakter berukuran 16 byte dengan nilai awal string kosong.
    - Menyimpan nama afiliasi Grand Company (misalnya, "`Storm`", "`Serpent`", "`Flame`"), diatur melalui perintah `grandcompany <company>` atau dihapus dengan `clear`.
    - Sesuai dengan `extern char grandcompany[16]` di `shell.h` untuk akses lintas modul.
    - Bertujuan untuk menyimpan status afiliasi pengguna yang memengaruhi warna terminal dan prompt.
- `char color = 0x07;`
  - Mendefinisikan dan menginisialisasi variabel global `color` sebagai variabel bertipe `char` dengan nilai awal `0x07` (kode warna putih untuk teks VGA).
    - Digunakan untuk mengatur warna teks di memori video, diubah oleh perintah seperti `grandcompany` (misalnya, `0x04` untuk merah) atau `clear` (kembali ke `0x07`).
    - Sesuai dengan `extern char color` di `shell.h` dan `kernel.c` untuk sinkronisasi warna antar modul.
    - Bertujuan untuk menyimpan status warna terminal.
- `static char *random_responses[] = {"yo", "ts unami gng </3", "sygau"};`
  - Mendefinisikan array `statis random_responses` yang berisi tiga pointer ke string untuk respons acak saat perintah `yogurt` dieksekusi.
    - Kata kunci static memastikan array hanya terlihat dalam `shell.c` dan tetap ada selama program berjalan.
    - String seperti "`yo`", "`ts unami gng </3`", dan "`sygau`" adalah respons yang ditampilkan secara acak berdasarkan nilai dari `getBiosTick`.
    - Bertujuan untuk memberikan fitur interaktif di `shell`.
- `void shell() { ... }`
  - Mendefinisikan fungsi `shell` sebagai inti dari antarmuka pengguna `EorzeOS`, menjalankan loop interaktif untuk memproses perintah.
    - Menampilkan pesan selamat datang ("Welcome to EorzeOS!") saat dimulai.
    - Loop `while (true)` memanggil `printPrompt` untuk menampilkan prompt, `readString` untuk membaca input, dan `parseCommand` untuk mem-parsing input menjadi `cmd` dan `arg`.
    - Mendukung perintah seperti:
      - `user`: Mengubah username ke argumen atau reset ke "user".
      - `grandcompany`: Mengatur grandcompany dan color berdasarkan argumen (misalnya, "maelstrom" untuk merah).
      - `clear`: Mengosongkan grandcompany dan mengatur color ke putih.
      - `add`, `sub`, `mul`, `div`: Melakukan operasi aritmatika dengan mengonversi argumen menggunakan atoi, menghitung hasil, dan menampilkan dengan itoa.
      - `yogurt`: Menampilkan respons acak dari random_responses berdasarkan imod(getBiosTick(), 3).
      - `yo dan gurt`: Menampilkan respons sederhana untuk interaksi lucu.
      - Lainnya: Mengembalikan input pengguna sebagai output (`echo`).
    - Bertujuan untuk menyediakan antarmuka interaktif yang mendukung pengaturan pengguna, operasi aritmatika, dan fitur lainnya.
- `void parseCommand(char *buf, char *cmd, char arg[2][64]) { ... }`
  - Mendefinisikan fungsi `parseCommand` untuk mem-parsing input pengguna menjadi perintah dan hingga dua argumen.
    - Parameter `char *buf` adalah buffer input, `char *cmd` menyimpan perintah, dan `char arg[2][64]` menyimpan hingga dua argumen.
    - Menggunakan `clear` untuk mengosongkan `cmd` dan `arg` sebelum parsing.
    - Mengiterasi buf untuk mengekstrak perintah dan argumen, mengabaikan spasi, dan menambahkan null terminator (\0) di akhir setiap string.
    - Memastikan `cmd` dan `arg` tidak melebihi 63 karakter untuk mencegah overflow.
    - Bertujuan untuk mempermudah pemrosesan input pengguna dengan struktur yang jelas.
- `void printPrompt() { ... }`
  - Mendefinisikan fungsi `printPrompt` untuk menampilkan prompt `shell` berdasarkan status `username` dan `grandcompany`.
    - Menampilkan `newline (\r\n)`, diikuti oleh `username`.
    - Jika `grandcompany` tidak kosong, menampilkan "`@`" dan nama `grandcompany`.
    - Mengakhiri dengan "`> `" sebagai indikator input.
    - Contoh: `user>` atau `user@Storm>` tergantung pada status.
    - Bertujuan untuk memberikan indikator visual yang jelas kepada pengguna untuk memasukkan perintah.

C. Makefile
```bash
all: build

prepare:
	mkdir -p bin
	dd if=/dev/zero of=bin/floppy.img bs=512 count=2880

bootloader:
	nasm -f bin src/bootloader.asm -o bin/bootloader.bin

stdlib:
	bcc -ansi -c src/std_lib.c -o bin/std_lib.o

shell:
	bcc -ansi -c src/shell.c -o bin/shell.o

kernel:
	nasm -f as86 src/kernel.asm -o bin/kernel_asm.o
	bcc -ansi -c src/kernel.c -o bin/kernel.o

link:
	ld86 -o bin/kernel.bin -d bin/kernel.o bin/kernel_asm.o bin/shell.o bin/std_lib.o
	dd if=bin/bootloader.bin of=bin/floppy.img bs=512 count=1 conv=notrunc
	dd if=bin/kernel.bin of=bin/floppy.img bs=512 seek=1 conv=notrunc

build: prepare bootloader stdlib shell kernel link

clean:
	rm -rf bin/

run: build
```
- `all: build`
  - Mendefinisikan target all sebagai target default yang akan dijalankan jika perintah make dipanggil tanpa argumen.
    - Target ini bergantung pada target build, sehingga menjalankan make akan memicu eksekusi target build.
    - Bertujuan untuk menyediakan titik masuk utama yang sederhana untuk membangun seluruh sistem operasi EorzeOS.
- `prepare:`
  - Mendefinisikan target prepare untuk menyiapkan lingkungan build.
    - Perintah mkdir -p bin membuat direktori bin jika belum ada (-p mencegah error jika direktori sudah ada).
    - Perintah dd if=/dev/zero of=bin/floppy.img bs=512 count=2880 membuat file image floppy disk (bin/floppy.img) berukuran 1,44 MB (2880 sektor x 512 byte per sektor) dengan mengisi semua byte dengan nol.
    - Bertujuan untuk menginisialisasi direktori output dan membuat image floppy kosong sebagai wadah untuk bootloader dan kernel.
- `bootloader:`
  - Mendefinisikan target bootloader untuk mengompilasi file bootloader.
    - Perintah nasm -f bin src/bootloader.asm -o bin/bootloader.bin menggunakan assembler NASM untuk mengompilasi file src/bootloader.asm ke format biner (-f bin) dan menghasilkan output bin/bootloader.bin.
    - File bootloader adalah kode assembly yang dimuat pertama kali oleh BIOS untuk memulai sistem operasi, biasanya menempati sektor pertama (512 byte) dari floppy disk.
    - Bertujuan untuk menghasilkan file biner bootloader yang siap ditulis ke image floppy.
- `stdlib:`
  - Mendefinisikan target stdlib untuk mengompilasi pustaka standar (std_lib.c).
    - Perintah bcc -ansi -c src/std_lib.c -o bin/std_lib.o menggunakan kompiler BCC (Bruce's C Compiler) dengan standar ANSI (-ansi) untuk mengompilasi file src/std_lib.c ke file objek (-c) bernama bin/std_lib.o.
    - File std_lib.c berisi fungsi-fungsi seperti div, imod, strcmp, strcpy, clear, atoi, dan itoa yang mendukung operasi shell.
    - Bertujuan untuk menghasilkan file objek dari pustaka standar untuk digunakan saat linking.
- `shell:`
  - Mendefinisikan target shell untuk mengompilasi modul shell (shell.c).
    - Perintah bcc -ansi -c src/shell.c -o bin/shell.o menggunakan BCC dengan standar ANSI untuk mengompilasi file src/shell.c ke file objek bin/shell.o.
    - File shell.c berisi logika antarmuka pengguna, seperti memproses perintah user, grandcompany, dan operasi aritmatika.
    - Bertujuan untuk menghasilkan file objek dari modul shell untuk digunakan saat linking.
- `kernel:`
  - Mendefinisikan target kernel untuk mengompilasi kernel, yang terdiri dari kode assembly dan C.
    - Perintah nasm -f as86 src/kernel.asm -o bin/kernel_asm.o menggunakan NASM untuk mengompilasi file src/kernel.asm ke format objek AS86 (-f as86), menghasilkan bin/kernel_asm.o. Format AS86 kompatibel dengan kompiler BCC untuk arsitektur 16-bit.
    - Perintah bcc -ansi -c src/kernel.c -o bin/kernel.o mengompilasi file src/kernel.c ke file objek bin/kernel.o menggunakan BCC.
    - File kernel.asm berisi fungsi tingkat rendah seperti _interrupt dan _putInMemory, sedangkan kernel.c berisi fungsi seperti main, printString, readString, dan clearScreen.
    - Bertujuan untuk menghasilkan file objek dari kernel untuk digunakan saat linking.
- `link:`
  - Mendefinisikan target link untuk menggabungkan file objek menjadi kernel biner dan menulisnya ke image floppy.
    - Perintah ld86 -o bin/kernel.bin -d bin/kernel.o bin/kernel_asm.o bin/shell.o bin/std_lib.o menggunakan linker LD86 untuk menggabungkan file objek (kernel.o, kernel_asm.o, shell.o, std_lib.o) ke file biner bin/kernel.bin. Opsi -d memungkinkan penggunaan simbol yang belum didefinisikan (berguna untuk debugging).
    - Perintah dd if=bin/bootloader.bin of=bin/floppy.img bs=512 count=1 conv=notrunc menulis bootloader.bin ke sektor pertama image floppy tanpa memotong file (conv=notrunc).
    - Perintah dd if=bin/kernel.bin of=bin/floppy.img bs=512 seek=1 conv=notrunc menulis kernel.bin mulai dari sektor kedua (seek=1) image floppy.
    - Bertujuan untuk menghasilkan image floppy yang berisi bootloader dan kernel, siap dijalankan pada emulator seperti Bochs atau QEMU.
- `build: prepare bootloader stdlib shell kernel link`
  - Mendefinisikan target build yang bergantung pada target prepare, bootloader, stdlib, shell, kernel, dan link.
    - Menjalankan semua target dependensi secara berurutan untuk membangun sistem operasi lengkap.
    - Bertujuan untuk menyediakan target utama untuk mengotomatiskan seluruh proses build, dari persiapan hingga pembuatan image floppy.
- `clean:`
  - Mendefinisikan target clean untuk menghapus hasil build.
    - Perintah rm -rf bin/ menghapus direktori bin beserta semua isinya (file objek, biner, dan image floppy).
    - Bertujuan untuk membersihkan lingkungan build, memungkinkan pembangunan ulang dari awal tanpa sisa file lama.
- `run: build`
  - Mendefinisikan target run yang bergantung pada target build.
    - Tidak ada perintah eksplisit di target ini, menunjukkan bahwa target ini mungkin dimaksudkan untuk menjalankan emulator (misalnya, Bochs atau QEMU) tetapi belum diimplementasikan sepenuhnya.
    - Dalam konteks sebelumnya, Anda menggunakan bochs -f bochsrc.txt untuk menjalankan image floppy, yang perlu ditambahkan ke target ini untuk fungsi lengkap.
    - Bertujuan untuk menyediakan target untuk membangun dan langsung menjalankan sistem operasi, meskipun saat ini hanya memicu build.

D. Hasil Demo
[Akses Video dalam Assets](./assets/20250603-0259-49.3880138 (1))

