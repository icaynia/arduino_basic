/* 
Copyright (c) 2016/11/05 icaynia

This code is free of change. This code is for Beginner, Tester and anyone.
The following steps will make a simple testing environment. 

First, Connect to HC-06 module to arduino with jumper cable,
default pin number is TX:digital 2, RX:digital 3.

and You can upload to arduino and run.
*/


#include <SoftwareSerial.h>

/*Set Tx, Rx pin */
#define Tx 2    
#define Rx 3

/*Set Bluetooth Baud Rate (Default is 9600)*/
#define bluetooth_baudrate 9600

/*Set Serial Baud Rate (Default is 9600)*/
#define serial_baudrate 9600
SoftwareSerial BTSerial(Tx, Rx);

char tmp;

void setup() {
  Serial.begin(serial_baudrate);
  BTSerial.begin(bluetooth_baudrate);
}

void loop() {
  if (Serial.available()) {
    tmp = Serial.read();
    BTSerial.print(tmp);
    
  }
  if (BTSerial.available()) {
    tmp = BTSerial.read();
    Serial.print(tmp);
  }

}
