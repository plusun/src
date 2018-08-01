#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
char *
strspct(char *buf, size_t bufsiz, intmax_t numerator, intmax_t denominator,
        size_t digits);

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
#define N 4096
    char buf[N];
    intmax_t a;
    if (size < sizeof(a)) {
        return 0;
    }
    a = *(intmax_t *)data;
    data += sizeof(a);
    size -= sizeof(a);
    intmax_t b;
    if (size < sizeof(b)) {
        return 0;
    }
    b = *(intmax_t *)data;
    data += sizeof(b);
    size -= sizeof(b);
    size_t c;
    if (size < sizeof(c)) {
        return 0;
    }
    c = *(intmax_t *)data;
    data += sizeof(c);
    size -= sizeof(c);

    strspct(buf, N, a, b, c);
    return 0;
}
