#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern pid_t pidfile_read(const char *path);
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    char *name = (char *)malloc(size + 1);
    memcpy(name, data, size);
    name[size] = '\0';
    pidfile_read(name);
    free(name);

    return 0;
}
