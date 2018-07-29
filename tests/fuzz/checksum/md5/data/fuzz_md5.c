#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include "md5.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    free(MD5Data((const unsigned char *)data, size, NULL));
    return 0;
}
