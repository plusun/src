#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include "rmd160.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    free(RMD160Data((const unsigned char *)data, size, NULL));
    return 0;
}
