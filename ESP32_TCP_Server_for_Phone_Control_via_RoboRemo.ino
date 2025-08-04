#include <WiFi.h>

// Your ESP32 will create its own Access Point (AP)
const char* ssid = "ESP32-AP";
const char* password = "123456789";

// TCP server port, ESP32 will listen to this port, client (RoboRemo) will connect to it
const uint16_t port = 12345;

WiFiServer server(port);

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Configure as WiFi AP
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
  // Start TCP server
  server.begin();
  Serial.print("TCP server started, listening on port ");
  Serial.println(port);
}

void loop() {
  WiFiClient client = server.accept();
  if(client) {
    Serial.println("Client connected");
    while (client.connected()) {
      if (client.available()) {
        String command = client.readStringUntil('\n');
        command.trim();
        Serial.println("Received: " + command);
        // Example: toggle an onboard LED or parse commands
        // For now, just echo back
        client.println("Received: " + command);
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
