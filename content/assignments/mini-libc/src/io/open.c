// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	mode_t mode = 0;
	if (flags & O_CREAT) {
		va_list args;
		va_start (args, flags);
		mode = va_arg (args, int);
		va_end (args);
	}
	int ret = syscall (__NR_openat, AT_FDCWD, filename, flags, mode);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
