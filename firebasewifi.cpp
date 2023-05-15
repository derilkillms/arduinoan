#include <WiFi.h>
#include <FirebaseESP32.h>

// Replace with your network credentials
const char* ssid = "Nama_WiFi";
const char* password = "Password_WiFi";

// Replace with your Firebase project URL and secret
#define FIREBASE_HOST "your_project_url.firebaseio.com"
#define FIREBASE_SECRET "your_firebase_secret"

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
    String path = "/arduino/id_number";
    String id = String(ESP.getEfuseMac(), HEX);
    String data = "1";
    Firebase.setInt(firebaseData, path.c_str(), data.toInt());
    Firebase.setString(firebaseData, "/arduino/arduino_id", id.c_str());
    if (firebaseData.dataAvailable()) {
      Serial.println(firebaseData.responseCode());
      Serial.println(firebaseData.errorReason());
    }
    delay(10000);
  } else {
    Serial.println("WiFi disconnected");
  }
}
