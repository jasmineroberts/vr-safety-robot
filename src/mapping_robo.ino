/*
   SA2_c
   2k19
   input voltage for motor driver is 6.25v; don't change.
*/
#include <Wire.h>
#include "Adafruit_VL53L0X.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
Adafruit_VL53L0X lox = Adafruit_VL53L0X();


const int RIGHTMotorEN =   10;
const int RIGHTlogic1  =  11;
const int RIGHTlogic2  = 12 ;

const byte LEFTMotorEN  =  9;
const byte LEFTlogic1  =   8;
const byte LEFTlogic2  =   7;

const byte trig_front = 13;
const byte echo_front = 6;
const byte trig_l_front = 15;
const byte echo_l_front = 14;
const byte trig_l_back = 17;
const byte echo_l_back = 16;


float distance_F;
float distance_LF;
float distance_LB;
float duration_F;
float duration_LB;
float duration_LF;
const byte left_enc = 2;
const byte right_enc = 3;
long left_reading;//encoder
long right_reading;

float P = 5.5 ;
float D = 1.0 ;
float I = 0.88 ;

float oldErrorP ;
float totalError ;
const byte offset = 5 ;
const byte front_threshold = 20;
const byte wall_threshold = 25 ;
const byte baseSpeed = 120 ;

byte RMS ;
byte LMS ;
byte corner_count;

void setup() {
  Serial.begin(9600);

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  if (!mag.begin())
  {
    Serial.println("no HMC5883 detected");
    while (1);
  }

  //  displaySensorDetails();

  pinMode(13, OUTPUT);
  pinMode(6, INPUT);
  pinMode(trig_l_front, OUTPUT);
  pinMode(echo_l_front, INPUT);
  pinMode(trig_l_back, OUTPUT);
  pinMode(echo_l_back, INPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(left_enc), L_enc, CHANGE);
  attachInterrupt(digitalPinToInterrupt(right_enc), R_enc, CHANGE);

}

void L_enc() {
  left_reading++;
 // Serial.println(left_reading);
}
void R_enc() {
  right_reading++;
 // Serial.println(right_reading);
}


