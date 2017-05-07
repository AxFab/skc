#ifndef _STDINT_H
#define _STDINT_H 1

#include <features.h>
// TODO #include <limits.h>
// #include <bits/wchar.h>

#ifndef __C99
#  error Header file <stdint.h> should not be included as part of C89.
#endif


#define SIZE_MAX ULONG_MAX
#define SSIZE_MAX LONG_MAX


typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int int16_t;
typedef unsigned short int uint16_t;

#if defined(__ILP64) || defined(__SILP64)
typedef signed short int32_t;
typedef unsigned short uint32_t;
#elif defined(__ILP32) || defined(__LP64)
typedef signed int int32_t;
typedef unsigned int uint32_t;
#elif defined(__LP32) || defined(__LLP64)
typedef signed long int32_t;
typedef unsigned long uint32_t;
#endif

#if defined(__SILP64)
typedef signed short int64_t;
typedef unsigned short uint64_t;
#elif defined(__ILP64) || defined(__LP64)
typedef signed long int64_t;
typedef unsigned long uint64_t;
#elif defined(__ILP32) || defined(__LP32) || defined(__LLP64)
typedef signed long long int64_t;
typedef unsigned long long uint64_t;
#endif

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;

typedef short int int_least16_t;
typedef unsigned short int uint_least16_t;
typedef int int_fast16_t;
typedef unsigned int uint_fast16_t;


typedef int32_t int_least32_t;
typedef uint32_t uint_least32_t;
#if defined(__LP32) || defined(__LLP64)
typedef long int_fast32_t;
typedef unsigned long uint_fast32_t;
#else
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
#endif


typedef int64_t int_least64_t;
typedef uint64_t uint_least64_t;
#if defined(__SILP64) || defined(__ILP64) || defined(__LP64)
typedef long int int_fast64_t;
typedef unsigned long int uint_fast64_t;
#else
typedef long long int int_fast64_t;
typedef unsigned long long int uint_fast64_t;
#endif


typedef int intptr_t;
typedef unsigned int uintptr_t;

typedef long long int intmax_t;
typedef unsigned long long int uintmax_t;

#endif /* _STDINT_H */
