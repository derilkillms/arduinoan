#include <SoftwareSerial.h>
#include <WiFi.h>

SoftwareSerial bluetooth(10, 11); // RX, TX
const char* ssid = "Nama_WiFi_Toko";
const char* password = "Password_WiFi_Toko";

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  delay(1000);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi terputus");
  }
  if (!bluetooth.available()) {
    Serial.println("Bluetooth terlalu jauh");
  } else {
    // Baca data dari perangkat ponsel
    char data = bluetooth.read();
    // Lakukan sesuatu dengan data
  }
  delay(1000);
}
