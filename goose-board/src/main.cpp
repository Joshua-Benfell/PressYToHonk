#include <Arduino.h>
#include <OpenSmartSerialMP3.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <queue>
#include <MusicTrack.h>

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

/* BEGIN QUEUE DEFINITIONS */
std::queue<MusicTrack_t> musicQueue;
/* END QUEUE DEFINITIONS */

/* BEGIN BLE DEFINITIONS */
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define DEVICE_NAME "Honk"

class Callbacks : public BLECharacteristicCallbacks {
	void onWrite(BLECharacteristic *pCharacteristic) {
		std::string value = pCharacteristic->getValue();
		std::string folder;
		std::string track;
		bool is_folder = true;
		for (int i = 0; i < value.length(); i++) {
			char c = value.at(i);
			if (isDigit(c)) {
				if (is_folder) {
					folder.push_back(c);
				} else {
					track.push_back(c);
				}
			} else {
				is_folder = false;
			}
		}
		PRINT("\nReceived Value: ", value.c_str())
		PRINT("\nFolder: ", folder.c_str());
		PRINT("\nTrack: ", track.c_str());
		MusicTrack_t temp = {(uint8_t) atoi(folder.c_str()), (uint8_t) atoi(track.c_str())};
		musicQueue.push(temp);
	}
};
/* END BLE DEFINITIONS */



void setup() {
	#if DEBUG
		Serial.begin(DEBUG_BAUD);
	#endif

	Serial2.begin(MP3_BAUD);
	mp3.begin();
	delay(100);
	mp3.setVolume(0x10);

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
	if (!musicQueue.empty()) {
		MusicTrack_t next = musicQueue.front();
		PRINT("\nFolder: ", next.folder);
		PRINT("\nTrack: ", next.track);
		mp3.playWithFileName(next.folder, next.track);
		musicQueue.pop();
	} else {
		delay(200);
	}
}