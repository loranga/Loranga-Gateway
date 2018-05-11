# Loranga

- Download image from WAZIUP page
- Burn image with Etcher on a SD card (more than 8 Gb)
- Boot with keyboard and screen
- CTRL+ALT+T open terminal
  - It will open a command screen
  - Enter option K -> Kill all GW related process
  - Enter option Q -> Quit

- Enter 'sudo raspi-config'
  - Change keyboard lyout (default French)
  - Enable SSH
    - Select Interfacing Options
		- Navigate to and select SSH
		- Choose Yes
		- Select Ok
		- Choose Finish
- Disable Access Point
  - Enter './scripts/stop_access_point.sh'
- Configure wifi
