#ifndef _Red_MP3_H__
#define _Red_MP3_H__

#include <Arduino.h>
#include <HardwareSerial.h>

/************Command byte**************************/
/*basic commands*/
#define CMD_PLAY  0x01
#define CMD_PAUSE 0x02
#define CMD_NEXT_SONG 0x03
#define CMD_PREV_SONG 0x04
#define CMD_VOLUME_UP   0x05
#define CMD_VOLUME_DOWN 0x06
#define CMD_FORWARD 0x0A // >>
#define CMD_REWIND  0x0B // <<
#define CMD_STOP 0x0E
#define CMD_STOP_INJECT 0x0F//stop interruptting with a song, just stop the interlude

#define CMD_CHECK_STATUS 0x10
  #define STATUS_STOP    0
  #define STATUS_PLAY    1
  #define STATUS_PAUSE   2
  #define STATUS_FORWARD 3
  #define STATUS_REWIND  4
  
/*5 bytes commands*/
#define CMD_SEL_DEV 0x35
  #define DEV_TF 0x01


/*6 bytes commands*/  
#define CMD_PLAY_W_INDEX   0x41
#define CMD_PLAY_FILE_NAME 0x42
#define CMD_INJECT_W_INDEX 0x43

/*Special commands*/
#define CMD_SET_VOLUME 0x31
#define CMD_PLAY_W_VOL 0x31

#define CMD_SET_PLAY_MODE 0x33
  #define ALL_CYCLE 0x00
  #define SINGLE_CYCLE 0x01

#define CMD_PLAY_COMBINE 0x45//can play combination up to 15 songs

class MP3
{
public:
	MP3(uint8_t baud);
	void begin();
	void play();
	void pause();
	void nextSong();
	void previousSong();
	void volumeUp();
	void volumeDown();
	void forward();
	void rewind();
	void stopPlay();
	void stopInject();
	void singleCycle();
	void allCycle();
	void playWithIndex(int8_t index);
    void injectWithIndex(int8_t index);

	uint8_t getStatus();

	void setVolume(int8_t vol);
	void playWithFileName(int8_t directory, int8_t file);
	void playWithVolume(int8_t index, int8_t volume);
	void cyclePlay(int16_t index);
	void setCyleMode(int8_t AllSingle);
	void playCombine(int16_t folderAndIndex[], int8_t number);
	void sendBytes(uint8_t buf[], uint8_t nbytes);
	
private:
	// HardwareSerial myMP3;
	uint8_t baud;
	void sendCommand(int8_t command, int16_t dat = 0);
	void mp3Basic(int8_t command);
	void mp3_5bytes(int8_t command, uint8_t dat);
	void mp3_6bytes(int8_t command, int16_t dat);
};

#endif