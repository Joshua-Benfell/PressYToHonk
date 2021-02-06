#include <Arduino.h>
#include <OpenSmartSerialMP3.h>

#define HW_SERIAL 2
#define BAUD 9600

MP3 mp3(BAUD);

enum folders_reference{
    honk = 1, glass, harmonica, soap, trash_lid, walkie_talkie
} folders;

void setup() {
    delay(500);
    mp3.setVolume(0x1e);
    delay(50);
    mp3.playWithFileName(0x01, 0x01);
    delay(50);
    Serial.println(mp3.getStatus());
}

void loop() {

}