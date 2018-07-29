#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include "sha1.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    free(SHA1Data(data, size, NULL));
    return 0;
}
