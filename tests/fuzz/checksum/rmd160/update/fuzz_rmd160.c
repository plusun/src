#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include "rmd160.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    RMD160_CTX context;
    RMD160Init(&context);
    RMD160Update(&context, (const u_char *)data, size);
    u_char digest[20];
    RMD160Final(digest, &context);
    return 0;
}
