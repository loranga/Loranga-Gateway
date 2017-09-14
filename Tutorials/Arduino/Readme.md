# Loranga and Arduino

If your don't have a Raspberry pi, you can use Loranga with an Arduino or any other microcontroller

Here you can find different examples to use Loranga with Arduino

The 2G module and the LoRa transceiver works on 3.3V communication only.

In this case we are using an Arduino nano with AtMega328p

In order to use, you need to connect your Arduino as the picture below

![Image of arduino](https://github.com/loranga/Loranga-Gateway/blob/master/Docs/Photos/nano_lora_gsm.png)

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
GSM_TX | 5 (Software Serial) | 8
GSM_RX | 6 (Software Serial) | 6
