#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <regex.h>

void init(const char *d, int flag) {
    regex_t reg;
    regcomp(&reg, d, flag);
    regfree(&reg);
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    char *d = (char *)malloc(size + 1);
    memcpy(d, data, size);
    d[size] = '\0';
    init(d, REG_BASIC | REG_NOSUB);
    free(d);
    return 0;
}
