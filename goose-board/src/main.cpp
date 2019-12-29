#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial ESP_BT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ESP_BT.begin("Honk");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ESP_BT.available()) {
    Serial.print("Received: ");
    Serial.println(ESP_BT.read());
  }
}