/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_HAL_MULTI_CORE_H__
#define __TFM_HAL_MULTI_CORE_H__

#include <stdint.h>
#include "config_tfm.h"

/**
 * \brief Performs the necessary actions to start the non-secure CPU running
 *        the code at the specified address.
 *
 * \param[in] start_addr       The entry point address of non-secure code.
 */
void tfm_hal_boot_ns_cpu(uintptr_t start_addr);

/**
 * \brief Called on the secure CPU.
 *        Flags that the secure CPU has completed its initialization
 *        Waits, if necessary, for the non-secure CPU to flag that
 *        it has completed its initialisation
 */
void tfm_hal_wait_for_ns_cpu_ready(void);

#if CONFIG_TFM_PSA_CALL_ADDRESS_REMAP
/**
 * \brief Remap NS CPU address to the address space visible by the current CPU.
 *
 * \param[in] addr  Address in NS CPU view.
 *
 * \return Remapped address if remapping is required, otherwise the original
 *         address.
 */
void* tfm_hal_remap_ns_cpu_address(const void* addr);
#endif /* CONFIG_TFM_PSA_CALL_ADDRESS_REMAP */

#endif /* __TFM_HAL_MULTI_CORE_H__ */
