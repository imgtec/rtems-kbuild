/**
 * @file
 *
 * @brief Initializes Thread and Executes it
 *
 * @ingroup ScoreThread
 */

/*
 *  COPYRIGHT (c) 1989-1999.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems/score/threadimpl.h>
#include <rtems/score/isrlevel.h>
#include <rtems/score/userextimpl.h>

bool _Thread_Start(
  Thread_Control                 *the_thread,
  const Thread_Entry_information *entry
)
{
  if ( _States_Is_dormant( the_thread->current_state ) ) {
    the_thread->Start.Entry = *entry;
    _Thread_Load_environment( the_thread );
    _Thread_Ready( the_thread );
    _User_extensions_Thread_start( the_thread );

    return true;
  }

  return false;
}
