#include <stdint.h>
#include <stddef.h>
#include "crc16.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    crc16(0, data, size);
    return 0;
}
