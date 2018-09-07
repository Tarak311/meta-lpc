#!/bin/sh

IPADDRESS0=192.168.2.40
IPADDRESS1=192.168.40.188
IPGATEWAY0=192.168.2.1
IPGATEWAY1=192.168.40.1
# This starts our network
ifconfig wlan0  up                                        
wpa_supplicant -Dnl80211 -iwlan0 -c/etc/wpa_supplicant.conf&           
ifconfig wlan0 $IPADDRESS0   
route add default gw $IPGATEWAY0
echo "nameserver 8.8.8.8">>/etc/resolv.conf

#This will setup out i2c-dev
modprobe i2c-dev

systemctl stop initscript.service
