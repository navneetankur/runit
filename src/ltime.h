#ifndef LTIME_H
#define LTIME_H
#include <stdio.h>
#include <time.h>

static inline void ltime(char *buf, char sep) {
  struct timespec ts;
  struct tm tm;

  clock_gettime(CLOCK_REALTIME, &ts);
  localtime_r(&ts.tv_sec, &tm);

  snprintf(buf, 26, "%04d-%02d-%02d%c%02d:%02d:%02d.%05ld", tm.tm_year + 1900,
           tm.tm_mon + 1, tm.tm_mday, sep, tm.tm_hour, tm.tm_min, tm.tm_sec,
           ts.tv_nsec / 10000);
}
#endif
