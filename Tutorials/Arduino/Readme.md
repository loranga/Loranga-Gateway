# Loranga and Arduino

If your don't have a Raspberry pi, you can use Loranga with an Arduino or any other microcontroller


# Examples

This folder contains sketches for Arduino (and compatible) boards.

**Arduino_LoRa_Ping_Pong** shows a simple ping-pong communication between a LoRa device and a gateway by requesting an acknowlegment for data messages sent to the gateway.


**sms_example** shows a simple example sending a SMS to a number. It uses TinyGsm Library


# Hardware


**The 2G module and the LoRa transceiver works on 3.3V communication only.**

In this case we are using an Arduino nano with AtMega328p

To use Loranga with your microcontroller, you need to connect the LoRa transceiver via SPI, and the 2G module with Serial.
In this example, as the Arduino nano has only one serial (for USB communication), you need to use Software Serial.

Before start communication with 2G module, you need to wake it up.
To wake up or sleep the 2G module, a high pulse on pin 15 of Loranga is needed.
This high pulse must be at least 2 seconds long.

On the next image you can see how to connect to have the 2 modules working.

![Image of arduino](https://github.com/loranga/Loranga-Gateway/blob/master/Docs/Photos/nano_lora_gsm1.png)

On the next table, you can see the connections for LoRa transceiver (SPI Protocol)

Function | Arduino Nano | Loranga
-------- | ------------ | -------
SPI_SS | 10 | 24
SPI_MOSI | 11 | 19
SPI_MISO | 12  | 21
SPI_CLK  | 13  | 23

And for the 2G module (Serial communication)

Function | Arduino Nano | Loranga
-------- | ------------ | -------
GSM_TX | 5 (Software Serial TX) | 8
GSM_RX | 6 (Software Serial RX) | 6

And the connection needed to wake up the 2G module

Function | Arduino Nano | Loranga
-------- | ------------ | -------
Wake up | 4 | 15

# Libraries

You will need the indicated Libraries to make it work.

Module | Description | Library | link
-------- | ----- | ------------ | -------
2G  | SIM800L | TinyGsm | [TinyGsm](https://github.com/vshymanskyy/TinyGSM )
LoRa | RFM95W  | SX1272 (LowCostLoRaGw)  | [LowCostLoRaGateway](https://github.com/CongducPham/LowCostLoRaGw/tree/master/Arduino/libraries/SX1272)
