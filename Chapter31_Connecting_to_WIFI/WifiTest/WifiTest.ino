#include <SoftwareSerial.h>
#include "WiFiEsp.h"

// Create WiFi module object on GPIO pin 6 (RX) and 7 (TX)
SoftwareSerial Serial1(6,7);

// Declare and initialise global arrays for WiFi settings
char ssid[] = "InTheAir";
char pass[] = "hkv1mrk4r0r";

// Declare and initialise variable for radio status
int status = WL_IDLE_STATUS;

void setup() {
  
  // Initialize serial for debugging
  Serial.begin(115200);
  
  // Initialize serial for ESP module
  Serial1.begin(9600);
  
  // Initialize ESP module
  WiFi.init(&Serial1);

  // Check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    
    // Don't continue
    while (true);
  }

  Serial.println("WiFi shield is present");
  
  // Attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  printWifiStatus();
}

void printWifiStatus(){
  // Print the SSID of the network
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Print the IP adress
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  // put your main code here, to run repeatedly:

}
