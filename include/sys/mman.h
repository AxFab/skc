/* Definitions for BSD-style memory management.
   Copyright (C) 1994-2000, 2003, 2004, 2005 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H 1

#include <sys/types.h>
#include <krn/mman.h>

/* Return value of `mmap' in case of an error.  */
#define MAP_FAILED  ((void *) -1)

/* Map addresses starting near ADDR and extending for LEN bytes.  from
  OFFSET into the file FD describes according to PROT and FLAGS.  If ADDR
  is nonzero, it is the desired mapping address.  If the MAP_FIXED bit is
  set in FLAGS, the mapping will be at ADDR exactly (which must be
  page-aligned); otherwise the system chooses a convenient nearby address.
  The return value is the actual mapping address chosen or MAP_FAILED
  for errors (in which case `errno' is set).  A successful `mmap' call
  deallocates any previous mapping for the affected region.  */
void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
    __THROW;

/* Deallocate any mapping for the region starting at ADDR and extending LEN
  bytes.  Returns 0 if successful, -1 for errors (and sets errno).  */
int munmap(void *addr, size_t len) __THROW;

/* Change the memory protection of the region starting at ADDR and
  extending LEN bytes to PROT.  Returns 0 if successful, -1 for errors
  (and sets errno).  */
int mprotect(void *addr, size_t len, int prot) __THROW;

/* Synchronize the region starting at ADDR and extending LEN bytes with the
  file it maps.  Filesystem operations on a file being mapped are
  unpredictable before this is done.  Flags are from the MS_* set.

  This function is a cancellation point and therefore not marked with
  __THROW.  */
int msync(void *addr, size_t len, int flags);


#ifdef __BSD
/* Advise the system about particular usage patterns the program follows
  for the region starting at ADDR and extending LEN bytes.  */
int madvise(void *addr, size_t len, int advice) __THROW;
#endif

#ifdef __XOPEN_00
/* This is the POSIX name for this function.  */
int posix_madvise(void *addr, size_t len, int advice) __THROW;
#endif

/* Guarantee all whole pages mapped by the range [ADDR,ADDR+LEN) to
  be memory resident.  */
int mlock(const void *addr, size_t len) __THROW;

/* Unlock whole pages previously mapped by the range [ADDR,ADDR+LEN).  */
int munlock(const void *addr, size_t len) __THROW;

/* Cause all currently mapped pages of the process to be memory resident
  until unlocked by a call to the `munlockall', until the process exits,
  or until the process calls `execve'.  */
int mlockall(int flags) __THROW;

/* All currently mapped pages of the process' address space become
  unlocked.  */
int munlockall(void) __THROW;

#if defined(__BSD) || defined(__SVID)
/* mincore returns the memory residency status of the pages in the
  current process's address space specified by [start, start + len).
  The status is returned in a vector of bytes.  The least significant
  bit of each byte is 1 if the referenced page is in memory, otherwise
  it is zero.  */
int mincore(void *start, size_t len, unsigned char *vec) __THROW;
#endif

#ifdef __GNU
/* Remap pages mapped by the range [ADDR,ADDR+OLD_LEN) to new length
  NEW_LEN.  If MREMAP_MAYMOVE is set in FLAGS the returned address
  may differ from ADDR.  If MREMAP_FIXED is set in FLAGS the function
  takes another paramter which is a fixed address at which the block
  resides after a successful call.  */
void *mremap(void *addr, size_t old_len, size_t new_len, int flags, ...)
    __THROW;

/* Remap arbitrary pages of a shared backing store within an existing VMA. */
int remap_file_pages(void *start, size_t size, int prot, size_t pgoff,
    int flags) __THROW;
#endif


/* Open shared memory segment.  */
int shm_open(const char *name, int oflag, mode_t mode);

/* Remove shared memory segment.  */
int shm_unlink(const char *name);

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#if defined(USE_LARGEFILE64) || defined(USE_FILE_OFFSET64)
void *mmap64(void *addr, size_t len, int prot, int flags, int fd,
    off64_t offset) __THROW;
#endif
#if defined(USE_FILE_OFFSET64)
#  define mmap mmap64
#endif



#endif  /* _SYS_MMAN_H */
