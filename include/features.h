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
#ifndef _FEATURES_H
#define _FEATURES_H 1

#include <bits/cdefs.h>

/* Decompose all possible data model */
#if defined(__SILP32) || defined(__SILP64)
#  define __SILPx
#elif defined(__SIP16) || defined(__SIP32) /* (SIP64: long -> 128b) */
#  define __SIPx
#elif defined(__SP16) || defined(__SP32) /* (SIP64: long -> 128b) */
#  define __SPx
#elif defined(__IP32) /* (IP64: long -> 128b) */
#  define __IPx
#elif defined(__ILP32) || defined(__ILP64)
#  define __ILPx
#elif defined(__LP32) || defined(__LP64)
#  define __LPx
#elif defined(__LLP64)
#  define __LLPx
#endif

#undef WORDSIZE
#if defined(__SIP16)
#  define WORDSIZE 16
#elif defined(__SILP32) || defined(__SIP32) || defined(__IP32) || \
      defined(__ILP32) || defined(__LP32)
#  define WORDSIZE 32
#elif defined(__SILP64) || defined(__ILP64) || defined(__LP64) || defined(__LLP64)
#  define WORDSIZE 64
#endif

#if defined(__SPx)
#  define __INT_WORD short
#elif defined(__SILPx) || defined(__SIPx) || defined(__IPx)
#  define __INT_WORD int
#elif defined(__ILPx) || defined(__LPx)
#  define __INT_WORD long
#elif defined(__LLPx)
#  define __INT_WORD long long
#else
#  error Unsupported data models for this architecture.
#endif

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Versions:

  Only ISO C89 standard is defined unconditionnaly. The ISO C standard can be
  extended by inclusion of C95, C99 or C11 specification.

  Some features can also be activated by POSIX or X/OpenUNIX standards.
  Those  standard are remapped for sake of maintabilty into numbers to provide
  an increment of features set:
    POSIX:
      IEEE Std 1003.1             POSIX_1
      IEEE Std 1003.2             POSIX_2
      IEEE Std 1003.1b-1993       POSIX_3
      IEEE Std 1003.1c-1995       POSIX_4
      IEEE Std 1003.1-2004        POSIX_5
      IEEE Std 1003.1-2008        POSIX_6
    UNIX*:
      XOPEN_SOURCE <500           XOPEN_95
      XOPEN_SOURCE 500+           XOPEN_98
      XOPEN_SOURCE 600+           XOPEN_00
      XOPEN_SOURCE 700+           XOPEN_08

    On Glibc, incremental development with a lack of restructure made unix
    standard implemented using incremental XOPEN variable and possible
    extention using _XOPEN_SOURCE_EXTENDED. However, those extensions are
    always active if the source version is equal or above to 500. which means
    it can be included as a primary version without any problem.

  Other extentions have been introducted to C library:
      BSD, will include 4.3BSD features
      SVID, will include System V features
      GNU, will include BSD, System V Unix and GNU extensions.
*/

/*
  Some other feature might be isolated like __AT_FILE, __REENT, __SECURED
*/

/* In case the user defined __SKC_PARAM, we shall consider that features flags
  are alredy set. */
#ifndef __SKC_PARAM

#  undef  __C99
#  undef  __C95
#  undef  __C11

#  undef __POSIX
#  undef __POSIX2
#  undef __POSIX3
#  undef __POSIX4
#  undef __POSIX5
#  undef __POSIX6

#  undef __XOPEN_95
#  undef __XOPEN_98
#  undef __XOPEN_00
#  undef __XOPEN_08

#  undef __BSD
#  undef __SVID
#  undef __GNU

#  undef __AT_FILE
#  undef __REENT
#  undef __SECURED
#  undef __SECURED_2

/* These are defined by the user (or the compiler)
   to specify the desired environment:

   __STRICT_ANSI__  ISO Standard C.
   _ISOC99_SOURCE Extensions to ISO C89 from ISO C99.
   _POSIX_SOURCE  IEEE Std 1003.1.
   _POSIX_C_SOURCE  If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
      if >=199309L, add IEEE Std 1003.1b-1993;
      if >=199506L, add IEEE Std 1003.1c-1995;
      if >=200112L, all of IEEE 1003.1-2004
      if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE  Includes POSIX and XPG things.  Set to 500 if
      Single Unix conformance is wanted, to 600 for the
      sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE  Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE  Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N  Select default filesystem interface.
   _BSD_SOURCE    ISO C, POSIX, and 4.3BSD things.
   _SVID_SOURCE   ISO C, POSIX, and SVID things.
   _ATFILE_SOURCE Additional *at interfaces.
   _GNU_SOURCE    All of the above, plus GNU extensions.
   _REENTRANT   Select additionally reentrant object.
   _THREAD_SAFE   Same as _REENTRANT, often used by other systems.
   _FORTIFY_SOURCE  If set to numeric value > 0 additional security
      measures are defined, according to level.

   The `-ansi' switch to the GNU C compiler defines __STRICT_ANSI__.
   If none of these are defined, the default is to have _SVID_SOURCE,
   _BSD_SOURCE, and _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200112L.  If more than one of these are defined, they accumulate.
   For example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE
   together give you ISO C, 1003.1, and 1003.2, but nothing else.  */


/* POSIX */
#  if defined(_POSIX_SOURCE) && !defined(_POSIX_C_SOURCE)
#    define _POSIX_C_SOURCE 1
#  endif
#  if defined(_POSIX_C_SOURCE)
#    if _POSIX_C_SOURCE >= 200809L
#      define __POSIX6
#    elif _POSIX_C_SOURCE >= 200112L
#      define __POSIX5
#    elif _POSIX_C_SOURCE >= 199506L
#      define __POSIX4
#    elif _POSIX_C_SOURCE >= 199309L
#      define __POSIX3
#    elif _POSIX_C_SOURCE >= 2
#      define __POSIX2
#    else
#      define __POSIX
#    endif
#  endif  /* _POSIX_C_SOURCE */


/* X/Open UNIX */
#  if defined(_XOPEN_SOURCE_EXTENDED) && !defined(_XOPEN_SOURCE)
#    define _XOPEN_SOURCE 1
#  endif
#  if defined(_XOPEN_SOURCE)
#    if _XOPEN_SOURCE >= 700
#      define __XOPEN_08
#    elif _XOPEN_SOURCE >= 600
#      define __XOPEN_00
#    elif _XOPEN_SOURCE >= 500
#      define __XOPEN_98
#    else
#      define __XOPEN_95
#    endif
#  endif  /* _POSIX_C_SOURCE */


/* ANSI Standard C */
#  if defined (__STDC_VERSION__)
#    if __STDC_VERSION__ >= 201112L
#      define __C11
#    elif __STDC_VERSION__ >= 199901L
#      define __C99
#    elif __STDC_VERSION__ >= 199409L
#      define __C95
#    endif
#  endif  /* __STDC_VERSION__ */

#  ifdef _ISOC99_SOURCE
#    define __C99
#  endif
#  ifdef _BSD_SOURCE
#    define __BSD
#  endif
#  ifdef _SVID_SOURCE
#    define __SVID
#  endif
#  ifdef _GNU_SOURCE
#    define __GNU
#  endif


/* Extra features */
#  if defined (_ATFILE_SOURCE)
#    define __AT_FILE
#  endif

#  if defined(_REENTRANT) || defined(_THREAD_SAFE)
#    define __REENT
#  endif

#  if defined _FORTIFY_SOURCE && _FORTIFY_SOURCE > 0
#    if _FORTIFY_SOURCE > 1
#      define __SECURED_2
#    endif
#    define __SECURED
#  endif


#endif  /* __SKC_PARAM */

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Handle dependencies between each version. */
#if defined(__GNU)
#  define __BSD
#  define __SVID
#  define __C11
#  define __POSIX6
#  define __XOPEN_08
#  define __AT_FILE
#elif defined(__BSD) || defined(__SVID)
#  define __C99
#  define __POSIX2
#endif

#ifdef __C11
#  define __C99
#endif
#ifdef __C99
#  define __C95
#endif

#ifdef __POSIX6
#  define __POSIX5
#  define __XOPEN_08
#  define __AT_FILE
#endif
#ifdef __POSIX5
#  define __POSIX4
#  define __XOPEN_00
#endif
#ifdef __POSIX4
#  define __POSIX3
#endif
#ifdef __POSIX3
#  define __POSIX2
#endif
#ifdef __POSIX2
#  define __POSIX
#endif

#ifdef __XOPEN_08
#  define __XOPEN_00
#endif
#ifdef __XOPEN_00
#  define __XOPEN_98
#endif
#ifdef __XOPEN_98
#  define __XOPEN_95
#endif


#ifdef __SECURED
#  define __SECURED_2
#endif



/* This library must be available for most sytem, even those without syscalls.
  For this we need to define an extra parameter to include function that are
  syscalls dependants. */
#ifndef _NO_SYS
#  define __SYS_CALL
#endif

#if defined (__C99) || WORDSIZE == 64 || defined(__LLPx)
/* A compiler pre-requisite to C99 is to support `long long' */
#  undef __have_LLONG
#  define __have_LLONG
#endif

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Convenience macros to test the versions of the library.
  Use it like this:
  #if __SKC_PREREQ(2,8)
    ... code requiring library 2.8 or later ...
  #endif
  */
#define __SKC_MAJ 1
#define __SKC_MIN 0
#define __SKC_PREREQ(maj, min)  \
  (((__SKC_MAJ << 16) + __SKC_MIN) >=  ((maj) << 16) + (min))






#if 0

/* TODO

# if defined _GNU_SOURCE
# undef  _LARGEFILE64_SOURCE
# define _LARGEFILE64_SOURCE  1
#endif

#ifdef _LARGEFILE_SOURCE
# define __USE_LARGEFILE  1
#endif
#ifdef _LARGEFILE64_SOURCE
# define __USE_LARGEFILE64  1
#endif
#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64
# define __USE_FILE_OFFSET64  1
#endif

/ * Suppress kernel-name space pollution unless user expressedly asks
   for it.  * /
#ifndef _LOOSE_KERNEL_NAMES
# define __KERNEL_STRICT_NAMES
#endif

  */



/* Define __STDC_IEC_559__ and other similar macros.  */
#include <bits/predefs.h>

/* wchar_t uses ISO 10646-1 (2nd ed., published 2000-09-15) / Unicode 3.1.  */
#define __STDC_ISO_10646__		200009L



/* This is here only because every header file already includes this one.  */
#ifndef __ASSEMBLER__
# ifndef _SYS_CDEFS_H
#  include <sys/cdefs.h>
# endif

/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */
# if defined __USE_FILE_OFFSET64 && !defined __REDIRECT
#  define __USE_LARGEFILE	1
#  define __USE_LARGEFILE64	1
# endif

#endif	/* !ASSEMBLER */

/* Decide whether we can define 'extern inline' functions in headers.  */
#if __GNUC_PREREQ (2, 7) && defined __OPTIMIZE__ \
    && !defined __OPTIMIZE_SIZE__ && !defined __NO_INLINE__ \
    && defined __extern_inline
# define __USE_EXTERN_INLINES	1
#endif

/* There are some functions that must be declared 'extern inline' even with
   -Os when building LIBC, or they'll end up undefined.  */
#if __GNUC_PREREQ (2, 7) && defined __OPTIMIZE__ \
    && (defined _LIBC || !defined __OPTIMIZE_SIZE__) && !defined __NO_INLINE__ \
    && defined __extern_inline
# define __USE_EXTERN_INLINES_IN_LIBC	1
#endif

#endif



#endif  /* _FEATURES_H */
