/*
 *  RTEMS SMP Support for Single Core
 *
 *  COPYRIGHT (c) 1989-2011.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#include <rtems.h>
#include <bsp.h>
#include <rtems/bspIo.h>
#include <rtems/bspsmp.h>
#include <stdlib.h>

void bsp_smp_secondary_cpu_initialize(int cpu)
{
}

uint32_t bsp_smp_initialize( uint32_t configured_cpu_count )
{
  /* return the number of CPUs */
  return 1;
}

void bsp_smp_broadcast_interrupt(void)
{
}

void bsp_smp_broadcast_message(
  uint32_t  message
)
{
}

void bsp_smp_interrupt_cpu(
  int cpu
)
{
}

void bsp_smp_delay( int max )
{
}
