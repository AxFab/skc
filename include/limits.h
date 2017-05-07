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
#ifndef _LIMITS_H_
#define _LIMITS_H_ 1

#include <features.h>
#include <krn/limits.h>

/* Number of bits, minimum and maximum values of primitive integer types:
  Architecture data model
                    IP16    LP32    ILP32   LLP64   LP64    ILP64   SILP64
    char              8       8       8       8       8       8       8
    short            16      16      16      16      16      16      64
    int              16      16      32      32      32      64      64
    long             32      32      32      32      64      64      64
    long long                        64      64      64      64      64
    pointer/size_t   16      32      32      64      64      64      64
 */

#define CHAR_BIT 8
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127
#define UCHAR_MAX 255
#ifdef __UCHAR
#  define CHAR_MIN 0
#  define CHAR_MAX UCHAR_MAX
#else
#  define CHAR_MIN SCHAR_MIN
#  define CHAR_MAX SCHAR_MAX
#endif

#if defined(__SILP64)
#  define SHRT_BIT 64
#  define SHRT_MIN  (-9223372036854775808)
#  define SHRT_MAX  9223372036854775807
#  define USHRT_MAX 18446744073709551615U
#elif defined(__SIP32) || defined(__SILP32)
#  define SHRT_BIT 32
#  define SHRT_MIN  (-2147483648)
#  define SHRT_MAX  2147483647
#  define USHRT_MAX 4294967295U
#else
#  define SHRT_BIT 16
#  define SHRT_MIN  (-32768)
#  define SHRT_MAX  32767
#  define USHRT_MAX 65535
#endif

#if defined(__SILP64) || defined(__ILP64)
#  define INT_BIT 64
#  define INT_MIN  (-9223372036854775808)
#  define SINT_MAX  9223372036854775807
#  define UINT_MAX 18446744073709551615U
#elif defined(__IP16) || defined(__LP32)
#  define INT_BIT 16
#  define INT_MIN  (-32768)
#  define INT_MAX  32767
#  define UINT_MAX 65535
#else
#  define INT_BIT 32
#  define INT_MIN  (-2147483648)
#  define INT_MAX  2147483647
#  define UINT_MAX 4294967295U
#endif

#if defined(__SILP64) || defined(__ILP64) || defined(__LP64)
#  define LONG_BIT 64
#  define LONG_MIN  (-9223372036854775808L)
#  define LONG_MAX  9223372036854775807L
#  define ULONG_MAX 18446744073709551615UL
#else
#  define LONG_BIT 32
#  define LONG_MIN  (-2147483648L)
#  define LONG_MAX  2147483647L
#  define ULONG_MAX 4294967295UL
#endif

#ifdef __have_LLONG
#  define LLONG_BIT 64
#  define LLONG_MAX  9223372036854775807LL
#  define LLONG_MIN  (-LLONG_MAX -1LL)
#  define ULLONG_MAX 18446744073709551615ULL
#endif

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */


#if defined(__SILPx) || defined(__SIPx) || defined(__IPx)
#  define SSIZE_MAX INT_MAX
#elif defined(__ILPx) || defined(__LPx)
#  define SSIZE_MAX LONG_MAX
#elif defined(__LLPx)
#  define SSIZE_MAX LLONG_MAX
#else
#  error Unsupported data models for this architecture.
#endif


/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef	__POSIX
#  include <bits/posix1_lim.h>
#endif
#ifdef	__POSIX2
#  include <bits/posix2_lim.h>
#endif
#ifdef	__XOPEN_95
#  include <bits/xopen_lim.h>
#endif

#endif  /* _LIMITS_H_ */
