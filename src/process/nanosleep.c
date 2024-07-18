#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret = syscall(__NR_nanosleep, req, rem);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
