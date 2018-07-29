#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include "crc_extern.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    crc_buf(0, data, size);
    return 0;
}
