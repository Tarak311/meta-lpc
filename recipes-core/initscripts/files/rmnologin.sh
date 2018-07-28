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

# This starts our network
ifconfig wlan0  up                                        
wpa_supplicant -Dnl80211 -iwlan0 -c/etc/wpa_supplicant.conf&           
ifconfig wlan0 192.168.2.40   

#This will setup out i2c-dev
modprobe i2c-dev


if test -f /etc/nologin.boot
then
	rm -f /etc/nologin /etc/nologin.boot
fi

: exit 0
