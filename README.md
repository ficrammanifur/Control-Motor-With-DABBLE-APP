# Control Motor with Dabble App

Proyek ini memungkinkan Anda mengendalikan motor (DC dan/atau servo) dengan aplikasi **Dabble** melalui koneksi Bluetooth. Cocok digunakan bersama Arduino Uno/Nano/Mega atau ESP32.

---

## 📦 Isi Repository

- `*.ino`: Sketsa Arduino untuk berbagai konfigurasi papan dan jenis motor.
- `README.md`: Panduan penggunaan (yang sedang Anda baca 😊).

---

## 🧰 Komponen yang Diperlukan

- Arduino Uno / Nano / Mega atau ESP32  
- Bluetooth module (misalnya HC‑05, HC‑06, HM‑10; ESP32 terintegrasi Bluetooth/BLE)  
- Motor DC dan/atau servo  
- Motor driver (untuk motor DC), kabel jumper, dan power supply yang sesuai  

---

## 🚀 Persiapan Proyek

1. **Unduh dan instal aplikasi [Dabble](https://play.google.com/store/apps/details?id=io.dabbleapp)** di Android (versi iOS mendukung BLE)  
2. Pasang modul Bluetooth ke papan seperti:
   - **Arduino Uno/Nano**: RX ke pin 3, TX ke pin 2 (SoftwareSerial)  
   - **Arduino Mega**: RX/TX pada Serial3 (pin 14/15)  
   - **ESP32**: gunakan BLE bawaan  
3. Sambungkan motor dan driver sesuai jenis papan:
   - Untuk Arduino: PWM + dua pin arah per motor  
   - Untuk ESP32: tentukan pin PWM dan arah dalam kode  

---

## ⚙️ Struktur Kode

Gunakan definisi berikut sebelum `#include <Dabble.h>`:

```cpp
#define CUSTOM_SETTINGS
#define INCLUDE_MOTORCONTROL_MODULE
#include <Dabble.h>
```

Inisialisasi:
- Dabble.begin(baudrate) untuk Arduino/evive
- Dabble.begin("Bluetooth_Name") untuk ESP32
- Perbarui data input dari aplikasi menggunakan Dabble.processInput() di dalam loop.

Contoh fungsi:
- Control.runMotor1(), Control.runMotor2()
- Control.getangle_Servo1(), Control.getangle_Servo2() untuk servo

---

**📝 Contoh Kode**
Arduino Uno / Nano / Mega
```cpp
#define CUSTOM_SETTINGS
#define INCLUDE_MOTORCONTROL_MODULE
#include <Servo.h>
#include <Dabble.h>

// Deklarasi pin untuk motor DC
uint8_t PWM_m1 = 6, Dir1_m1 = 4, Dir2_m1 = 7; // Pin PWM dan arah untuk motor 1
Servo servo1, servo2; // Objek untuk servo
motorControls Control(PWM_m1, Dir1_m1, Dir2_m1); // Inisialisasi kontrol motor

void setup() {
  Serial.begin(9600); // Inisialisasi Serial Monitor dengan baud rate 9600
  Dabble.begin(9600); // Inisialisasi Dabble dengan baud rate 9600 untuk Bluetooth
  servo1.attach(10); // Hubungkan servo1 ke pin 10
}

void loop() {
  Dabble.processInput(); // Perbarui data dari aplikasi Dabble
  Control.runMotor1(); // Jalankan motor 1 berdasarkan input dari aplikasi
  servo1.write(Control.getangle_Servo1()); // Atur sudut servo1 berdasarkan input
}
```
**🎮 Cara Penggunaan Aplikasi**
 - Buka aplikasi Dabble di smartphone.
 - Pilih modul Motor Control.
 - Atur slider untuk kecepatan dan arah motor; knob untuk servo.
 - Perangkat Anda akan menerima dan menjalankan perintah sesuai input.

**🧩 Tips & Troubleshooting**
 - Pastikan baud rate Bluetooth cocok dengan Dabble.begin(...).
 - Gunakan modul Bluetooth original (terutama HM‑10 untuk iOS).
 - Gunakan Dabble.processInput() di setiap loop untuk memperbarui data input.
 - Contoh pengendalian servo menggunakan joystick analog dapat ditemukan di forum dan subreddit pengguna ESP32.

**🔗 Referensi & Dokumen Pendukung**
 - Panduan modul Motor Control di Dabble (Arduino & ESP32)
 - Dokumentasi Getting Started with Dabble App

**🧪 Preview & Uji Coba**
 - Silakan sesuaikan pin sesuai konfigurasi hardware Anda dan cobalah contoh kode. Jika ada kendala lebih lanjut, jangan ragu     bertanya!
