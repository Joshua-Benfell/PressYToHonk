#include <Arduino.h>
#include <OpenSmartSerialMP3.h>

#define BAUD 9600

MP3 mp3;

// enum folders_reference{
//     honk = 1, glass, harmonica, soap, trash_lid, walkie_talkie
// } folders;

// uint8_t select_SD_card[] = {0x7e, 0x03, 0X35, 0x01, 0xef}; // 7E 03 35 01 EF
// uint8_t play_folder_honk[] = {0x7e, 0x04, 0x42, 0x01, 0x01, 0xef}; // 7E 04 42 01 01 EF
// uint8_t play_folder_glass[] = {0x7e, 0x04, 0x42, 0x02, 0x01, 0xef}; // 7E 04 42 02 01 EF

void send_command_to_MP3_player(uint8_t command[], int len){
    Serial.print("\nMP3 Command => ");
    for(int i=0;i<len;i++){
        Serial2.write(command[i]); 
        Serial.print(command[i], HEX);
    }
    delay(1000);
}


void setup() {
    // Serial.begin(115200);
    // Serial2.begin(9600);
    // send_command_to_MP3_player(select_SD_card, 5);
    // send_command_to_MP3_player(play_folder_honk, 6);
    // delay(2000);
    // send_command_to_MP3_player(play_folder_glass, 6);

    Serial.begin(115200);
    Serial2.begin(9600);
    mp3.begin();
    mp3.playWithFileName(0x01, 0x01);
    mp3.playWithFileName(0x02, 0x01);

}

void loop() {
}