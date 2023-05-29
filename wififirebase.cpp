#include <WiFi.h>
#include <FirebaseESP32.h>

// Replace with your network credentials
const char* ssid = "SSID WIFI";
const char* password = "PASSWORD WIFI";

// Replace with your Firebase project URL and secret
//Project overview >> Setting >> Service Accounts >> Database Secrets
#define FIREBASE_HOST "DATABASE FIREBASE URL"
#define FIREBASE_SECRET "FIREBASE SECRET"
#define DEVICE_ID "DEVICE-0007"

FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  // Connect to WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_SECRET);
}

void loop() {
  // Check WiFi connection
  if (WiFi.status() == WL_CONNECTED) {
    // Send data to Firebase

    if (Firebase.setString(firebaseData, DEVICE_ID "/deviceName", DEVICE_ID)){
      Serial.println("PASSED : deviceName");
    }
    if (Firebase.setString(firebaseData, DEVICE_ID "/rssi", WiFi.RSSI())){
      Serial.println("PASSED : rssi");
    }
    if (Firebase.setString(firebaseData, DEVICE_ID "/status", "connected")){
      Serial.println("PASSED : status");
    }
    if (Firebase.setTimestamp(firebaseData, DEVICE_ID "/timestamp")){
      Serial.println("PASSED : timestamp");
    }

    if (firebaseData.dataAvailable()) {
      Serial.println("respon");
      Serial.println(firebaseData.errorReason());
    }
    delay(10000);
  } else {
    Serial.println("WiFi disconnected");
  }
}
