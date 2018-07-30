#
# This file was derived from the 'Hello World!' example recipe in the
# Yocto Project Development Manual.
#

SUMMARY = "I2C temp application"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://i2ctemp.c"

S = "${WORKDIR}"

do_compile() {
	     ${CC} ${LDFLAGS} -Idir 	 /home/tarak/rpi/meta-lpc/recipes-i2ctemperature/i2ctemp/files/wiringPiI2C.c i2ctemp.c  	 -o i2ctemp
}

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 i2ctemp ${D}${bindir}
}
