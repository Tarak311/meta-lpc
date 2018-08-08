SRC_URI += "file://spi1-2cs-overlay.dts;subdir=git/arch/${ARCH}/boot/dts/overlays"
SRC_URI += "git://github.com/Tarak311/linux-1.git;branch=linux-tarak"
FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRCREV = "${AUTOREV}"
PACKAGE_ARCH = "${MACHINE_ARCH}"

#KERNEL_DEVICETREE += "overlays/spi1-2cs-overlay.dtbo"
