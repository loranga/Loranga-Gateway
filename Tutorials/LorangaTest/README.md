# Loranga

- Download image from WAZIUP page
- Burn image with Etcher on a SD card (more than 8 Gb)
- Boot with keyboard and screen
- CTRL+ALT+T open terminal
  - It will open a command screen
  - Enter option K -> Kill all GW related process
  - Enter option Q -> Quit

- Run `sudo raspi-config`
  - Change keyboard lyout (default French)
  - Enable SSH
    - Select Interfacing Options
		- Navigate to and select SSH
		- Choose Yes
		- Select Ok
		- Choose Finish
- Disable Access Point
  - Run `./scripts/stop_access_point.sh`
- Configure wifi:
  - Open the wpa-supplicant configuration file in nano:
    `sudo nano /etc/wpa_supplicant/wpa_supplicant.conf`
  - Go to the bottom of the file and add the following:
    ``` network={
        ssid="YOUR wifi SSID"
        psk="YOUR password"
        }
    ```
  - Reboot     
- Modify lora_gateway.cpp file to change frequency and enable PABOOST
  - `sudo nano lora_gateway.cpp`
  - Get down until you find "ifdef ARDUINO"
  - Uncomment line //define PABOOST
  - A few lines under uncomment the BAND900 and comment the BAND868
  - Exit and save with CRTL+X and Y
- Compile the GW code
	- `sudo ./scripts/basic_config_gw.sh`
	- Reboot
  - Quit with Q
- Go to Loranga folder `cd 3GDongle/loranga`
  - Download test files
    - `wget https://raw.githubusercontent.com/loranga/Loranga-Gateway/master/Tutorials/LorangaTest/serialtest.py`
    - `wget https://raw.githubusercontent.com/loranga/Loranga-Gateway/master/Tutorials/LorangaTest/lorangatest.sh`
  - Make the test file executable
    - `chmod +x lorangatest.sh`
- Run test
  - (In the /3GDongle/loranga folder)
  - Run `./lorangatest.sh`
