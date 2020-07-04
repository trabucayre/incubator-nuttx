/****************************************************************************
 * arch/arm/src/eoss3/eoss3_lowputc.c
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
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>

#include <arch/board/board.h>

#include "arm_internal.h"
#include "arm_arch.h"

#include "chip.h"

#include "eoss3.h"
#include "hardware/eoss3_uart.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: arm_lowputc
 *
 * Description:
 *   Output one byte on the serial console
 *
 ****************************************************************************/

void arm_lowputc(char ch)
{
  /* Wait until the TX data register is empty */

  while ((getreg32(EOSS3_UART_TFR) & UART_TFR_BUSY) == 0);

  /* Then send the character */

  putreg32((uint32_t)ch, EOSS3_UART_DR);

}

/****************************************************************************
 * Name: eoss3_lowsetup
 *
 * Description:
 *   This performs basic initialization of the UART used for the serial
 *   console.  Its purpose is to get the console output available as soon
 *   as possible.
 *
 ****************************************************************************/

void eoss3_lowsetup(void)
{
  uint32_t lcr;

  /* Configure the Baudrate
   * At this point we 9973760.0 clock on C11
   * Lets go ahead and configure the UART Baudrate to be 115200
   * This clocking configuration should probably be configured via
   * board settings but we are hard coding it all for now.
   * 
   * 9973760.0 * (1.0/115200) = 86.57777777777778
   * 
   * int = 86
   * frac = (86.57777777777778 - 86)*(2^6) = 37
   * 
   * act_div = 86 + 37 / 2^6 = 86.578125
   * act_baud = 9973760.0 / 86.578125 = 115199
   */

  putreg32(86, EOSS3_UART_IBRD);
  putreg32(37, EOSS3_UART_FBRD);

  /* Configure word length 8 bit */

  lcr = getreg32(EOSS3_UART_LCR_H);
  lcr &= ~UART_LCR_H_WLEN_MASK;
  lcr |= 0x3 << UART_LCR_H_WLEN_SHIFT;

  /* Enable Hardware */

  putreg32(0x3 << UART_LCR_H_WLEN_SHIFT, EOSS3_UART_CR);
  putreg32(UART_CR_UARTEN & UART_CR_TXE, EOSS3_UART_CR);
}