#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    while (nanosleep(&req, &rem) == -1) {
        req = rem;
    }
	return rem.tv_sec;
}
