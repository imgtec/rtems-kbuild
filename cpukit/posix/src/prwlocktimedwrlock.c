/**
 * @file
 *
 * @brief Function applies a Write lock to RWLock referenced by rwlock 
 * @ingroup POSIXAPI
 */

/*
 *  POSIX RWLock Manager -- Attempt to Obtain a Write Lock on a RWLock Instance
 *
 *  COPYRIGHT (c) 1989-2008.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems/posix/rwlockimpl.h>
#include <rtems/score/todimpl.h>

int pthread_rwlock_timedwrlock(
  pthread_rwlock_t      *rwlock,
  const struct timespec *abstime
)
{
  POSIX_RWLock_Control                    *the_rwlock;
  ISR_lock_Context                         lock_context;
  Watchdog_Interval                        ticks;
  bool                                     do_wait;
  TOD_Absolute_timeout_conversion_results  status;
  Thread_Control                          *executing;

  /*
   *  POSIX requires that blocking calls with timeouts that take
   *  an absolute timeout must ignore issues with the absolute
   *  time provided if the operation would otherwise succeed.
   *  So we check the abstime provided, and hold on to whether it
   *  is valid or not.  If it isn't correct and in the future,
   *  then we do a polling operation and convert the UNSATISFIED
   *  status into the appropriate error.
   *
   *  If the status is TOD_ABSOLUTE_TIMEOUT_INVALID,
   *  TOD_ABSOLUTE_TIMEOUT_IS_IN_PAST, or TOD_ABSOLUTE_TIMEOUT_IS_NOW,
   *  then we should not wait.
   */
  status = _TOD_Absolute_timeout_to_ticks( abstime, &ticks );
  do_wait = ( status == TOD_ABSOLUTE_TIMEOUT_IS_IN_FUTURE );

  the_rwlock = _POSIX_RWLock_Get( rwlock, &lock_context );

  if ( the_rwlock == NULL ) {
    return EINVAL;
  }

  executing = _Thread_Executing;
  _CORE_RWLock_Seize_for_writing(
    &the_rwlock->RWLock,
    executing,
    do_wait,
    ticks,
    &lock_context
  );

  if (
    !do_wait
      && ( executing->Wait.return_code == CORE_RWLOCK_UNAVAILABLE )
  ) {
    if ( status == TOD_ABSOLUTE_TIMEOUT_INVALID ) {
      return EINVAL;
    }

    if (
      status == TOD_ABSOLUTE_TIMEOUT_IS_IN_PAST
        || status == TOD_ABSOLUTE_TIMEOUT_IS_NOW
    ) {
      return ETIMEDOUT;
    }
  }

  return _POSIX_RWLock_Translate_core_RWLock_return_code(
    (CORE_RWLock_Status) executing->Wait.return_code
  );
}
