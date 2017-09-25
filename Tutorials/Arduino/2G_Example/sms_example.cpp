//////////////////////////////////////////
/*
 *  Copyright (C) 2017 Loranga, Valpariso, Chile
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************
 * last update: Sep. 25 by Loranga
 */

//////////////////////////////////////////


#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGsmClientSIM800.h>


#define TINY_GSM_MODEM_SIM800           // Define the tipe of 2G module you are using

SoftwareSerial SerialAT(5, 6);          // Software Serial to comunicate with 2G module
                                        // pin 5 of arduino is RX, pin 6 is TX
TinyGsm modem(SerialAT);                // Start the TinyGsm lib on SoftwareSerial 


void setup() {


Serial.begin(38400);                    // Enable Serial with computer
pinMode(4, OUTPUT);                     // Enable pin 4 of arduino to wake 2G module
digitalWrite(4, HIGH);                  // High pulse on wake-2G pin of Loranga for 2 seconds to enable or disable the module
delay(2000);
digitalWrite(4, LOW);                   // Stop wake up pulse

SerialAT.begin(9600);                   // Start SoftwareSerial for 2G module
delay(2000);

modem.restart();                        // restart the modem to start communication


Serial.print(F("Waiting for network"));  // check if you have network
if (!modem.waitForNetwork()) {
  Serial.println(" fail");
  delay(10000);
  return;
  }
Serial.println(" OK");

modem.sendSMS("+xxxxxxxxxxx", "some text");  // send a SMS to the number
                                               // number must be in international format
}

void loop() { // run over and over

}
