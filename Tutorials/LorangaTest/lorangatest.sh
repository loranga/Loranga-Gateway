
#!/bin/bash

#Script to test Loranga2G over Rpi

echo "This script will test the Loranga 2G board."

echo "Testing Serial Com with SIM800L"


#sudo pyhton /home/pi/lora_gateway/3GDongle/loranga/wake-2G.py
echo "Turn ON 2G module"
#sudo python wake-2G.py
sudo python /home/pi/lora_gateway/3GDongle/loranga/wake-2G.py

sleep 2

sudo python /home/pi/lora_gateway/3GDongle/loranga/serialtest.py

sleep 1

echo "Turn OFF 2G module"

sudo python /home/pi/lora_gateway/3GDongle/loranga/wake-2G.py

sleep 2

echo "Now testing if  LoRa Transceiver Detected"

sudo timeout 1 /home/pi/lora_gateway/lora_gateway

echo "Loranga2G test finished!"
