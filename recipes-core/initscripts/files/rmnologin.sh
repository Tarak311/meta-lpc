#!/bin/sh
##v1
### BEGIN INIT INFO
# Provides:          rmnologin
# Required-Start:    $remote_fs $all
# Required-Stop: 
# Default-Start:     2 3 4 5
# Default-Stop:
# Short-Description: Remove /etc/nologin at boot
# Description:       This script removes the /etc/nologin file as the
#                    last step in the boot process, if DELAYLOGIN=yes.
#                    If DELAYLOGIN=no, /etc/nologin was not created by
#                    bootmisc earlier in the boot process.
### END INIT INFO
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


if test -f /etc/nologin.boot
then
	rm -f /etc/nologin /etc/nologin.boot
fi

: exit 0
