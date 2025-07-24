#include <ESP32Servo.h>

Servo myServo;

void setup() {
  Serial.begin(115200);
  myServo.attach(13);
  Serial.println("Servo Smooth Scanning Mode Aktif!");
}

void loop() {
  // Scan ke kanan (40 -> 180)
  for (int pos = 40; pos <= 180; pos += 1) {
    myServo.write(pos);
    Serial.print("Scanning ke kanan: ");
    Serial.print(pos);
    Serial.println(" derajat");
    delay(10);  // Lebih halus (semakin kecil = makin smooth)
  }

  delay(200); // jeda singkat di ujung

  // Scan ke kiri (180 -> 40)
  for (int pos = 180; pos >= 40; pos -= 1) {
    myServo.write(pos);
    Serial.print("Scanning ke kiri: ");
    Serial.print(pos);
    Serial.println(" derajat");
    delay(10);
  }

  delay(200); // jeda sebelum ulang
}
