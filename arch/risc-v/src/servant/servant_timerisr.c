/****************************************************************************
 * arch/risc-v/src/servant/servant_timerisr.c
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
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <time.h>
#include <debug.h>

#include <nuttx/arch.h>
#include <nuttx/clock.h>
#include <arch/board/board.h>

#include "riscv_arch.h"

#include "servant.h"
#include "servant_clockconfig.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define TICK_COUNT (servant_get_hfclk() / TICK_PER_SEC)

/****************************************************************************
 * Private Data
 ****************************************************************************/
uint32_t next_count;

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name:  servant_timerisr
 ****************************************************************************/

static int servant_timerisr(int irq, void *context, FAR void *arg)
{
  up_lowputc2('t');
  up_lowputc2('\n');
  uint32_t now;
  uint32_t next;
  irqstate_t flags = enter_critical_section();

  volatile uint32_t *timer = (uint32_t *)SERVANT_TIMER_BASE;
  now = *timer;

  next = now + TICK_COUNT;
  if (next < 10000)
    {
      next += 10000;
    }

  next_count = next;
  *timer = next;
  leave_critical_section(flags);

  nxsched_process_timer();
  return 0;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_timer_initialize
 *
 * Description:
 *   This function is called during start-up to initialize
 *   the timer interrupt.
 *
 ****************************************************************************/

void up_timer_initialize(void)
{
  volatile uint32_t *timer = (uint32_t *)SERVANT_TIMER_BASE;
  *timer = *timer + TICK_COUNT;

  irq_attach(SERVANT_IRQ_MTIMER, servant_timerisr, NULL);
  up_enable_irq(SERVANT_IRQ_MTIMER);
}
