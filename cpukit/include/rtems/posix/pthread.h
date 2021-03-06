/**
 * @file
 *
 * @brief POSIX Threads Private Support
 *
 * This include file contains all the private support information for
 * POSIX threads.
 */

/*
 *  COPYRIGHT (c) 1989-2011.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#ifndef _RTEMS_POSIX_PTHREAD_H
#define _RTEMS_POSIX_PTHREAD_H

#include <rtems/posix/threadsup.h>
#include <rtems/score/thread.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup POSIX_PTHREAD POSIX Threads Support
 *
 * @ingroup POSIXAPI
 *
 * @brief Private Support Information for POSIX Threads
 *
 */
/**@{**/

extern const size_t _Configuration_POSIX_Minimum_stack_size;

/**
 * @brief POSIX threads initialize user threads body.
 *
 * This routine creates and starts all configured user
 * initialization threads.
 */
extern void _POSIX_Threads_Initialize_user_threads_body(void);

/**
 * The following defines the information control block used to manage
 * this class of objects.
 */
extern Thread_Information _POSIX_Threads_Information;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
/*  end of include file */
