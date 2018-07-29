SUMMARY = "I2C test application"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://i2c-t.c"

S = "${WORKDIR}"

do_compile() {
             ${CC} ${LDFLAGS} i2c-t.c -o i2ct
             }

do_install() {
             install -d ${D}${bindir}
             install -m 0755 spitest ${D}${bindir}
}
