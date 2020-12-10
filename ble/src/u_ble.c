/*
 * Copyright 2020 u-blox Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Only #includes of u_* and the C standard library are allowed here,
 * no platform stuff and no OS stuff.  Anything required from
 * the platform/OS must be brought in through u_port* to maintain
 * portability.
 */

/** @file
 * @brief Implementation of the "general" API for ble.
 */

#ifdef U_CFG_OVERRIDE
# include "u_cfg_override.h" // For a customer's configuration override
#endif

#include "stdlib.h"    // malloc() and free()
#include "stddef.h"    // NULL, size_t etc.
#include "stdint.h"    // int32_t etc.
#include "stdbool.h"

#include "u_error_common.h"

#include "u_at_client.h"
#include "u_short_range.h"

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * TYPES
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * STATIC VARIABLES
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * STATIC FUNCTIONS
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * PUBLIC FUNCTIONS
 * -------------------------------------------------------------- */

// Initialise the cellular driver.
int32_t uBleInit()
{
    return uShortRangeInit();
}

// Shut-down the cellular driver.
void uBleDeinit()
{
    uShortRangeDeinit();
}

// Add a cellular instance.
int32_t uBleAdd(uShortRangeModuleType_t moduleType,
                uAtClientHandle_t atHandle)
{
    return uShortRangeAdd(moduleType, atHandle);
}

// Remove a cellular instance.
void uBleRemove(int32_t bleHandle)
{
    uShortRangeRemove(bleHandle);
}

// Get the handle of the AT client.
int32_t uBleAtClientHandleGet(int32_t bleHandle,
                              uAtClientHandle_t *pAtHandle)
{
    return uShortRangeAtClientHandleGet(bleHandle, pAtHandle);
}

// End of file