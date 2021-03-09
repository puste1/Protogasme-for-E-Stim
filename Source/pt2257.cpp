// Electronic Volume Controller, IC PT2257, v0.3
// 2.10.2018, Arduino IDE v1.8.7, LZ2WSG, KN34PC
//----------------------------------------------------------
#include <Arduino.h>
#include <Wire.h>
#include "pt2257.h"
//        _____
//  LIN -|  ^  |- RIN
// LOUT -|     |- ROUT
//  GND -|     |- VDD
//  SDA -|_____|- SCL

#define PT2275_ADDR 0x44        // I2C address
#define PT2275_OFF  0b11111111  // Off 
#define PT2275_MUTE 0b01111000  // Mute
#define LR_ATT_1    0b11010000  // L & R channels attenuation -1dB
#define LR_ATT_10   0b11100000  // L & R channels attenuation -10dB
#define L_ATT_1     0b10100000  // L-channel attenuation -1dB
#define L_ATT_10    0b10110000  // L-channel attenuation -10dB
#define R_ATT_1     0b00100000  // R-channel attenuation -1dB
#define R_ATT_10    0b00110000  // R-channel attenuation -10dB
//----------------------------------------------------------
PT2257::PT2257() {
}
//----------------------------------------------------------
void PT2257::init() {
  Wire.begin();
}
//----------------------------------------------------------
void PT2257::set_volume(uint8_t db) {
  Wire.beginTransmission(PT2275_ADDR);
  Wire.write(LR_ATT_10 | (db / 10));
  Wire.write(LR_ATT_1 | (db % 10));
  Wire.endTransmission();
}
//----------------------------------------------------------
void PT2257::set_volume_left(uint8_t db) {
  Wire.beginTransmission(PT2275_ADDR);
  Wire.write(L_ATT_10 | (db / 10));
  Wire.write(L_ATT_1 | (db % 10));
  Wire.endTransmission();
}
//----------------------------------------------------------
void PT2257::set_volume_right(uint8_t db) {
  Wire.beginTransmission(PT2275_ADDR);
  Wire.write(R_ATT_10 | (db / 10));
  Wire.write(R_ATT_1 | (db % 10));
  Wire.endTransmission();
}
//----------------------------------------------------------
void PT2257::mute(bool st) {
  Wire.beginTransmission(PT2275_ADDR);
  Wire.write(PT2275_MUTE | st);
  Wire.endTransmission();
}
//----------------------------------------------------------
void PT2257::off() {
  Wire.beginTransmission(PT2275_ADDR);
  Wire.write(PT2275_OFF);
  Wire.endTransmission();
}
