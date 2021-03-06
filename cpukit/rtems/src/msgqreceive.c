/**
 *  @file
 *
 *  @brief RTEMS Message Queue Receive
 *  @ingroup ClassicMessageQueue
 */

/*
 *  COPYRIGHT (c) 1989-2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems/system.h>
#include <rtems/score/chain.h>
#include <rtems/score/isr.h>
#include <rtems/score/coremsgimpl.h>
#include <rtems/score/threadimpl.h>
#include <rtems/score/wkspace.h>
#include <rtems/rtems/status.h>
#include <rtems/rtems/attrimpl.h>
#include <rtems/rtems/messageimpl.h>
#include <rtems/rtems/optionsimpl.h>
#include <rtems/rtems/support.h>

THREAD_WAIT_QUEUE_OBJECT_ASSERT(
  Message_queue_Control,
  message_queue.Wait_queue
);

rtems_status_code rtems_message_queue_receive(
  rtems_id        id,
  void           *buffer,
  size_t         *size,
  rtems_option    option_set,
  rtems_interval  timeout
)
{
  Message_queue_Control          *the_message_queue;
  Objects_Locations               location;
  bool                            wait;
  Thread_Control                 *executing;
  ISR_lock_Context                lock_context;

  if ( !buffer )
    return RTEMS_INVALID_ADDRESS;

  if ( !size )
    return RTEMS_INVALID_ADDRESS;

  the_message_queue = _Message_queue_Get_interrupt_disable(
    id,
    &location,
    &lock_context
  );
  switch ( location ) {

    case OBJECTS_LOCAL:
      if ( _Options_Is_no_wait( option_set ) )
        wait = false;
      else
        wait = true;

      executing = _Thread_Executing;
      _CORE_message_queue_Seize(
        &the_message_queue->message_queue,
        executing,
        the_message_queue->Object.id,
        buffer,
        size,
        wait,
        timeout,
        &lock_context
      );
      return _Message_queue_Translate_core_message_queue_return_code(
        executing->Wait.return_code
      );

#if defined(RTEMS_MULTIPROCESSING)
    case OBJECTS_REMOTE:
      return _Message_queue_MP_Send_request_packet(
          MESSAGE_QUEUE_MP_RECEIVE_REQUEST,
          id,
          buffer,
          size,
          option_set,
          timeout
        );
#endif

    case OBJECTS_ERROR:
      break;
  }

  return RTEMS_INVALID_ID;
}
