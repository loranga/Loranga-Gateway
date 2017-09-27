# Loranga IoT HAT

Loranga is a Raspberry Pi compatible board designed to make it easier to set up an internet connected LoRa IoT network anywhere a cell phone signal is available. The LoRa Technology enables long range, low power and low cost communication between devices.

All Raspberry Pi boards with a 40-pin header works great with Loranga. With a formfactor of the RPI0 complexity is kept at a minimum in order to keep the BOM short and cost as low as possible while maintaining flexibility.

## Functional diagram

Loranga combines the power of the widely deployed 2G cellular network with the great LoRa network features.
Our first edition is equiped with the HopeRF RF95W LoRa Transceiver and a SIMCom SIM800L 2G module. Make sure you order a Loranga with your region's license free frequency bands (typically 433MHz and 850MHz-1GHz).

![Image of loranga](https://github.com/loranga/Loranga-Gateway/blob/master/Docs/Photos/PARTES%2BTECNICAS.png)


## Features

- Fully compatible with the 40-pin GPIO connector on Raspberry Pi.

- Contains its own micro USB connector to power the Loranga as well as the Raspberry Pi.

- Each wireless module has its own u.FL antenna connector.

- Loranga has two built-in status LEDs for the 2G module and one connected to a GPIO pin for customizable implementation.


# Setup


## Physical setup

In order to use Loranga with your Rasperry Pi you need to:

1. Insert a nano SIM card in the SIM holder on the backside of the Loranga board.

2. Connect your antennas to the u.FL connectors.

3. Plug a 5V, 2A power adapter to the micro USB conector on Loranga (You don't need to connect your regular Pi power).


## How to use with the WAZIUP gateway software.

We at La Fabrica Alegre recommend setting up your gateway with the [LowCostLoRaGateway](https://github.com/CongducPham/LowCostLoRaGw)
This gateway software is plug-and-play with Loranga and extremely well documented. It is therefor recommended to dig into the tutorial material and FAQ to learn about all the possibilities.

You can also simply download a complete Raspbian image with the gateway sotware already installed.


### Setting up Loranga with prebuilt gateway SD-card image

SD-card image available here: http://cpham.perso.univ-pau.fr/LORA/WAZIUP/raspberrypi-jessie-WAZIUP-demo.dmg.zip

The image works out-of-the-box for RPI3 and RPI0W enabling an AP using the onboard wifi.

1. Boot up the Pi with Loranga installed on top.

2. Select the advertised wifi AP and connect with ssh pi@192.168.200.1 (password is loragateway).

3. cd to /home/pi/lora_gateway

4. If using HopeRF RF95W, edit  (what path !!) radio.makefile and uncomment the PABOOST option. (link here to PABOOST explanation on congduc github)

5. Run ./scripts/basic_config_gw.sh  (The script also recompiles the gateway software. You can reboot and you will see that the advertised wifi name has now changed and the gateway id has been set)

6. Run (is path correct ??) ./scripts/start_internet.sh   (3GDongle/loranga) to connect the gw to the internet using the 2G modem on Loranga.

7. To access the web admin interface open a browser on your Pi and go to the local webpage 192.168.200.1/admin, login: 'admin', password: 'loragateway'.

8. Once the gw has internet you can select the gateway update menu on the left and then you can select the "Full update" option and click on the download icon to update with the latest version from github.



### Setting up Loranga and manually build the gateway software

Setting up manually is slightly more involved but serves as a great start to underastand the functionality of the gateway. The tutorial material is provided by Congduc Pham and the WAZIUP team.

Two tutorial videos on YouTube describing all the steps to build the whole framework from scratch:

- [Build your low-cost, long-range IoT device with WAZIUP](https://www.youtube.com/watch?v=YsKbJeeav_M)
- [Build your low-cost LoRa gateway with WAZIUP](https://www.youtube.com/watch?v=peHkDhiH3lE)

Go to [https://github.com/CongducPham/tutorials](https://github.com/CongducPham/tutorials) for all tutorials and particularly look for:

- [Low-cost-LoRa-IoT-step-by-step tutorial](https://github.com/CongducPham/tutorials/blob/master/Low-cost-LoRa-GW-step-by-step.pdf)
- [Low-cost-LoRa-GW-step-by-step tutorial](https://github.com/CongducPham/tutorials/blob/master/Low-cost-LoRa-IoT-step-by-step.pdf)
- [Low-cost-LoRa-IoT-antennaCable tutorial](https://github.com/CongducPham/tutorials/blob/master/Low-cost-LoRa-IoT-antennaCable.pdf)

See also Congduc Pham's gateway [FAQ](https://github.com/CongducPham/tutorials/blob/master/FAQ.pdf) and [website](http://cpham.perso.univ-pau.fr/LORA/RPIgateway.html).




### Manually setting up the 2G module

If you plan to use Loranga for other purposes you can setup the hardware as described below.

#### A. Start the 2G module on your Loranga board
The 2G module on Loranga needs a wake-up signal from the RPi.

The pin used for this is GPIO 22 (physical pin 15).

You need to send a high level for 2 seconds over GPIO 22 to wake it up (same procedure to sleep it)

1. Download the wake-2G python script
- `wget https://raw.githubusercontent.com/edu986/test_ppp/edit_readme/wake-2G.py`

2. Call the script in order to wake-up the 2G module
- `sudo python wake-2G.py`

3. This script can be added later on /etc/rc.local to auto wake-up at boot.


#### B. Set up the ppp connection
Loranga uses the UART pins on the RPi GPIO to interface with the 2G modem. Follow the instructions below to connect to the cellular network of your choice.

1. Firstly, connect your Raspberry Pi to the internet using wifi or ethernet and run `sudo apt-get update` to update your Raspberry Pi

2. Stop the getty service on Raspbian.
  1. For non-Raspberry Pi 3 machines, remember it’s /dev/ttyAMA0 that is linked to the getty (console) service. So you need to perform this command from the terminal:
    - `sudo systemctl stop serial-getty@ttyAMA0.service`
    - `sudo systemctl disable serial-getty@ttyAMA0.service`

  2. For Raspberry Pi 3’s the command is similar but referencing /dev/ttyS0:
    - `sudo systemctl stop serial-getty@ttyS0.service`
    - `sudo systemctl disable serial-getty@ttyS0.service`

  3. Remove the console from the cmdline.txt:
    - `sudo nano /boot/cmdline.txt`
      ```
      dwc_otg.lpm_enable=0 console=serial0,115200 console=tty1 root=/dev/mmcblk0p2 rootfstype=ext4 elevator=deadline fsck.repair=yes rootwait quiet splash plymouth.ignore-serial-consoles
      ```
      , remove the line: `console=serial0,115200` and save.

  4. Enable UART by editing the /boot/config.txt file
    - `sudo nano /boot/config.txt` and add `enable_uart=1` to the bottom of file. Then save and reboot for changes to take effect.

3. Download ppp-creator.sh script and run. This script will install ppp and create the ppp config files.
  - `wget https://raw.githubusercontent.com/edu986/test_ppp/master/ppp-creator.sh`
  - `chmod +x ppp-creator.sh`
  - `sudo ./ppp-creator.sh INTERNET ttyAMA0` # RPi3 needs ttyS0 instead of ttyAMA0 # Replace INTERNET with your cellular network provider's APN (example: web.entelpcs.cl).

4. Run `sudo pppd call gprs`
5. run `ifconfig ppp0` in the terminal to see the following output and check your designated IP<br/>
  ```
  ppp0      Link encap:Point-to-Point Protocol
            inet addr:XX.XX.XXX.XXX  P-t-P:XX.XX.XX.XX  Mask:255.255.255.255
            UP POINTOPOINT RUNNING NOARP MULTICAST  MTU:1500  Metric:1
            RX packets:38 errors:0 dropped:0 overruns:0 frame:0
            TX packets:39 errors:0 dropped:0 overruns:0 carrier:0
            collisions:0 txqueuelen:3
            RX bytes:3065 (2.9 KiB)  TX bytes:2657 (2.5 KiB)

  ```


## LoRa Module Set-up

The easiest way to run the RPi and the HopeRF LoRa module on the Loranga board is to only run the basic gateway from the gateway project above. From there you can start experimenting with the drivers
HopeRF RFM95W SX1276 compatible drivers are available from RadioHead and Libelium as well as in the gateway package described above.
Semtech

[RadioHead](http://www.airspayce.com/mikem/arduino/RadioHead/classRH__RF95.html) :

## Building your own LoRa nodes

Now that you have your LoRa-Internet gateway ready, you probably want to build some wireless nodes to send you data. There are many options out there to get you started quickly. Our favourites are:

- [Moteino](https://lowpowerlab.com/guide/moteino/)
- [Modtronix](http://modtronix.com/inair9.html)
