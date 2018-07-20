#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

extern int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "%s bug_file\n", argv[0]);
        return 1;
    }

    const char *bug_file = argv[1];
    FILE *bf = fopen(bug_file, "rb");
    fseek(bf, 0, SEEK_END);
    long size = ftell(bf);
    fseek(bf, 0, SEEK_SET);

    char *content = (char *)malloc(size);
    fread(content, size, 1, bf);
    fclose(bf);

    return LLVMFuzzerTestOneInput((const uint8_t *)content, size);
}
