#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

extern char     *bozo_http_date(char *, size_t);

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    char *name = (char *)malloc(size + 1);
    memcpy(name, data, size);
    name[size] = '\0';
    bozo_http_date(name, size);
    free(name);

    return 0;
}
