#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include "sha1.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    SHA1_CTX context;
    SHA1Init(&context);
    SHA1Update(&context, (const u_char *)data, size);
    u_char digest[20];
    SHA1Final(digest, &context);
    return 0;
}
