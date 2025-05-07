#include <WiFi.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 48
#define NUMPIXELS 1

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

const char* ssid = "ESP32-RGB";
const char* password = "esp32password";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Starting RGB Access Point...");
  WiFi.softAP(ssid, password);
  Serial.println("✅ AP started");
  Serial.println(WiFi.softAPIP());

  pixels.begin();
  pixels.clear();
  pixels.show();

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();
    Serial.println("📄 Request: " + request);

    if (request.indexOf("/RED") != -1) {
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));
      pixels.show();
      Serial.println("🔴 Red");
    } else if (request.indexOf("/GREEN") != -1) {
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.show();
      Serial.println("🟢 Green");
    } else if (request.indexOf("/BLUE") != -1) {
      pixels.setPixelColor(0, pixels.Color(0, 0, 255));
      pixels.show();
      Serial.println("🔵 Blue");
    } else if (request.indexOf("/OFF") != -1) {
      pixels.clear();
      pixels.show();
      Serial.println("⚫ Off");
    }

    // Build HTML response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println(R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body {
      font-family: sans-serif;
      text-align: center;
      padding-top: 30px;
      background: #f0f0f0;
    }
    button {
      width: 80%;
      padding: 20px;
      margin: 10px;
      font-size: 1.5rem;
      border: none;
      border-radius: 15px;
      box-shadow: 2px 2px 8px rgba(0,0,0,0.2);
      transition: all 0.2s ease-in-out;
    }
    .red { background-color: #e74c3c; color: white; }
    .green { background-color: #2ecc71; color: white; }
    .blue { background-color: #3498db; color: white; }
    .off { background-color: #bdc3c7; color: #333; }
    button:active {
      transform: scale(0.97);
    }
  </style>
</head>
<body>
  <h1>ESP32 RGB Control</h1>
  <a href="/RED"><button class="red">Red</button></a><br>
  <a href="/GREEN"><button class="green">Green</button></a><br>
  <a href="/BLUE"><button class="blue">Blue</button></a><br>
  <a href="/OFF"><button class="off">Turn Off</button></a>
</body>
</html>
)rawliteral");
  }
}
