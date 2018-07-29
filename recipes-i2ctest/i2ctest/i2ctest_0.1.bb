#
# This file was derived from the 'Hello World!' example recipe in the
# Yocto Project Development Manual.
#

SUMMARY = "I2C test application"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://i2ctest.c"

S = "${WORKDIR}"

do_compile() {
	     ${CC} ${LDFLAGS} i2ctest.c -o i2ctest
}

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 i2ctest ${D}${bindir}
}
