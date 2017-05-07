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
#ifndef _BITS_POSIX2_LIM_H
#define _BITS_POSIX2_LIM_H 1


/* The maximum `ibase' and `obase' values allowed by the `bc' utility. */
#define _POSIX2_BC_BASE_MAX 99

/* The maximum number of elements allowed in an array by the `bc' utility. */
#define _POSIX2_BC_DIM_MAX 2048

/* The maximum `scale' value allowed by the `bc' utility. */
#define _POSIX2_BC_SCALE_MAX 99

/* The maximum length of a string constant accepted by the `bc' utility. */
#define _POSIX2_BC_STRING_MAX 1000

/* The maximum number of weights that can be assigned to an entry of
 the LC_COLLATE `order' keyword in the locale definition file. */
#define _POSIX2_COLL_WEIGHTS_MAX 2

/* The maximum number of expressions that can be nested
 within parentheses by the `expr' utility. */
#define _POSIX2_EXPR_NEST_MAX 32

/* The maximum length, in bytes, of an input line. */
#define _POSIX2_LINE_MAX 2048

/* The maximum number of repeated occurrences of a regular expression
 permitted when using the interval notation `\{M,N\}'. */
#define _POSIX2_RE_DUP_MAX 255

/* The maximum number of bytes in a character class name. We have no
 fixed limit, 2048 is a high number. */
#define _POSIX2_CHARCLASS_NAME_MAX 14


/* These values are implementation-specific,
 and may vary within the implementation.
 Their precise values can be obtained from sysconf. */

#ifndef BC_BASE_MAX
#define BC_BASE_MAX _POSIX2_BC_BASE_MAX
#endif
#ifndef BC_DIM_MAX
#define BC_DIM_MAX _POSIX2_BC_DIM_MAX
#endif
#ifndef BC_SCALE_MAX
#define BC_SCALE_MAX _POSIX2_BC_SCALE_MAX
#endif
#ifndef BC_STRING_MAX
#define BC_STRING_MAX _POSIX2_BC_STRING_MAX
#endif
#ifndef COLL_WEIGHTS_MAX
#define COLL_WEIGHTS_MAX _POSIX2_COLL_WEIGHTS_MAX
#endif
#ifndef EXPR_NEST_MAX
#define EXPR_NEST_MAX _POSIX2_EXPR_NEST_MAX
#endif
#ifndef LINE_MAX
#define LINE_MAX _POSIX2_LINE_MAX
#endif
#ifndef CHARCLASS_NAME_MAX
#define CHARCLASS_NAME_MAX _POSIX2_CHARCLASS_NAME_MAX
#endif

/* This value is defined like this in regex.h. */
#define RE_DUP_MAX (0x7fff)

#endif  /* _BITS_POSIX2_LIM_H */
