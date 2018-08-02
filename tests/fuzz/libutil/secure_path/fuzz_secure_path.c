#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

extern int secure_path(const char *line);

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    char *name = (char *)malloc(size + 1);
    memcpy(name, data, size);
    name[size] = '\0';
    secure_path(name);
    free(name);

    return 0;
}
