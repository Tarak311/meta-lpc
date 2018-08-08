#
# This file was derived from the 'Hello World!' example recipe in the
# Yocto Project Development Manual.
#

SUMMARY = "I2C temp application"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://tcpi2c.cpp"

S = "${WORKDIR}"

do_compile() {
	     ${CXX} ${LDFLAGS} tcpi2c.cpp  -o tcpi2c
}

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 tcpi2c ${D}${bindir}
}
