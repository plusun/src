#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include "md5.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    MD5_CTX context;
    MD5Init(&context);
    MD5Update(&context, (const char *)data, size);
    char digest[16];
    MD5Final(digest, &context);
    return 0;
}
