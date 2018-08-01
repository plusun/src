#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

extern const char *
getdiskcookedname(char *buf, size_t bufsiz, const char *name);
        

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
#define N 4096
    char buf[N];

    char *name = (char *)malloc(size + 1);
    memcpy(name, data, size);
    name[size] = '\0';
    getdiskcookedname(buf, N, name);
    free(name);

    return 0;
}
