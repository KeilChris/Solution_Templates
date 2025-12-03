/******************************************************************************
 * @file     vio_XYZ.c
 * @brief    Virtual I/O implementation for board XYZ
 * @version  V1.0.0
 * @date     26. November 2025
 ******************************************************************************/
/*
 * Copyright (c) 2021-2025 Arm Limited (or its affiliates).
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*! \page vio_XYZ Physical I/O Mapping

The table below lists the physical I/O mapping of this CMSIS-Driver VIO implementation.

Virtual Resource  | Variable       | Physical Resource on XYZ   |
:-----------------|:---------------|:---------------------------|
vioLED0           | vioSignalOut.0 | tbd                        |
vioLED1           | vioSignalOut.1 | tbd                        |
*/

#include "cmsis_vio.h"

#include "RTE_Components.h"
#include CMSIS_device_header

// VIO input, output definitions
#define VIO_VALUE_NUM           1U          // Number of values

// VIO input, output variables
__USED uint32_t vioSignalOut;               // Memory for outgoing signal
__USED int32_t  vioValue[VIO_VALUE_NUM];    // Memory for value used in vioGetValue/vioSetValue

// Initialize test input, output.
void vioInit(void) {
  vioSignalOut = 0U;

  memset(vioValue, 0, sizeof(vioValue));
}


// Set signal output.
void vioSetSignal (uint32_t mask, uint32_t signal) {
  vioSignalOut &= ~mask;
  vioSignalOut |=  mask & signal;

}

// Add other VIO API functions as needed (e.g., vioPrint, vioGetIPv4, etc.)
