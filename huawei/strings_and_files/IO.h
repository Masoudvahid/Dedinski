#ifndef IO_H
#define IO_H

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <sys/stat.h>

struct text {
    char *str;
    size_t length;
};

enum RETURN_CODE {
    SUCCESS             =  1,
    EMPTY_FILE_NAME     = -1,
    EMPTY_FILE_SIZE     = -2,
    FILE_OPEN_ERROR     = -3,
    FILE_READ_FAILED    = -4,
    EMPTY_BUFFER        = -5,
    EMPTY_TEXT          = -6,
    SWAP_FAIL           = -7,
    BUBBLE_FAIL         = -8,
    FILE_WRITE_FAILED   = -9,
    QSORT_FAIL          = -10,
    FILE_WRITE_FAIL     = -10
};

size_t GetFileSize(const char *file_name);

RETURN_CODE ReadFile(const char *file_name, size_t file_size, char **buffer);

RETURN_CODE CreatePoem(char *buffer, size_t file_size, text **poem, size_t *lines_num);

RETURN_CODE WriteFile(const char *file_name, const text *poem, size_t lines_num);

#endif //IO_H
