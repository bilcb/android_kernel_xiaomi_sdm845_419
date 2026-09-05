# SPDX-License-Identifier: GPL-2.0

ifeq ($(CONFIG_BUILD_ARM64_DT_OVERLAY),y)
#	dtbo-$(CONFIG_ARCH_SDM845) += \
		sdm845-mtp-overlay.dtbo \
		sdm845-v2-mtp-overlay.dtbo \
		sdm845-v2.1-mtp-overlay.dtbo

	dtbo-$(CONFIG_MACH_XIAOMI_D5X) += \
		polaris/polaris-p0-overlay.dtbo  \
		polaris/polaris-p0-v2-overlay.dtbo \
		polaris/polaris-p1-overlay.dtbo  \
		polaris/polaris-p1-v2-overlay.dtbo \
		polaris/polaris-p1-v2.1-overlay.dtbo \
		polaris/polaris-p2-overlay.dtbo  \
		polaris/polaris-p2-v2-overlay.dtbo \
		polaris/polaris-p2-v2.1-overlay.dtbo \
		polaris/polaris-p3-overlay.dtbo  \
		polaris/polaris-p3-v2-overlay.dtbo \
		polaris/polaris-p3-v2.1-overlay.dtbo

	dtbo-$(CONFIG_MACH_XIAOMI_E1N) += \
		dipper/dipper-p0-v2-overlay.dtbo \
		dipper/dipper-p0-v2.1-overlay.dtbo \

	dtbo-$(CONFIG_MACH_XIAOMI_E10) += \
		beryllium/beryllium-p0-v2-overlay.dtbo \
		beryllium/beryllium-p0-v2.1-overlay.dtbo

	dtbo-$(CONFIG_MACH_XIAOMI_E5) += \
		perseus/perseus-p0-v2.1-overlay.dtbo \
		perseus/perseus-p1-v2.1-overlay.dtbo \
		perseus/perseus-p1_2-v2.1-overlay.dtbo \
		perseus/perseus-p2-v2.1-overlay.dtbo \
		perseus/perseus-p3-v2.1-overlay.dtbo \
		perseus/perseus-mp-v2.1-overlay.dtbo

#sdm845-mtp-overlay.dtbo-base := sdm845.dtb
#sdm845-v2-mtp-overlay.dtbo-base := sdm845-v2.dtb
#sdm845-v2.1-mtp-overlay.dtbo-base := sdm845-v2.1.dtb

polaris/polaris-p0-overlay.dtbo-base := sdm845.dtb
polaris/polaris-p0-v2-overlay.dtbo-base := sdm845-v2.dtb
polaris/polaris-p1-overlay.dtbo-base := sdm845.dtb
polaris/polaris-p1-v2-overlay.dtbo-base := sdm845-v2.dtb
polaris/polaris-p1-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb
polaris/polaris-p2-overlay.dtbo-base := sdm845.dtb
polaris/polaris-p2-v2-overlay.dtbo-base := sdm845-v2.dtb
polaris/polaris-p2-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb
polaris/polaris-p3-overlay.dtbo-base := sdm845.dtb
polaris/polaris-p3-v2-overlay.dtbo-base := sdm845-v2.dtb
polaris/polaris-p3-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb

dipper/dipper-p0-v2-overlay.dtbo-base := sdm845-v2.dtb
dipper/dipper-p0-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb
dipper/dipper-p1-v2-overlay.dtbo-base := sdm845-v2.dtb
dipper/dipper-p1-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb
dipper/dipper-p2-v2-overlay.dtbo-base := sdm845-v2.dtb
dipper/dipper-p2-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb

beryllium/beryllium-p0-v2-overlay.dtbo-base := sdm845-v2.dtb
beryllium/beryllium-p0-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb

perseus/perseus-p0-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb
perseus/perseus-p1-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb
perseus/perseus-p1_2-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb
perseus/perseus-p2-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb
perseus/perseus-p3-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb
perseus/perseus-mp-v2.1-overlay.dtbo-base := sdm845-v2.1.dtb

else

#dtb-$(CONFIG_ARCH_SDM845) += \
	sdm845-mtp.dtb \
	sdm845-v2-mtp.dtb \
	sdm845-v2.1-mtp.dtb

dtb-$(CONFIG_MACH_XIAOMI_D5X) += \
	polaris/polaris-p0.dtb \
	polaris/polaris-p0-v2.dtb \
	polaris/polaris-p1.dtb \
	polaris/polaris-p1-v2.dtb \
	polaris/polaris-p1-v2.1.dtb \
	polaris/polaris-p2.dtb \
	polaris/polaris-p2-v2.dtb \
	polaris/polaris-p2-v2.1.dtb \
	polaris/polaris-p3.dtb \
	polaris/polaris-p3-v2.dtb \
	polaris/polaris-p3-v2.1.dtb \
	polaris/polaris-mp.dtb \
	polaris/polaris-mp-v2.dtb \
	polaris/polaris-mp-v2.1.dtb

dtb-$(CONFIG_MACH_XIAOMI_E1N) += \
	dipper/dipper-p0-v2.dtb \
	dipper/dipper-p0-v2.1.dtb \
	dipper/dipper-p1-v2-cn.dtb \
	dipper/dipper-p1-v2.1-cn.dtb \
	dipper/dipper-p1-v2-gb.dtb \
	dipper/dipper-p1-v2.1-gb.dtb \
	dipper/dipper-p1.1-v2.dtb \
	dipper/dipper-p1.1-v2.1.dtb \
	dipper/dipper-p2-v2.dtb \
	dipper/dipper-p2-v2.1.dtb \
	dipper/dipper-mp-v2.dtb \
	dipper/dipper-mp-v2.1.dtb

dtb-$(CONFIG_MACH_XIAOMI_E10) += \
	beryllium/beryllium-p0-v2.dtb \
	beryllium/beryllium-p0-v2.1.dtb \
	beryllium/beryllium-p1-v2.1.dtb \
	beryllium/beryllium-p2-v2.1.dtb \
	beryllium/beryllium-mp-v2.1.dtb

dtb-$(CONFIG_MACH_XIAOMI_E1S) += \
	equuleus/equuleus-p0-v2.dtb \
	equuleus/equuleus-p0-v2.1.dtb \
	equuleus/equuleus-p1-v2.dtb \
	equuleus/equuleus-p1-v2.1.dtb \
	equuleus/equuleus-mp-v2.dtb \
	equuleus/equuleus-mp-v2.1.dtb

dtb-$(CONFIG_MACH_XIAOMI_E8) += \
	ursa/ursa-p0-v2.dtb \
	ursa/ursa-p0-v2.1.dtb \
	ursa/ursa-p1-v2.dtb \
	ursa/ursa-p1-v2.1.dtb \
	ursa/ursa-p2-v2.dtb \
	ursa/ursa-p2-v2.1.dtb \
	ursa/ursa-mp-v2.dtb \
	ursa/ursa-mp-v2.1.dtb

dtb-$(CONFIG_MACH_XIAOMI_E5) += \
	perseus/perseus-p0-v2.dtb \
	perseus/perseus-p0-v2.1.dtb \
	perseus/perseus-p1-v2.1.dtb \
	perseus/perseus-p1_2-v2.1.dtb \
	perseus/perseus-p2-v2.1.dtb \
	perseus/perseus-p3-v2.1.dtb \
	perseus/perseus-mp-v2.1.dtb
endif

always		:= $(dtb-y)
subdir-y	:= $(dts-dirs)
clean-files    := *.dtb *.dtbo
