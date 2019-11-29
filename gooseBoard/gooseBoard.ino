#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

const char *ssid = "Honk";

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.softAP(ssid);
  IPAddress ip = Wifi.softAPIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

}

void loop() {
  // put your main code here, to run repeatedly:
  
}
