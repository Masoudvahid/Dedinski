#include "IO.h"

size_t GetFileSize(const char *file_name) {

    assert (file_name);

    struct stat sb{};
    stat(file_name, &sb);
    return sb.st_size;
}

RETURN_CODE CreatePoem(char *buffer, size_t file_size, text **poem, size_t *lines_num) {
    if (buffer == nullptr) {
        perror("Buffer cannot be empty\n");
        return EMPTY_BUFFER;
    }

//    *lines_num = CountSymbols (buffer, file_size, '\n');

    *poem = (text *) calloc(file_size, sizeof(text));
    for (size_t i = 0, last_line_index = 0; i < file_size; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';

            (*poem)[*lines_num].str = (buffer + last_line_index);
            (*poem)[*lines_num].length = strlen(buffer + last_line_index);
            (*lines_num)++;
            last_line_index += strlen(buffer + last_line_index) + 1;

        } else if (buffer[i + 1] == '\0') {
            (*poem)[*lines_num].str = (buffer + last_line_index);
            (*poem)[*lines_num].length = strlen(buffer + last_line_index);
            (*lines_num)++;
        }
    }




/*    *poem = (text *) recalloc (*poem, *lines_num, sizeof (*poem));/// Here is the problem with reallocation, it prints 511 chars (2^9) + 1
    for (int i = 0; i < *lines_num; ++i) {
        printf("%s\n", (*poem)[i].str);
    }*/

    return SUCCESS;
}

RETURN_CODE ReadFile(const char *file_name, size_t file_size, char **buffer) {
    if (file_name == nullptr) {
        perror("File name cannot be empty\n");
        return EMPTY_FILE_NAME;
    }
    if (!file_size) {
        perror("File size cannot be empty\n");
        return EMPTY_FILE_SIZE;
    }

    FILE *fp = fopen(file_name, "r");
    if (fp == nullptr) {
        perror("Error in opening file\n");
        return FILE_OPEN_ERROR;
    }

    *buffer = (char *) calloc(file_size + 1, sizeof(char));
    size_t num_read_chars = fread(*buffer, sizeof(char), file_size, fp);

    fclose(fp);

    return (num_read_chars == file_size) ? SUCCESS : FILE_READ_FAILED;
}

RETURN_CODE WriteFile(const char *file_name, const text *poem, size_t lines_num) {
    if (file_name == nullptr) {
        perror("File name cannot be empty\n");
        return EMPTY_FILE_NAME;
    }
    if (!lines_num) {
        perror("File size cannot be empty\n");
        return EMPTY_FILE_SIZE;
    }

    FILE *fp = fopen(file_name, "w");
    if (fp == nullptr) {
        perror("Error in opening file\n");
        return FILE_OPEN_ERROR;
    }

    size_t num_write_chars = 0;
    for (int i = 0; i < lines_num; ++i) {
        if (poem[i].length){
            num_write_chars += fprintf(fp, "%s\n", poem[i].str);
        }
    }
    fclose(fp);

    return SUCCESS;
}