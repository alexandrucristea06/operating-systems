/* SPDX-License-Identifier: BSD-3-Clause */

#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

struct timespec {
    long sec;
    long nsec;
};

int nanosleep (const struct timespec *req, struct timespec *rem) {
    int ret = syscall (__NR_nanosleep, req, rem);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return 0;
}

unsigned int sleep (unsigned int sec) {
    struct timespec req;
    struct timespec rem;
    req.sec = (long) sec;
    req.nsec = 0;
    if (nanosleep (&req, &rem) == -1)
        return (unsigned int) rem.sec;
    return 0;
}
