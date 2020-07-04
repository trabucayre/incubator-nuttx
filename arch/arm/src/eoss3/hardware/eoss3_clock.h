/****************************************************************************
 * arch/arm/src/eoss3/eoss3_clock.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *****************************************************************************/
 

#ifndef __ARCH_ARM_SRC_EOSS3_HARDWARE_EOSS3_CLOCK_H
#define __ARCH_ARM_SRC_EOSS3_HARDWARE_EOSS3_CLOCK_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include "chip.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register Offsets *********************************************************/

#define EOSS3_CLK_CONTROL_A_0_OFFSET    0x0004  /* Clock 10 Divisor */
#define EOSS3_CLK_CONTROL_A_1_OFFSET    0x0008  /* Clock 10 Clock Src Ctrl */
#define EOSS3_CLK_CONTROL_B_0_OFFSET    0x0010  /* Clock 2 Divisor */
#define EOSS3_CLK_CONTROL_C_0_OFFSET    0x0014  /* Clock 8 Divisor */
#define EOSS3_CLK_CONTROL_D_0_OFFSET    0x0018  /* Clock 11 Divisor */
#define EOSS3_CLK_CONTROL_E_0_OFFSET    0x0020  /* Clock 12 Divisor */
#define EOSS3_CLK_CONTROL_F_0_OFFSET    0x0024  /* Clock 16 Divisor */
#define EOSS3_CLK_CONTROL_F_1_OFFSET    0x0028  /* Clock 16 Clock Src Ctrl */
#define EOSS3_CLK_CONTROL_G_0_OFFSET    0x002c  /* Clock 30 Divisor */
#define EOSS3_CLK_CONTROL_H_0_OFFSET    0x0034  /* Clock 19 Divisor */
#define EOSS3_CLK_CONTROL_I_1_OFFSET    0x0038  /* Clock 21 Clock Src Ctrl */
#define EOSS3_CLK_HS_CLK_SOURCE_OFFSET  0x003c  /* HS Clock Selection Pin */
#define EOSS3_CLK_C01_GATE_OFFSET       0x0040  /* Clock 1 Gating Ctrl */
#define EOSS3_CLK_C02_GATE_OFFSET       0x0044  /* Clock 2 Gating Ctrl */
#define EOSS3_CLK_C08_X4_GATE_OFFSET    0x0048  /* Clock 8 X4 Gating Ctrl */
#define EOSS3_CLK_C08_X1_GATE_OFFSET    0x004c  /* Clock 8 X1 Gating Ctrl */
#define EOSS3_CLK_C10_GATE_OFFSET       0x0050  /* Clock 10 Gating Ctrl */
#define EOSS3_CLK_C11_GATE_OFFSET       0x0054  /* Clock 111 Gating Ctrl */
#define EOSS3_CLK_CS_GATE_OFFSET        0x005c  /* Clock S Gating Ctrl */
#define EOSS3_CLK_C16_GATE_OFFSET       0x0064  /* Clock 16 Gating Ctrl */
#define EOSS3_CLK_C19_GATE_OFFSET       0x006c  /* Clock 19 Gating Ctrl */
#define EOSS3_CLK_C21_GATE_OFFSET       0x0070  /* Clock 21 Gating Ctrl */
#define EOSS3_CLK_PF_SW_RESET_OFFSET    0x0080  /* Software Rest PF Block */
#define EOSS3_CLK_FFE_SW_RESET_OFFSET   0x0084  /* Software Reset FFE Block */
#define EOSS3_CLK_FB_SW_RESET_OFFSET    0x0088  /* Software Reset FB Block */
#define EOSS3_CLK_A1_SW_RESET_OFFSET    0x008c  /* Software Reset A1 Block */

#define EOSS3_CLK_AUDIO_MISC_SW_RESET_OFFSET   0x0090  /* SW Rst Audio MISC */
#define EOSS3_CLK_FB_MISC_SW_RST_CTL_OFFSET    0x0094  /* SW Rst FB MISC */

#define EOSS3_CLK_CONTROL_PMU_OFFSET    0x0100  /* PMU Clock Gating Ctrl */
#define EOSS3_CLK_CRU_GENERAL_OFFSET    0x0104  /* SPICLK Always On Ctrl */
#define EOSS3_CLK_CRU_DEBUG_OFFSET      0x0108  /* Debug Select */
#define EOSS3_CLK_C01_DIV_OFFSET        0x0110  /* Clock 1 Divider Ctrl */
#define EOSS3_CLK_C09_DIV_OFFSET        0x0114  /* Clock 9 Divider Ctrl */
#define EOSS3_CLK_C31_DIV_OFFSET        0x0118  /* Clock 31 Divider Ctrl */
#define EOSS3_CLK_C09_GATE_OFFSET       0x011c  /* Clock 9 Gating Ctrl */
#define EOSS3_CLK_C30_C31_GATE_OFFSET   0x0120  /* Clock 30/31 Gating Ctrl */

#define EOSS3_CLK_DIVIDER_CLK_GATING_OFFSET  0x0124  /* Clk DIV Clk Gating */

#define EOSS3_CLK_SWITCH_FOR_B_OFFSET   0x0130  /* Clock 2 Source Ctrl */
#define EOSS3_CLK_SWITCH_FOR_C_OFFSET   0x0134  /* Clock 8 Source Ctrl */
#define EOSS3_CLK_SWITCH_FOR_D_OFFSET   0x0138  /* Clock 11 Source Ctrl */
#define EOSS3_CLK_SWITCH_FOR_H_OFFSET   0x013c  /* Clock 19 Source Ctrl */
#define EOSS3_CLK_SWITCH_FOR_J_OFFSET   0x0140  /* Clock 23 Source Ctrl */
#define EOSS3_CLK_SWITCH_FOR_G_OFFSET   0x0144  /* Clock 30 Source Ctrl */

/* Register Addresses *******************************************************/

#define EOSS3_UART_DR             (EOSS3_CLK_BASE + EOSS3_UART_DR_OFFSET)
#define EOSS3_CLK_CONTROL_A_0     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_A_0_OFFSET)
#define EOSS3_CLK_CONTROL_A_1     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_A_1_OFFSET)
#define EOSS3_CLK_CONTROL_B_0     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_B_0_OFFSET)
#define EOSS3_CLK_CONTROL_C_0     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_C_0_OFFSET)
#define EOSS3_CLK_CONTROL_D_0     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_D_0_OFFSET)
#define EOSS3_CLK_CONTROL_E_0     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_E_0_OFFSET)
#define EOSS3_CLK_CONTROL_F_0     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_F_0_OFFSET)
#define EOSS3_CLK_CONTROL_F_1     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_F_1_OFFSET)
#define EOSS3_CLK_CONTROL_G_0     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_G_0_OFFSET)
#define EOSS3_CLK_CONTROL_H_0     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_H_0_OFFSET)
#define EOSS3_CLK_CONTROL_I_1     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_I_1_OFFSET)
#define EOSS3_CLK_HS_CLK_SOURCE   (EOSS3_CLK_BASE + EOSS3_CLK_HS_CLK_SOURCE_OFFSET)
#define EOSS3_CLK_C01_GATE        (EOSS3_CLK_BASE + EOSS3_CLK_C01_GATE_OFFSET)
#define EOSS3_CLK_C02_GATE        (EOSS3_CLK_BASE + EOSS3_CLK_C02_GATE_OFFSET)
#define EOSS3_CLK_C08_X4_GATE     (EOSS3_CLK_BASE + EOSS3_CLK_C08_X4_GATE_OFFSET)
#define EOSS3_CLK_C08_X1_GATE     (EOSS3_CLK_BASE + EOSS3_CLK_C08_X1_GATE_OFFSET)
#define EOSS3_CLK_C10_GATE        (EOSS3_CLK_BASE + EOSS3_CLK_C10_GATE_OFFSET)
#define EOSS3_CLK_C11_GATE        (EOSS3_CLK_BASE + EOSS3_CLK_C11_GATE_OFFSET)
#define EOSS3_CLK_CS_GATE         (EOSS3_CLK_BASE + EOSS3_CLK_CS_GATE_OFFSET)
#define EOSS3_CLK_C16_GATE        (EOSS3_CLK_BASE + EOSS3_CLK_C16_GATE_OFFSET)
#define EOSS3_CLK_C19_GATE        (EOSS3_CLK_BASE + EOSS3_CLK_C19_GATE_OFFSET)
#define EOSS3_CLK_C21_GATE        (EOSS3_CLK_BASE + EOSS3_CLK_C21_GATE_OFFSET)
#define EOSS3_CLK_PF_SW_RESET     (EOSS3_CLK_BASE + EOSS3_CLK_PF_SW_RESET_OFFSET)
#define EOSS3_CLK_FFE_SW_RESET    (EOSS3_CLK_BASE + EOSS3_CLK_FFE_SW_RESET_OFFSET)
#define EOSS3_CLK_FB_SW_RESET     (EOSS3_CLK_BASE + EOSS3_CLK_FB_SW_RESET_OFFSET)
#define EOSS3_CLK_A1_SW_RESET     (EOSS3_CLK_BASE + EOSS3_CLK_A1_SW_RESET_OFFSET)


#define EOSS3_CLK_AUDIO_MISC_SW_RESET  (EOSS3_CLK_BASE + EOSS3_CLK_AUDIO_MISC_SW_RESET_OFFSET)
#define EOSS3_CLK_FB_MISC_SW_RST_CTL   (EOSS3_CLK_BASE + EOSS3_CLK_FB_MISC_SW_RST_CTL_OFFSET)

#define EOSS3_CLK_CONTROL_PMU     (EOSS3_CLK_BASE + EOSS3_CLK_CONTROL_PMU_OFFSET)
#define EOSS3_CLK_CRU_GENERAL     (EOSS3_CLK_BASE + EOSS3_CLK_CRU_GENERAL_OFFSET)
#define EOSS3_CLK_CRU_DEBUG       (EOSS3_CLK_BASE + EOSS3_CLK_CRU_DEBUG_OFFSET)
#define EOSS3_CLK_C01_DIV         (EOSS3_CLK_BASE + EOSS3_CLK_C01_DIV_OFFSET)
#define EOSS3_CLK_C09_DIV         (EOSS3_CLK_BASE + EOSS3_CLK_C09_DIV_OFFSET)
#define EOSS3_CLK_C31_DIV         (EOSS3_CLK_BASE + EOSS3_CLK_C31_DIV_OFFSET)
#define EOSS3_CLK_C09_GATE        (EOSS3_CLK_BASE + EOSS3_CLK_C09_GATE_OFFSET)
#define EOSS3_CLK_C30_C31_GATE    (EOSS3_CLK_BASE + EOSS3_CLK_C30_C31_GATE_OFFSET)

#define EOSS3_CLK_DIVIDER_CLK_GATING  (EOSS3_CLK_BASE + EOSS3_CLK_DIVIDER_CLK_GATING_OFFSET)

#define EOSS3_CLK_SWITCH_FOR_B    (EOSS3_CLK_BASE + EOSS3_CLK_SWITCH_FOR_B)
#define EOSS3_CLK_SWITCH_FOR_C    (EOSS3_CLK_BASE + EOSS3_CLK_SWITCH_FOR_C)
#define EOSS3_CLK_SWITCH_FOR_D    (EOSS3_CLK_BASE + EOSS3_CLK_SWITCH_FOR_D)
#define EOSS3_CLK_SWITCH_FOR_H    (EOSS3_CLK_BASE + EOSS3_CLK_SWITCH_FOR_H)
#define EOSS3_CLK_SWITCH_FOR_J    (EOSS3_CLK_BASE + EOSS3_CLK_SWITCH_FOR_J)
#define EOSS3_CLK_SWITCH_FOR_G    (EOSS3_CLK_BASE + EOSS3_CLK_SWITCH_FOR_G)

/* Register Bitfield Definitions ********************************************/

#endif /* __ARCH_ARM_SRC_EOSS3_HARDWARE_EOSS3_CLOCK_H */
