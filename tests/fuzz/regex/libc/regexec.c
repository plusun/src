#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <regex.h>

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
    memcpy(d, data, size);

    d[i] = '\0';
    printf("pattern: %s\n", d);
    regex_t reg;
    if (regcomp(&reg, d, REG_BASIC | REG_NOSUB) != 0) {
        free(d);
        return 0;
    }

    size_t len = size - i - 1;
    char *text = d + i + 1;
    text[len] = '\0';
    printf("text: %s\n", text);
    regexec(&reg, text, 0, NULL, 0);

    free(d);
    regfree(&reg);

    return 0;
}
