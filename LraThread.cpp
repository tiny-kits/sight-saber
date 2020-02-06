#include <Arduino.h>
#ifdef CMAKE
#include <cstring>
#endif 
#include "LraThread.h"

#include <Wire.h>             // For using I2C communication
#include "src/adafruit/Adafruit_DRV2605.h" // For interfacing with the DRV2605 chip

LraThread lraThread; // Haptic feedback

Adafruit_DRV2605 drv;   // The variable used to interface with the DRV2605 chip
const int powerPin = 4;  // Power to Wireling

LraThread::LraThread(uint16_t msLoop, uint8_t port)
    : msLoop(msLoop), level(0), effect(0), count(0), port(port)
{}

void LraThread::setup(uint8_t port) {
    id = 'L';
    Thread::setup();
    this->port = port;
    om::pinMode(powerPin, OUTPUT);
    om::digitalWrite(powerPin, HIGH);
    drv.begin();
    drv.selectLibrary(1);
    om::print("LraThread.setup");
}

void LraThread::buzz(uint8_t level) {
    // 50% duty cycle software PWM buzz
    // PWM period is twice msLoop
    this->level = level;
}

void LraThread::setEffect(uint8_t effect, uint8_t count) {
    this->effect = effect;
    this->count = count;
}

void LraThread::playWaveform() {
    // repeat effect every period until count goes to zero
    if (count) { count--; } else { effect = 0; };
    drv.setMode(DRV2605_MODE_INTTRIG);
    drv.useLRA();
    // Just use waveform buffer for one effect
    drv.setWaveform(0, effect);  // Set effect
    drv.setWaveform(1, 0);       // End waveform
    drv.go(); // play
}

void LraThread::loop() {
    nextLoop.ticks = om::ticks() + MS_TICKS(msLoop);

    om::setI2CPort(port); // Tiny Adapter port

    if (level) {
        drv.setMode(DRV2605_MODE_REALTIME);
        drv.setRealtimeValue((loops%2) ? level : 0);
    } else {
        playWaveform();
    }
}
