#include "IO.h"

size_t ReadFile(char *file_name, char *text, size_t SIZE) {
    char mode[] = "r";
    FILE *file = fopen(file_name, mode);

    if (file == nullptr) {
        printf("Error in reading file.");
    }

    size_t ret_val = fread(text, sizeof *text, SIZE, file);

    fclose(file);

    return ret_val;
}
