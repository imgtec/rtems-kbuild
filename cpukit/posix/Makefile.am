include $(top_srcdir)/automake/multilib.am
include $(top_srcdir)/automake/compile.am

EXTRA_DIST =

noinst_LIBRARIES = libposix.a
libposix_a_CPPFLAGS = $(AM_CPPFLAGS)
libposix_a_SOURCES =

# Some POSIX functions that are nice to always have
libposix_a_SOURCES += src/nanosleep.c src/clockgettime.c src/clocksettime.c \
    src/clockgetres.c src/sysconf.c

include_rtems_posixdir = $(includedir)/rtems/posix

include_rtems_posix_HEADERS = include/rtems/posix/sigset.h

## Some POSIX threads features are needed all the time
include_rtems_posix_HEADERS += include/rtems/posix/key.h
include_rtems_posix_HEADERS += include/rtems/posix/keyimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/config.h
include_rtems_posix_HEADERS += include/rtems/posix/posixapi.h

if HAS_PTHREADS
# include
include_HEADERS = include/aio.h
include_HEADERS += include/mqueue.h
if !HAVE_SEMAPHORE_H
include_HEADERS += include/semaphore.h
endif

# include/rtems/posix
include_rtems_posix_HEADERS += include/rtems/posix/aio_misc.h
include_rtems_posix_HEADERS += include/rtems/posix/cancel.h
include_rtems_posix_HEADERS += include/rtems/posix/cond.h
include_rtems_posix_HEADERS += include/rtems/posix/condimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/mqueue.h
include_rtems_posix_HEADERS += include/rtems/posix/mqueueimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/mutex.h
include_rtems_posix_HEADERS += include/rtems/posix/muteximpl.h
include_rtems_posix_HEADERS += include/rtems/posix/priorityimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/psignal.h
include_rtems_posix_HEADERS += include/rtems/posix/psignalimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/pthread.h
include_rtems_posix_HEADERS += include/rtems/posix/pthreadimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/ptimer.h
include_rtems_posix_HEADERS += include/rtems/posix/semaphore.h
include_rtems_posix_HEADERS += include/rtems/posix/semaphoreimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/threadsup.h
include_rtems_posix_HEADERS += include/rtems/posix/timer.h
include_rtems_posix_HEADERS += include/rtems/posix/timerimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/barrier.h
include_rtems_posix_HEADERS += include/rtems/posix/barrierimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/rwlock.h
include_rtems_posix_HEADERS += include/rtems/posix/rwlockimpl.h
include_rtems_posix_HEADERS += include/rtems/posix/spinlock.h
include_rtems_posix_HEADERS += include/rtems/posix/spinlockimpl.h

## src
libposix_a_SOURCES += src/aio_cancel.c src/aio_error.c src/aio_fsync.c \
    src/aio_read.c src/aio_return.c src/aio_suspend.c src/aio_write.c \
    src/lio_listio.c src/aio_misc.c

libposix_a_SOURCES += src/_execve.c
endif

libposix_a_SOURCES += src/fork.c src/vfork.c

libposix_a_SOURCES += src/wait.c src/waitpid.c

if HAS_PTHREADS
libposix_a_SOURCES +=  src/pthreadatfork.c

## BARRIER_C_FILES
libposix_a_SOURCES += src/barrierattrdestroy.c src/barrierattrgetpshared.c \
    src/barrierattrinit.c src/barrierattrsetpshared.c src/pbarrier.c \
    src/pbarrierdestroy.c src/pbarrierinit.c \
    src/pbarriertranslatereturncode.c src/pbarrierwait.c

## CANCEL_C_FILES
libposix_a_SOURCES += src/cancel.c src/canceleval.c \
    src/cleanuppush.c src/setcancelstate.c \
    src/setcanceltype.c src/testcancel.c

## CONDITION_VARIABLE_C_FILES
libposix_a_SOURCES += src/cond.c src/condattrdestroy.c \
    src/condattrgetpshared.c src/condattrinit.c src/condattrsetpshared.c \
    src/condbroadcast.c src/conddefaultattributes.c src/conddestroy.c \
    src/condinit.c src/condsignal.c src/condsignalsupp.c \
    src/condtimedwait.c src/condwait.c src/condwaitsupp.c src/condget.c

## MEMORY_C_FILES
libposix_a_SOURCES += src/mmap.c
libposix_a_SOURCES += src/mprotect.c
libposix_a_SOURCES += src/munmap.c

## MESSAGE_QUEUE_C_FILES
libposix_a_SOURCES += src/mqueue.c src/mqueueclose.c \
    src/mqueuecreatesupp.c src/mqueuedeletesupp.c src/mqueuegetattr.c \
    src/mqueuenotify.c src/mqueueopen.c \
    src/mqueuereceive.c src/mqueuerecvsupp.c src/mqueuesend.c \
    src/mqueuesendsupp.c src/mqueuesetattr.c src/mqueuetimedreceive.c \
    src/mqueuetimedsend.c src/mqueuetranslatereturncode.c \
    src/mqueueunlink.c

## MUTEX_C_FILES
libposix_a_SOURCES += src/mutexattrdestroy.c src/mutexattrgetprioceiling.c \
    src/mutexattrgetprotocol.c src/mutexattrgetpshared.c \
    src/mutexattrgettype.c src/mutexattrinit.c src/mutexattrsetprioceiling.c \
    src/mutexattrsetprotocol.c src/mutexattrsetpshared.c \
    src/mutexattrsettype.c src/mutex.c src/mutexdestroy.c src/mutexget.c \
    src/mutexgetprioceiling.c src/mutexinit.c src/mutexlock.c \
    src/mutexlocksupp.c src/mutexsetprioceiling.c src/mutextimedlock.c \
    src/mutextranslatereturncode.c src/mutextrylock.c src/mutexunlock.c

## PTHREAD_C_FILES
libposix_a_SOURCES += src/pthreadatfork.c src/pthreadattrdestroy.c \
    src/pthreadattrgetdetachstate.c src/pthreadattrgetinheritsched.c \
    src/pthreadattrgetschedparam.c src/pthreadattrgetschedpolicy.c \
    src/pthreadattrgetscope.c src/pthreadattrgetstackaddr.c \
    src/pthreadattrgetstack.c src/pthreadattrgetstacksize.c \
    src/pthreadattrinit.c src/pthreadattrsetdetachstate.c \
    src/pthreadattrsetguardsize.c src/pthreadattrsetinheritsched.c \
    src/pthreadattrsetschedparam.c src/pthreadattrsetschedpolicy.c \
    src/pthreadattrsetscope.c src/pthreadattrsetstackaddr.c \
    src/pthreadattrsetstack.c src/pthreadattrsetstacksize.c \
    src/pthreadgetattrnp.c \
    src/pthreadattrgetguardsize.c src/pthread.c \
    src/pthreadconcurrency.c \
    src/pthreadcreate.c src/pthreaddetach.c src/pthreadequal.c \
    src/pthreadexit.c src/pthreadgetcpuclockid.c \
    src/pthreadgetschedparam.c \
    src/pthreadinitthreads.c src/pthreadjoin.c src/pthreadkill.c \
    src/pthreadself.c \
    src/pthreadsetschedparam.c src/pthreadsigmask.c \
    src/psxpriorityisvalid.c src/psxtransschedparam.c

## RTEMS specific support methods
libposix_a_SOURCES += src/pthreadattrcompare.c

if HAS_SMP
## PTHREAD_AFFINITY_C_FILES
libposix_a_SOURCES += src/pthreadattrsetaffinitynp.c \
    src/pthreadattrgetaffinitynp.c  src/pthreadgetaffinitynp.c   \
    src/pthreadsetaffinitynp.c
endif

## PSIGNAL_C_FILES
libposix_a_SOURCES += src/psignal.c src/alarm.c src/kill.c src/killinfo.c \
    src/kill_r.c src/pause.c src/psignalclearprocesssignals.c \
    src/psignalsetprocesssignals.c \
    src/psignalclearsignals.c src/psignalunblockthread.c src/pthreadkill.c \
    src/pthreadsigmask.c src/sigaction.c
endif

## KEY_C_FILES
libposix_a_SOURCES += src/key.c src/keycreate.c src/keydelete.c \
    src/keygetspecific.c \
    src/keysetspecific.c

## ONCE_C_FILES
libposix_a_SOURCES += src/pthreadonce.c

libposix_a_SOURCES += src/sigaddset.c src/sigdelset.c src/sigfillset.c \
   src/sigemptyset.c src/sigismember.c

libposix_a_SOURCES += src/sigprocmask.c

if HAS_PTHREADS
libposix_a_SOURCES += src/sigpending.c \
    src/sigqueue.c src/sigsuspend.c src/sigtimedwait.c \
    src/sigwait.c src/sigwaitinfo.c src/signal_2.c src/ualarm.c

## RWLOCK_C_FILES
libposix_a_SOURCES += src/prwlock.c src/prwlockdestroy.c src/prwlockinit.c \
    src/prwlockrdlock.c src/prwlocktimedrdlock.c src/prwlocktimedwrlock.c \
    src/prwlocktryrdlock.c src/prwlocktrywrlock.c src/prwlockunlock.c \
    src/prwlockwrlock.c src/rwlockattrdestroy.c src/rwlockattrgetpshared.c \
    src/rwlockattrinit.c src/rwlockattrsetpshared.c \
    src/prwlocktranslatereturncode.c

## SEMAPHORE_C_FILES
libposix_a_SOURCES += src/semaphore.c src/semaphorecreatesupp.c \
    src/semaphoredeletesupp.c \
    src/semaphoretranslatereturncode.c src/semaphorewaitsupp.c \
    src/semclose.c src/semdestroy.c src/semgetvalue.c src/seminit.c \
    src/semopen.c src/sempost.c src/semtimedwait.c src/semtrywait.c \
    src/semunlink.c src/semwait.c

## SPINLOCK_C_FILES
libposix_a_SOURCES += src/pspin.c src/pspindestroy.c src/pspininit.c \
    src/pspinlock.c src/pspinlocktranslatereturncode.c src/pspintrylock.c \
    src/pspinunlock.c

## TIME_C_FILES
libposix_a_SOURCES += src/adjtime.c src/clockgetcpuclockid.c

## TIMER_C_FILES
libposix_a_SOURCES += src/ptimer.c src/timercreate.c src/timerdelete.c \
    src/timergetoverrun.c src/timergettime.c src/timersettime.c

## ITIMER_C_FILES
libposix_a_SOURCES += src/getitimer.c src/setitimer.c

## SUPPORT_C_FILES
libposix_a_SOURCES += src/psxpriorityisvalid.c
libposix_a_SOURCES += src/psxnametoid.c

EXTRA_DIST += src/README.mqueue

libposix_a_SOURCES += src/sched_getparam.c src/sched_getprioritymax.c \
    src/sched_getprioritymin.c src/sched_getscheduler.c \
    src/sched_rr_get_interval.c src/sched_setparam.c \
    src/sched_setscheduler.c src/sched_yield.c
endif

include $(srcdir)/preinstall.am
include $(top_srcdir)/automake/local.am
