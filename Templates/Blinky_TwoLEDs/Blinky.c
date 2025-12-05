/*---------------------------------------------------------------------------
 * Copyright (c) 2025 Arm Limited (or its affiliates). All rights reserved.
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
 *
 *      Name:    Blinky.c
 *      Purpose: RTX example program
 *
 *---------------------------------------------------------------------------*/

#include "main.h"
#include "cmsis_os2.h"
#include "cmsis_vio.h"

static osThreadId_t tid_thrLED;                 // Thread id of thread: LED
static osThreadId_t tid_thrButton;              // Thread id of thread: Button

volatile     uint32_t g_ledSet = 0;             // Variable to store virtual LED value:
                                                // 0 = LED0 on,  LED1 off
                                                // 1 = LED0 on,  LED1 on
                                                // 2 = LED0 off, LED1 on
                                                // 3 = LED0 off, LED1 off

// Create thread attribute to show thread name in the XRTOS viewer:
static const osThreadAttr_t app_main_attr  = {.name = "MainThread"};
static const osThreadAttr_t thrLED_attr    = {.name = "LEDThread"};

/*-----------------------------------------------------------------------------
  thrLED: blink LED
 *----------------------------------------------------------------------------*/
static __NO_RETURN void thrLED (void *argument) {
  uint32_t active_flag = 0U;

  (void)argument;

  for (;;) {
      vioSetSignal(vioLED0, vioLEDon);          // Switch LED0 on
      g_ledSet = 0U;                            // LED0 on, LED1 off
      osDelay(500U);                            // Delay 500 ms
      vioSetSignal(vioLED1, vioLEDon);          // Switch LED1 on
      g_ledSet = 1U;                            // LED0 on, LED1 on
      osDelay(500U);                            // Delay 500 ms
      vioSetSignal(vioLED0, vioLEDoff);         // Switch LED0 off
      g_ledSet = 2U;                            // LED0 off, LED1 on
      osDelay(500U);                            // Delay 500 ms
      vioSetSignal(vioLED1, vioLEDoff);         // Switch LED1 off
      g_ledSet = 3U;                            // LED0 off, LED1 off
      osDelay(500U);                            // Delay 500 ms
  }
}

/*-----------------------------------------------------------------------------
  Application main thread
 *----------------------------------------------------------------------------*/
__NO_RETURN void app_main_thread (void *argument) {
  (void)argument;

  // Create LED and Button threads
  tid_thrLED    = osThreadNew(thread_LED, NULL, &thread_attr_LED);

  for (;;) {
    osDelay(osWaitForever);                     // Delay indefinitely
  }
}

/*-----------------------------------------------------------------------------
  Application initialization
 *----------------------------------------------------------------------------*/
int app_main (void) {
  osKernelInitialize();                         // Initialize CMSIS-RTOS2
  osThreadNew(app_main_thread, NULL, &app_main_attr);
  osKernelStart();                              // Start thread execution
  return 0;                                     // Should never reach here
}
