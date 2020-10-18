
#include <sys/time.h>
#include <time.h>
#include <stdio.h>

unsigned long getTimeZone(void) {
#ifdef __linux__
    return timezone;
#else
    struct timeval tv;
    struct timezone tz;

    gettimeofday(&tv, &tz);

    return tz.tz_minuteswest * 60UL;
#endif
}

// 这个方法只能精确到秒，不能精确到毫秒
//
unsigned long getTime(void) {

    return time(NULL);
}