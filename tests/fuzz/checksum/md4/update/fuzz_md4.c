#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include "md4.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    MD4_CTX context;
    MD4Init(&context);
    MD4Update(&context, (const char *)data, size);
    char digest[16];
    MD4Final(digest, &context);
    return 0;
}
