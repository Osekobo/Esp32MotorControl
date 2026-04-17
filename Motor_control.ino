#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "MOOD";
const char* password = "1password1";

WebServer server(80);

int motorPin = 2;

void handleRoot() {
  String html = "<h1>ESP32 Motor Control</h1>";
  html += "<p><a href='/on'><button>ON</button></a></p>";
  html += "<p><a href='/off'><button>OFF</button></a></p>";
  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(motorPin, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleOff() {
  digitalWrite(motorPin, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
}

void loop() {
  server.handleClient();
}
