#include <Arduino.h>
#include <OpenSmartSerialMP3.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

/* BEGIN DEBUG DEFINITIONS */
#define DEBUG 1

#if DEBUG
	#define DEBUG_BAUD 115200
	#define PRINTS(s) { Serial.print(F(s)); }
	#define PRINT(s,v)  { Serial.print(F(s)); Serial.print(v); }
	#define PRINTX(s,v) { Serial.print(F(s)); Serial.print(F("0x")); Serial.print(v, HEX); } // Print Hex
#else
	#define PRINTS(s)
	#define PRINT(s,v)
	#define PRINTX(s,v)
#endif
/* END DEBUG DEFINITIONS */


/* BEGIN MP3 DEFINITIONS */
#define MP3_BAUD 9600

MP3 mp3;
/* END MP3 DEFINITIONS */


/* BEGIN BLE DEFINITIONS */
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define DEVICE_NAME "Honk"

class Callbacks : public BLECharacteristicCallbacks {
	void onWrite(BLECharacteristic *pCharacteristic) {
		std::string value = pCharacteristic->getValue();
		PRINT("\nReceived Value: ", value.c_str())
	}
};
/* END BLE DEFINITIONS */

// enum folders_reference{
//     honk = 1, glass, harmonica, soap, trash_lid, walkie_talkie
// } folders;

void setup() {
	#if DEBUG
		Serial.begin(DEBUG_BAUD);
	#endif

	Serial2.begin(MP3_BAUD);
	mp3.begin();

	PRINTS("\nStarting BLE work!")

	BLEDevice::init(DEVICE_NAME);
	BLEServer *pServer = BLEDevice::createServer();
	BLEService *pService = pServer->createService(SERVICE_UUID);
	BLECharacteristic *pCharacteristic = pService->createCharacteristic(
											CHARACTERISTIC_UUID,
											BLECharacteristic::PROPERTY_READ |
											BLECharacteristic::PROPERTY_WRITE |
											BLECharacteristic::PROPERTY_WRITE_NR
										);
	pCharacteristic->setCallbacks(new Callbacks());

	pCharacteristic->setValue("");
	pService->start();
	// BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
	BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
	pAdvertising->addServiceUUID(SERVICE_UUID);
	pAdvertising->setScanResponse(true);
	pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
	pAdvertising->setMinPreferred(0x12);
	BLEDevice::startAdvertising();
	PRINTS("\nCharacteristic defined!");

}

void loop() {
	delay(2000);
}