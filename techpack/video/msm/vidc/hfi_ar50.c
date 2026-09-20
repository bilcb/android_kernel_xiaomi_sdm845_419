// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2019, The Linux Foundation. All rights reserved.
 */

#include "msm_vidc_debug.h"
#include "hfi_common.h"

#define VIDC_CPU_BASE_OFFS_AR50		0x000C0000

#define VIDC_CPU_CS_BASE_OFFS_AR50		(VIDC_CPU_BASE_OFFS_AR50 + 0x00012000)
#define VIDC_CPU_IC_BASE_OFFS_AR50		(VIDC_CPU_BASE_OFFS_AR50 + 0x0001F000)

#define VIDC_CPU_CS_A2HSOFTINTCLR_AR50	(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x1C)

#define VIDC_CPU_CS_SCIACMD_AR50		(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x48)

/* HFI_CTRL_STATUS */
#define VIDC_CPU_CS_SCIACMDARG0_AR50		(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x4C)
#define VIDC_CPU_CS_SCIACMDARG0_HFI_CTRL_ERROR_STATUS_BMSK_AR50	0xfe
#define VIDC_CPU_CS_SCIACMDARG0_HFI_CTRL_PC_READY_AR50		0x100
#define VIDC_CPU_CS_SCIACMDARG0_HFI_CTRL_INIT_IDLE_MSG_BMSK_AR50	0x40000000

/* HFI_QTBL_INFO */
#define VIDC_CPU_CS_SCIACMDARG1_AR50		(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x50)

/* HFI_QTBL_ADDR */
#define VIDC_CPU_CS_SCIACMDARG2_AR50		(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x54)

/* HFI_VERSION_INFO */
#define VIDC_CPU_CS_SCIACMDARG3_AR50		(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x58)

/* VIDC_SFR_ADDR */
#define VIDC_CPU_CS_SCIBCMD_AR50		(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x5C)

/* VIDC_MMAP_ADDR */
#define VIDC_CPU_CS_SCIBCMDARG0_AR50	(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x60)

/* VIDC_UC_REGION_ADDR */
#define VIDC_CPU_CS_SCIBARG1_AR50		(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x64)

/* VIDC_UC_REGION_SIZE */
#define VIDC_CPU_CS_SCIBARG2_AR50		(VIDC_CPU_CS_BASE_OFFS_AR50 + 0x68)

#define VIDC_CPU_IC_SOFTINT_AR50		(VIDC_CPU_IC_BASE_OFFS_AR50 + 0x18)
#define VIDC_CPU_IC_SOFTINT_H2A_SHFT_AR50	0xF

/*
 * --------------------------------------------------------------------------
 * MODULE: vidc_wrapper
 * --------------------------------------------------------------------------
 */
#define VIDC_WRAPPER_BASE_OFFS_AR50		0x000E0000

#define VIDC_WRAPPER_INTR_STATUS_AR50	(VIDC_WRAPPER_BASE_OFFS_AR50 + 0x0C)
#define VIDC_WRAPPER_INTR_STATUS_A2HWD_BMSK_AR50	0x10
#define VIDC_WRAPPER_INTR_STATUS_A2H_BMSK_AR50	0x4

#define VIDC_WRAPPER_INTR_MASK_AR50		(VIDC_WRAPPER_BASE_OFFS_AR50 + 0x10)
#define VIDC_WRAPPER_INTR_MASK_A2HVCODEC_BMSK_AR50	0x8

#define VIDC_WRAPPER_INTR_CLEAR_AR50		(VIDC_WRAPPER_BASE_OFFS_AR50 + 0x14)

#define VIDC_WRAPPER_CPU_STATUS_AR50	(VIDC_WRAPPER_BASE_OFFS_AR50 + 0x2014)

#define VIDC_CTRL_INIT_AR50			VIDC_CPU_CS_SCIACMD_AR50

#define VIDC_CTRL_STATUS_AR50		VIDC_CPU_CS_SCIACMDARG0_AR50
#define VIDC_CTRL_ERROR_STATUS__M_AR50 \
		VIDC_CPU_CS_SCIACMDARG0_HFI_CTRL_ERROR_STATUS_BMSK_AR50
#define VIDC_CTRL_INIT_IDLE_MSG_BMSK_AR50 \
		VIDC_CPU_CS_SCIACMDARG0_HFI_CTRL_INIT_IDLE_MSG_BMSK_AR50
#define VIDC_CTRL_STATUS_PC_READY_AR50 \
		VIDC_CPU_CS_SCIACMDARG0_HFI_CTRL_PC_READY_AR50

#define VIDC_QTBL_INFO_AR50			VIDC_CPU_CS_SCIACMDARG1_AR50
#define VIDC_QTBL_ADDR_AR50			VIDC_CPU_CS_SCIACMDARG2_AR50
#define VIDC_VERSION_INFO_AR50		VIDC_CPU_CS_SCIACMDARG3_AR50

#define VIDC_SFR_ADDR_AR50			VIDC_CPU_CS_SCIBCMD_AR50
#define VIDC_MMAP_ADDR_AR50			VIDC_CPU_CS_SCIBCMDARG0_AR50
#define VIDC_UC_REGION_ADDR_AR50		VIDC_CPU_CS_SCIBARG1_AR50
#define VIDC_UC_REGION_SIZE_AR50		VIDC_CPU_CS_SCIBARG2_AR50

void __interrupt_init_ar50(struct venus_hfi_device *device, u32 sid)
{
	__write_register(device, VIDC_WRAPPER_INTR_MASK_AR50,
		VIDC_WRAPPER_INTR_MASK_A2HVCODEC_BMSK_AR50, sid);
}

void __setup_ucregion_memory_map_ar50(struct venus_hfi_device *device, u32 sid)
{
	__write_register(device, VIDC_UC_REGION_ADDR_AR50,
			(u32)device->iface_q_table.align_device_addr, sid);
	__write_register(device, VIDC_UC_REGION_SIZE_AR50, SHARED_QSIZE, sid);
	__write_register(device, VIDC_QTBL_ADDR_AR50,
			(u32)device->iface_q_table.align_device_addr, sid);
	__write_register(device, VIDC_QTBL_INFO_AR50, 0x01, sid);
	if (device->sfr.align_device_addr)
		__write_register(device, VIDC_SFR_ADDR_AR50,
				(u32)device->sfr.align_device_addr, sid);
	if (device->qdss.align_device_addr)
		__write_register(device, VIDC_MMAP_ADDR_AR50,
				(u32)device->qdss.align_device_addr, sid);
}

void __power_off_ar50(struct venus_hfi_device *device)
{
	if (!device->power_enabled)
		return;

	if (!(device->intr_status & VIDC_WRAPPER_INTR_STATUS_A2HWD_BMSK_AR50))
		disable_irq_nosync(device->hal_data->irq);
	device->intr_status = 0;

	__disable_unprepare_clks(device);
	if (call_venus_op(device, reset_ahb2axi_bridge, device,
		DEFAULT_SID))
		d_vpr_e("Failed to reset ahb2axi\n");

	if (__disable_regulators(device))
		d_vpr_e("Failed to disable regulators\n");

	if (__unvote_buses(device, DEFAULT_SID))
		d_vpr_e("Failed to unvote for buses\n");
	device->power_enabled = false;
}

int __prepare_pc_ar50(struct venus_hfi_device *device)
{
	int rc = 0;
	u32 wfi_status = 0, idle_status = 0, pc_ready = 0;
	u32 ctrl_status = 0;
	int count = 0;
	const int max_tries = 10;

	ctrl_status = __read_register(device, VIDC_CTRL_STATUS_AR50, DEFAULT_SID);
	pc_ready = ctrl_status & VIDC_CTRL_STATUS_PC_READY_AR50;
	idle_status = ctrl_status & BIT(30);

	if (pc_ready) {
		d_vpr_h("Already in pc_ready state\n");
		return 0;
	}

	wfi_status = BIT(0) & __read_register(device,
			VIDC_WRAPPER_CPU_STATUS_AR50, DEFAULT_SID);
	if (!wfi_status || !idle_status) {
		d_vpr_e("Skipping PC, wfi status not set\n");
		goto skip_power_off;
	}

	rc = __prepare_pc(device);
	if (rc) {
		d_vpr_e("Failed __prepare_pc %d\n", rc);
		goto skip_power_off;
	}

	while (count < max_tries) {
		wfi_status = BIT(0) & __read_register(device,
				VIDC_WRAPPER_CPU_STATUS_AR50, DEFAULT_SID);
		ctrl_status = __read_register(device,
				VIDC_CTRL_STATUS_AR50, DEFAULT_SID);
		if (wfi_status &&
			(ctrl_status & VIDC_CTRL_STATUS_PC_READY_AR50))
			break;
		usleep_range(150, 250);
		count++;
	}

	if (count == max_tries) {
		d_vpr_e("Skip PC. Core is not in right state\n");
		goto skip_power_off;
	}

	return rc;

skip_power_off:
	d_vpr_e("Skip PC, wfi=%#x, idle=%#x, pcr=%#x, ctrl=%#x)\n",
		wfi_status, idle_status, pc_ready, ctrl_status);
	return -EAGAIN;
}

void __raise_interrupt_ar50(struct venus_hfi_device *device, u32 sid)
{
	__write_register(device, VIDC_CPU_IC_SOFTINT_AR50,
		1 << VIDC_CPU_IC_SOFTINT_H2A_SHFT_AR50, sid);
}

void __core_clear_interrupt_ar50(struct venus_hfi_device *device)
{
	u32 intr_status = 0, mask = 0;

	if (!device) {
		d_vpr_e("%s: NULL device\n", __func__);
		return;
	}

	intr_status = __read_register(device, VIDC_WRAPPER_INTR_STATUS_AR50, DEFAULT_SID);
	mask = (VIDC_WRAPPER_INTR_STATUS_A2H_BMSK_AR50 |
		VIDC_WRAPPER_INTR_STATUS_A2HWD_BMSK_AR50 |
		VIDC_CTRL_INIT_IDLE_MSG_BMSK_AR50);

	if (intr_status & mask) {
		device->intr_status |= intr_status;
		device->reg_count++;
		d_vpr_l("INTERRUPT: times: %d interrupt_status: %d\n",
			device->reg_count, intr_status);
	} else {
		device->spur_count++;
	}

	__write_register(device, VIDC_CPU_CS_A2HSOFTINTCLR_AR50, 1, DEFAULT_SID);
	__write_register(device, VIDC_WRAPPER_INTR_CLEAR_AR50, intr_status, DEFAULT_SID);
}

int __boot_firmware_ar50(struct venus_hfi_device *device, u32 sid)
{
	int rc = 0;
	u32 ctrl_init_val = 0, ctrl_status = 0, count = 0, max_tries = 1000;

	ctrl_init_val = BIT(0);
	if (device->res->cvp_internal)
		ctrl_init_val |= BIT(1);

	__write_register(device, VIDC_CTRL_INIT_AR50, ctrl_init_val, sid);
	while (!ctrl_status && count < max_tries) {
		ctrl_status = __read_register(device, VIDC_CTRL_STATUS_AR50, sid);
		if ((ctrl_status & VIDC_CTRL_ERROR_STATUS__M_AR50) == 0x4) {
			s_vpr_e(sid, "invalid setting for UC_REGION\n");
			break;
		}
		usleep_range(50, 100);
		count++;
	}

	if (count >= max_tries) {
		s_vpr_e(sid, "Error booting up vidc firmware\n");
		rc = -ETIME;
	}

	return rc;
}
