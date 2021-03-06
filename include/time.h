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
#ifndef _TIME_H
#define _TIME_H 1

#include <stddef.h>

#define CLOCKS_PER_SEC  1000000L


typedef long int time_t;
typedef long int clock_t;

/* Structure for a time value.  */
struct timespec
{
  time_t tv_sec;    /* Seconds.  */
  long int tv_nsec;   /* Nanoseconds.  */
};

/* Used by other time functions.  */
struct tm
{
  /* Seconds. [0-60] (1 leap second) */
  int tm_sec;
  /* Minutes. [0-59] */
  int tm_min;
  /* Hours. [0-23] */
  int tm_hour;
  /* Day.   [1-31] */
  int tm_mday;
  /* Month. [0-11] */
  int tm_mon;
  /* Year - 1900.  */
  int tm_year;
  /* Day of week. [0-6] */
  int tm_wday;
  /* Days in year.[0-365] */
  int tm_yday;
  /* DST.   [-1/0/1]*/
  int tm_isdst;
#ifdef  __USE_BSD
  /* Seconds east of UTC.  */
  long int tm_gmtoff;
  /* Timezone abbreviation.  */
  const char *tm_zone;
#else
  /* Seconds east of UTC.  */
  long int __tm_gmtoff;
  /* Timezone abbreviation.  */
  const char *__tm_zone;
#endif
};


/* Transform date and time to ASCII */
char *asctime(const struct tm *tm);
/* Transform date and time to ASCII */
char *ctime(const time_t *timep);
/* Calculate time difference */
double difftime(time_t time1, time_t time0);
/* Transform date and time to broken-down time */
struct tm *gmtime(const time_t *timep);
/* Transform date and time to broken-down time */
struct tm *localtime(const time_t *timep);
/* Transform broken-down time to timestamp */
time_t mktime(struct tm *tm);
/* Format date and time */
size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);
/* Determine processor time */
clock_t clock(void);
/* Get time in seconds  */
time_t time(time_t *p);


#endif  /* _TIME_H */
