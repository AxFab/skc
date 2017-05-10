
/* This is the value this implementation supports.  */
#define PTHREAD_KEYS_MAX   THREAD_KEYS_MAX

/* Number of iterations this implementation does.  */
#define PTHREAD_DESTRUCTOR_ITERATIONS  _POSIX_THREAD_DESTRUCTOR_ITERATIONS

/* We have no predefined limit on the number of threads.  */
#undef PTHREAD_THREADS_MAX

/* Minimum size for a thread.  We are free to choose a reasonable value.  */
#define PTHREAD_STACK_MIN  4096


/* Maximum amount by which a process can descrease its asynchronous I/O
   priority level.  */
#define AIO_PRIO_DELTA_MAX 20


/* Maximum number of timer expiration overruns.  */
#define DELAYTIMER_MAX  2147483647

/* Maximum tty name length.  */
#define TTY_NAME_MAX 12

/* Maximum login name length.  This is arbitrary.  */
#define LOGIN_NAME_MAX 256

/* Maximum host name length.  */
#define HOST_NAME_MAX      64

/* Maximum message queue priority level.  */
#define MQ_PRIO_MAX     32768

/* Maximum value the semaphore can have.  */
#define SEM_VALUE_MAX   (2147483647)



#define NGROUPS_MAX 8



/* PATHNAME VARIABLE VALUES */
#define FILESIZEBITS 32
/* Maximum number of links to a single file. */
#define LINK_MAX 65536
/* Maximum number of bytes in a terminal canonical input line. */
#define MAX_CANON 4096
/* Minimum number of bytes for which space is available in a terminal input queue */
#define MAX_INPUT 4096
/* Maximum number of bytes in a filename (without the terminating null
  character) */
#define NAME_MAX 255
/* Maximum number of bytes the implementation will store as a pathname in a
  user-supplied buffer, including the terminating null character. */
#define PATH_MAX 1024
/* Maximum number of bytes that is guaranteed to be atomic when writing to a pipe. */
#define PIPE_BUF 512

