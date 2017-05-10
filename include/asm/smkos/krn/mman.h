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
#if !defined _SYS_MMAN_H
# error "Never use <krn/mman.h> directly; include <sys/mman.h> instead."
#endif


/* Share changes. */
#define MAP_SHARED  (1 << 0)
/* Changes are private. */
#define MAP_PRIVATE  (1 << 1)
/* Use a file. */
#define MAP_FILE  (1 << 2)
/* Don't use a file. */
#define MAP_ANONYMOUS  (1 << 3)

/* Map mask. */
#define MAP_TYPE  (MAP_SHARED | MAP_PRIVATE | MAP_FILE | MAP_ANONYMOUS)
#define MAP_ANON MAP_ANONYMOUS

/* Interpret addr exactly. */
#define MAP_FIXED  (1 << 4)


/* These are Linux-specific.  */
#if defined(__USE_BSD) || defined(__SVID)
/* Populate (prefault) pagetables.  */
#  define MAP_POPULATE  (1 << 5)

/* ETXTBSY */
#  define MAP_DENYWRITE  (1 << 8)
/* Mark it as an executable.  */
#  define MAP_EXECUTABLE  (1 << 9)
/* Lock the mapping.  */
#  define MAP_LOCKED  (1 << 10)
/* Don't check for reservations.  */
#  define MAP_NORESERVE  (1 << 11)
/* Do not block on IO.  */
#  define MAP_NONBLOCK  (1 << 12)
/* Allocation is for a stack.  */
#  define MAP_STACK  (1 << 13)
/* Create huge page mapping.  */
#  define MAP_HUGETLB  (1 << 14)
/* Stack-like segment.  */
#  define MAP_GROWSDOWN  (1 << 8)

#endif


/* Page can not be accessed. */
#define PROT_NONE 0x0
/* Page can be read. */
#define PROT_READ (1 << 0)
/* Page can be written. */
#define PROT_WRITE (1 << 1)
/* Page can be executed. */
#define PROT_EXEC (1 << 2)

/* Extend change to start of growsdown vma (mprotect only).  */
#define PROT_GROWSDOWN  (1 << 4)
/* Extend change to start of growsup vma (mprotect only).  */
#define PROT_GROWSUP  (1 << 5)



#define MAP_PROT_NONE  (PROT_NONE << 16)
#define MAP_PROT_READ  (PROT_READ << 16)
#define MAP_PROT_WRITE  (PROT_WRITE << 16)
#define MAP_PROT_EXEC  (PROT_EXEC << 16)

#define MAP_PROT_GROWSDOWN  (PROT_GROWSDOWN << 16)
#define MAP_PROT_GROWSUP  (PROT_GROWSUP << 16)

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Flags to `msync'.  */
/* Sync memory asynchronously.  */
#define MS_ASYNC  1
/* Synchronous memory sync.  */
#define MS_SYNC   4
/* Invalidate the caches.  */
#define MS_INVALIDATE 2


/* Flags for `mlockall'.  */
/* Lock all currently mapped pages.  */
#define MCL_CURRENT 1
/* Lock all additions to address space.  */
#define MCL_FUTURE  2


#ifdef __GNU
/* Flags for `mremap'.  */
# define MREMAP_MAYMOVE 1
# define MREMAP_FIXED 2
#endif


#ifdef __BSD
/* Advice to `madvise'.  */
/* No further special treatment.  */
# define MADV_NORMAL    0
/* Expect random page references.  */
# define MADV_RANDOM    1
/* Expect sequential page references.  */
# define MADV_SEQUENTIAL  2
/* Will need these pages.  */
# define MADV_WILLNEED    3
/* Don't need these pages.  */
# define MADV_DONTNEED    4
/* Remove these pages and resources.  */
# define MADV_REMOVE    9
/* Do not inherit across fork.  */
# define MADV_DONTFORK    10
/* Do inherit across fork.  */
# define MADV_DOFORK    11
/* KSM may merge identical pages.  */
# define MADV_MERGEABLE   12
/* KSM may not merge identical pages.  */
# define MADV_UNMERGEABLE 13
/* Worth backing with hugepages.  */
# define MADV_HUGEPAGE    14
/* Not worth backing with hugepages.  */
# define MADV_NOHUGEPAGE  15
/* Poison a page for testing.  */
# define MADV_HWPOISON    100
#endif


#ifdef __XOPEN_00
/* The POSIX people had to invent similar names for the same things.  */
/* No further special treatment.  */
# define POSIX_MADV_NORMAL  0
/* Expect random page references.  */
# define POSIX_MADV_RANDOM  1
/* Expect sequential page references.  */
# define POSIX_MADV_SEQUENTIAL  2
/* Will need these pages.  */
# define POSIX_MADV_WILLNEED  3
/* Don't need these pages.  */
# define POSIX_MADV_DONTNEED  4
#endif
