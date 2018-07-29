#include <stdint.h>
#include <stddef.h>

uint32_t crc32(uint32_t, const uint8_t *, size_t);

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    crc32(0, data, size);
    return 0;
}
