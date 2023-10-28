#!/bin/bash

# Read SSID from the first line of config.txt
read -r ssid < /home/islam_pi/GUI/build-FOTA_ver1-Desktop-Debug/WifiInformation.txt

read -r password < <(sed -n '2p' /home/islam_pi/GUI/build-FOTA_ver1-Desktop-Debug/WifiInformation.txt)


# Print the SSID and password
echo "SSID: $ssid"
echo "Password: $password"


# Connect to the specified SSID with the provided password
sudo nmcli device wifi connect "$ssid" password "$password"
