#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include "md2.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    free(MD2Data((const char *)data, size, NULL));
    return 0;
}
