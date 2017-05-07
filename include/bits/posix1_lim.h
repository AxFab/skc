/*
 *      This file is part of the SmokeOS project.
 *  Copyright (C) 2015  <Fabien Bavent>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   - - - - - - - - - - - - - - -
 */
#ifndef _BITS_POSIX1_LIM_H
#define _BITS_POSIX1_LIM_H 1

/* Minimum number of operations in one list I/O call. */
#define _POSIX_AIO_LISTIO_MAX 2

/* Minimal number of outstanding asynchronous I/O operations. */
#define _POSIX_AIO_MAX 1

/* Maximum length of arguments to `execve', including environment. */
#define _POSIX_ARG_MAX 4096

/* Maximum simultaneous processes per real user ID. */
#define _POSIX_CHILD_MAX 6

/* Minimal number of timer expiration overruns. */
#define _POSIX_DELAYTIMER_MAX 32

/* Maximum length of a host name as returned from the GETHOSTNAME function. */
#define _POSIX_HOST_NAME_MAX 255

/* Maximum link count of a file. */
#define _POSIX_LINK_MAX 8

/* Maximum length of login name. */
#define _POSIX_LOGIN_NAME_MAX 9

/* Number of bytes in a terminal canonical input queue. */
#define _POSIX_MAX_CANON 255

/* Number of bytes for available space in a terminal input queue. */
#define _POSIX_MAX_INPUT 255

/* Maximum number of message queues open for a process. */
#define _POSIX_MQ_OPEN_MAX 8

/* Maximum number of supported message priorities. */
#define _POSIX_MQ_PRIO_MAX 32

/* Number of bytes in a filename. */
#define _POSIX_NAME_MAX 14

/* Number of simultaneous supplementary group IDs per process. */
#define _POSIX_NGROUPS_MAX 0

/* Number of files one process can have open at once. */
#define _POSIX_OPEN_MAX 16

/* Number of bytes in a pathname. */
#define _POSIX_PATH_MAX 256

/* Number of bytes than can be written atomically to a pipe. */
#define _POSIX_PIPE_BUF 512

/* The number of repeated occurrences of a BRE permitted by the
 REGEXEC and REGCOMP functions when using the interval notation. */
#define _POSIX_RE_DUP_MAX 255

/* Minimal number of realtime signals reserved for the application. */
#define _POSIX_RTSIG_MAX 8

/* Number of semaphores a process can have. */
#define _POSIX_SEM_NSEMS_MAX 256

/* Maximal value of a semaphore. */
#define _POSIX_SEM_VALUE_MAX 32767

/* Number of pending realtime signals. */
#define _POSIX_SIGQUEUE_MAX 32

/* Largest value of a `ssize_t'. */
#define _POSIX_SSIZE_MAX 32767

/* Number of streams a process can have open at once. */
#define _POSIX_STREAM_MAX 8

/* The number of bytes in a symbolic link. */
#define _POSIX_SYMLINK_MAX 255

/* The number of symbolic links that can be traversed in the
 resolution of a pathname in the absence of a loop. */
#define _POSIX_SYMLOOP_MAX 8

/* Number of timer for a process. */
#define _POSIX_TIMER_MAX 32

/* Maximum number of characters in a tty name. */
#define _POSIX_TTY_NAME_MAX 9

/* Maximum length of a timezone name (element of `tzname'). */
#define _POSIX_TZNAME_MAX 6

/* Maximum clock resolution in nanoseconds. */
#define _POSIX_CLOCKRES_MIN 20000000


/* Overwrite by specification of XOPEN2k */
#ifdef __XOPEN_00

#  undef _POSIX_CHILD_MAX
#  define _POSIX_CHILD_MAX 25

#  undef _POSIX_NGROUPS_MAX
#  define _POSIX_NGROUPS_MAX 8

#  undef _POSIX_OPEN_MAX
#  define _POSIX_OPEN_MAX 20

#endif


/* !? */
#if !defined __XOPEN_00 || defined __GNU
/* Number of descriptors that a process may examine with `pselect' or
 `select'. */
# define _POSIX_FD_SETSIZE _POSIX_OPEN_MAX

/* Maximum number of connections that can be queued on a socket. */
# define _POSIX_QLIMIT 1

/* Maximum number of bytes that can be buffered on a socket for send
 or receive. */
# define _POSIX_HIWAT _POSIX_PIPE_BUF

/* Maximum number of elements in an `iovec' array. */
# define _POSIX_UIO_MAXIOV 16

#endif



/* The number of data keys per process.  */
#define _POSIX_THREAD_KEYS_MAX   128

/* Controlling the iterations of destructors for thread-specific data.  */
#define _POSIX_THREAD_DESTRUCTOR_ITERATIONS  4

/* The number of threads per process.  */
#define _POSIX_THREAD_THREADS_MAX   64

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#endif  /* _BITS_POSIX1_LIM_H */
