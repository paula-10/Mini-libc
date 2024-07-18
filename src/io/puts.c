#include <stdio.h>
#include <string.h>
#include <internal/types.h>
#include <unistd.h>

int puts(const char *source) {
    size_t len = strlen(source);
    if (source != NULL) {
        write(1, source, len);
        write(1, "\n", 1);
        return len + 1;
    } else {
        return -1;
    }
}
