/*-----------------------------------------------------------------------------
 * Copyright (c) 2023-2026 Arm Limited (or its affiliates).
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
 *
 *      Name:    main.c
 *      Purpose: Print a few lines so you can quickly verify that:
 *               - startup code runs correctly,
 *               - clocks/stack/heap are sane,
 *               - and stdout routing is configured as expected.
 *
 *---------------------------------------------------------------------------*/

#include "RTE_Components.h"
#include CMSIS_device_header
#include "cmsis_os2.h"
#include <stdio.h>
#include <stdlib.h>

static   osThreadId_t tid_thrPRINTF;       // Thread id of thread: thrPRINTF

// Create thread attribute to show thread name in the XRTOS viewer:
const osThreadAttr_t app_main_attr  = {.name = "MainThread"};
const osThreadAttr_t thrPRINTF_attr = {.name = "PrintfThread"};

/*---------------------------------------------------------------------------
  thrPRINTF: Print message thread
 *---------------------------------------------------------------------------*/
static void thrPRINTF (void *arg) {

  (void)arg;

  for(int count = 0; count<10; count++) {
    printf ("Hello, Codespaces! %d\r\n", count);
    osDelay (1000);
  }
  printf("Simulation complete – shutting down via semihosting.\n");
  exit(0);                              // clean FVP shutdown via SYS_EXIT
}

/*---------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
static void app_main_thread (void *argument) {
  (void)argument;

  tid_thrPRINTF = osThreadNew(thrPRINTF, NULL, &thrPRINTF_attr);         // Create PRINTF thread
  if (tid_thrPRINTF == NULL) { /* add error handling */ }

  for (;;) {                            // Loop forever
  }
}

/*-----------------------------------------------------------------------------
 * Application initialization
 *----------------------------------------------------------------------------*/
int main (void) {
  osKernelInitialize();                         // Initialize CMSIS-RTOS2
  osThreadNew(app_main_thread, NULL, &app_main_attr);  // Create application main thread
  osKernelStart();                              // Start thread execution
  return 0;
}
