#include <WiFi.h>
#include <BluetoothSerial.h>

// Replace with your network credentials
const char* ssid = "realme narzo 20";
const char* password = "12345678";

// Replace with your Bluetooth name
const char* bluetoothName = "SEADICK";


// Create Bluetooth serial object
BluetoothSerial SerialBT;

// Store WiFi connection status
bool wifiConnected = false;

void setup() {
  Serial.begin(9600);
  // Start Bluetooth serial
  SerialBT.begin(bluetoothName);
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
  // Set WiFi connection status to true
  wifiConnected = true;
}

void loop() {
 if (WiFi.status() != WL_CONNECTED) {
  Serial.println("WiFi terputus");
}else{
  Serial.println("WiFi tersambung");
}

 // Check Bluetooth connection
if (!SerialBT.connected()) {
    // If Bluetooth is disconnected, print message and wait for reconnection
  Serial.println("Bluetooth connect");

  
}else{
  Serial.println("Bluetooth terlalu jauh");
}

    // Wait for 10 seconds before sending next data
delay(10000);

}
