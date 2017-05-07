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
 *
 *      Standard types.
 */
#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H 1

#include <stddef.h>

#ifndef __C99
#  error Header file <sys/types.h> should not be included as part of C89.
#endif

typedef unsigned char u_char;
typedef unsigned short int u_short;
typedef unsigned int u_int;
typedef unsigned long int u_long;

typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;


typedef signed long long int quad_t;
typedef unsigned long long int u_quad_t;
typedef struct { int __val[2]; } fsid_t;

typedef quad_t loff_t;


typedef unsigned int __id_t;

typedef int pid_t;
typedef __id_t uid_t;
typedef __id_t gid_t;
typedef __id_t mode_t;
typedef __id_t nlink_t;
typedef __id_t id_t;
typedef unsigned long int ino_t;
typedef int key_t;




typedef int off_t;
typedef u_quad_t dev_t;
typedef u_quad_t ino64_t;
typedef quad_t off64_t;

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

typedef char* caddr_t;
typedef quad_t* qaddr_t;

#ifndef __defined_size_t
#  define __defined_size_t
typedef unsigned __INT_WORD size_t;
#endif

typedef signed __INT_WORD ssize_t;
typedef __INT_WORD daddr_t;


/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

typedef signed short int __int16_t;
#if defined(__ILP64) || defined(__SILP64)
typedef signed short __int32_t;
#elif defined(__ILP32) || defined(__LP64)
typedef signed int __int32_t;
#elif defined(__LP32) || defined(__LLP64)
typedef signed long __int32_t;
#endif

#if defined(__SILP64)
typedef signed short __int64_t;
#elif defined(__ILP64) || defined(__LP64)
typedef signed long __int64_t;
#elif defined(__ILP32) || defined(__LP32) || defined(__LLP64)
#  ifdef __C99
typedef signed long long __int64_t;
#  endif
#endif


#if WORDSIZE == 16
typedef __int16_t register_t;
#elif WORDSIZE == 32
typedef __int32_t register_t;
#elif WORDSIZE == 64
typedef __int64_t register_t;
#endif

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */


#define __block long int

typedef __block __blksize_t;
typedef __block blkcnt_t;
typedef unsigned __block fsblkcnt_t;
typedef unsigned __block fsfilcnt_t;

typedef quad_t blkcnt64_t;
typedef u_quad_t fsblkcnt64_t;
typedef u_quad_t fsfilcnt64_t;

#include <time.h>
// TODO #include <endian.h>
// #include <sys/select.h>
// #include <sys/sysmacros.h>

#endif /* _SYS_TYPES_H */
