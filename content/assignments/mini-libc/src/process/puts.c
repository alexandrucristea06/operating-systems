/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int puts (const char *s) {
    if (s == NULL)
        return -1;
    size_t len = strlen (s);
    ssize_t wrt = write (1, s, len);
    if (wrt < 0)
        return -1;
    ssize_t nl = write (1, "\n", 1);
    if (nl < 0)
        return -1;
    return 0;
}