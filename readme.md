# Loranga IoT HAT

Loranga is a IoT HAT transforming your Raspberry Pi into a gateway for IoT,
It uses LoRa and 2G radio to connect all your sensors to the world easyly

It is designed for the Raspberry Pi Zero (other RPi boards with 40-pin header will also work).


## Functional diagram

bla bla

## Features

bla bla


# How to use

bla bla


## 2G Module Set-up

### A. Start 2G module on your loranga board
The 2G module on Loranga needs a wake-up signal from the Rpi.

The pin used for this is GPIO 22 (Physical pin 15).

You need to send a High level for 2 seconds over GPIO 22 to wake-up or sleep the module.


1. Download the wake-2G python script
- `wget https://raw.githubusercontent.com/edu986/test_ppp/edit_readme/wake-2G.py`

2. Call the script in order to wake-up the 2G module
- `sudo python wake-2G.py`

3. This script can be added later on /etc/rc.local to auto wake-up at boot.


### B. Set-up the ppp connection
LORANGA use Uart connection on Raspberry Pi. You can use following instructions to make it work.

1. Firstly, Connect your Raspberry Pi to internet and run `sudo apt-get update` to update your Raspberry Pi

2. We should stop getty service on Raspbian.
  1. For non Raspberry Pi 3 machines, remember it’s /dev/ttyAMA0 that is linked to the getty (console) service. So you need to perform this command from a terminal window:
    - `sudo systemctl stop serial-getty@ttyAMA0.service`
    - `sudo systemctl disable serial-getty@ttyAMA0.service`

  2. For Raspberry Pi 3’s the command is similar but referencing /dev/ttyS0:
    - `sudo systemctl stop serial-getty@ttyS0.service`
    - `sudo systemctl disable serial-getty@ttyS0.service`

  3. You also need to remove the console from the cmdline.txt. If you edit this with:
    - `sudo nano /boot/cmdline.txt`
      ```
      dwc_otg.lpm_enable=0 console=serial0,115200 console=tty1 root=/dev/mmcblk0p2 rootfstype=ext4 elevator=deadline fsck.repair=yes rootwait quiet splash plymouth.ignore-serial-consoles
      ```
      remove the line: console=serial0,115200 and save and reboot for changes to take effect.
  4. You also need to enable uart with edit /boot/config.txt file
    - `sudo nano /boot/config.txt` and add `enable_uart=1` to bottom of file then save and reboot for changes to take effect.

3. Download ppp-creator.sh script and run. Script will install ppp and creates config files.
  - `wget https://raw.githubusercontent.com/edu986/test_ppp/master/ppp-creator.sh`
  - `chmod +x ./ppp-creator.sh`
  - `sudo ./ppp-creator.sh INTERNET ttyAMA0` # Rpi3 > ttyS0 , others ttyAMA0 # INTERNET is APN, check your cellular

4. Run `sudo pppd call gprs`
5. run `ifconfig ppp0` at terminal window to see following outputs and see your ip<br/>
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

### A Enable serial


### WAZIUP Code
