#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


extern int logoutx(const char *line, int status, int type);
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    int a, b;
    if (size < sizeof(int)) {
        return 0;
    }
    a = *(int *)data;
    data += sizeof(int);
    size -= sizeof(int);
    if (size < sizeof(int)) {
        return 0;
    }
    b = *(int *)data;
    data += sizeof(int);
    size -= sizeof(int);
    char *name = (char *)malloc(size + 1);
    memcpy(name, data, size);
    name[size] = '\0';
    logoutx(name, a, b);
    free(name);

    return 0;
}
