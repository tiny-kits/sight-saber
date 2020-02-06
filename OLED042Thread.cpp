#include <Arduino.h>
#ifdef CMAKE
#include <cstring>
#endif 
#include <Wire.h>                   // For using I2C communication
#include <Wireling.h>               // For interfacing with Wirelings
#include "src/omilli/Thread.h"
#include "src/omilli/OMilli.h"
#include "OLED042Thread.h"
#include "src/tinycircuits/Font_042.h"  // The font displayed on the screen
#include "src/tinycircuits/TinyCircuits_HP7240.h"    // Library for OLED screen

OLED042Thread oledThread; 

TinyCircuits_HP7240 TiniestScreen;  // 0.42" Wireling screen

#define xMax TiniestScreen.xMax
#define yMax TiniestScreen.yMax

uint8_t oledbuf[HP7240_BUFFERSIZE]; // Buffer to hold screen data

OLED042Thread::OLED042Thread() {}

void OLED042Thread::setup(uint8_t port, uint16_t msLoop){
    id = 'D';
    this->port = port;
    this->msLoop = msLoop;
    Thread::setup();
    switch (port) {
    case 0: resetPin = A0; break;
    case 1: resetPin = A1; break;
    case 2: resetPin = A2; break;
    case 3: resetPin = A3; break;
    default: // INVALID PORT
        resetPin = A0;
        break;
    }
    for (int i = 0; i < OLED042_LINES; i++) {
        sprintf(lines[i], "OM-Ranger %d", i);
    }
    Wireling.begin();
    Wireling.selectPort(port);  // 
    initScreen(); // Initialize the Screen
}

void OLED042Thread::loop() {
    nextLoop.ticks = om::ticks() + MS_TICKS(msLoop);
    Wireling.selectPort(port);  // 
    clearOLED(); // Important for animations or scrolling text
    sprintf(lines[0], "%d", loops);
    for (int i = 0; i < OLED042_LINES; i++) {
        if (lines[i][0]) {
            textPos = i*xMax;
            TiniestScreen.setCursorX(textPos);
            TiniestScreen.printSSD(oledbuf, lines[i]); 
        }
    }
    TiniestScreen.sendFramebuffer(oledbuf);
}

void OLED042Thread::initScreen(void){
    TiniestScreen.begin();    
    TiniestScreen.resetScreen(resetPin);  // reset BEFORE init()
    TiniestScreen.init();     
    clearOLED();              
    om::delay(2);
    TiniestScreen.sendFramebuffer(oledbuf); // update screen
}

void OLED042Thread::clearOLED() {
    for (int i = 0; i < HP7240_BUFFERSIZE; i++) {
        oledbuf[i] = 0x00;
    }
}

void OLED042Thread::setPixel(int px, int py) {
    int pos = py>7 ? px + (py/8)*xMax : px;
    py = (py % 8);  
    oledbuf[pos] |= (1 << (py)); 
}
