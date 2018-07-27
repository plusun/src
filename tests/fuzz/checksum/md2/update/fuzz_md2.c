#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include "md2.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    MD2_CTX context;
    MD2Init(&context);
    MD2Update(&context, (const char *)data, size);
    char digest[16];
    MD2Final(digest, &context);
    return 0;
}
