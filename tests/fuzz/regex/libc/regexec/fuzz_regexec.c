#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "regex.h"
#include "namespace.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    size_t i;
    for (i = 0; i < size; i++) {
        if (data[i] == '\n') {
            break;
        }
    }

    if (i + 1 >= size) {
        return 0;
    }

    char *d = (char *)malloc(size + 1);
    if (d == NULL) {
        return 0;
    }
    memcpy(d, data, size);

    d[i] = '\0';
#ifdef _REPRODUCE_
    printf("pattern: %s\n", d);
#endif
    regex_t reg;
    if (regcomp(&reg, d, REG_BASIC | REG_NOSUB) != 0) {
        free(d);
        return 0;
    }

    size_t len = size - i - 1;
    char *text = d + i + 1;
    text[len] = '\0';
#ifdef _REPRODUCE_
    printf("text: %s\n", text);
#endif
    if (regexec(&reg, text, 0, NULL, 0) != 0) {
        // do nothing
        // just continue the execution of free and regfree
    }

    regfree(&reg);
    free(d);

    return 0;
}
