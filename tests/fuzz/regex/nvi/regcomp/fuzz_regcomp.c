#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "regex.h"

void init(const char *d, int flag) {
    regex_t reg;
    if (regcomp(&reg, d, flag) == 0) {
        regfree(&reg);
    }
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    char *d = (char *)calloc(size + 8, 1);
    memcpy(d, data, size);
    init(d, REG_BASIC | REG_NOSUB);
    free(d);
    return 0;
}
