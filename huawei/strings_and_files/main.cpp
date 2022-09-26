#include "IO.h"
#include "sort.h"
/// \b  me\bow mow
void printBuffer(char *buffer, size_t file_size) {
    for (int i = 0; i < file_size; i++) {
        printf("%c<%d>", buffer[i], buffer[i]);
    }
}

void printPoem(text *poem, size_t lines_num) {
    for (int i = 0; i < lines_num; ++i) {
        printf("%s\n", poem[i].str);
    }
}

int main(int argc, char **argv) {
    char *file_name = nullptr;
    if (argc > 1) {
        file_name = argv[1];

    } else {
        file_name = "../poem.txt";
    }

 //   strcpy (file_name, "meow.txt");

    size_t file_size = GetFileSize(file_name);

    char *buffer = nullptr;
    if (ReadFile(file_name, file_size, &buffer) == FILE_READ_FAILED) {
        perror("Error in reading file");
        return FILE_READ_FAILED;
    }

    size_t lines_num = 0;
    text *poem = nullptr;
    if (CreatePoem(buffer, file_size, &poem, &lines_num) == EMPTY_BUFFER) {
        perror("Failed to split buffer\n");
        return EMPTY_BUFFER;
    }

    char original_file[] = "../poem_original.txt";
    if (WriteFile(original_file, poem, lines_num) != SUCCESS) {
        perror("Write file failed\n");
        return FILE_WRITE_FAIL;
    }

    if (QSort(poem, 0, lines_num - 1, LexComp) != SUCCESS) {
        perror("Quick sort failed\n");
        return QSORT_FAIL;
    }

    char sorted_file[] = "../poem_sorted.txt";
    if (WriteFile(sorted_file, poem, lines_num) != SUCCESS) {
        perror("Write file failed\n");
        return FILE_WRITE_FAIL;
    }

    if (QSort(poem, 0, lines_num - 1, RevLexComp) != SUCCESS) {
        perror("Quick sort failed\n");
        return QSORT_FAIL;
    }

    char rev_sorted_file[] = "../poem_rev_sorted.txt";
    if (WriteFile(rev_sorted_file, poem, lines_num) != SUCCESS) {
        perror("Write file failed\n");
        return FILE_WRITE_FAIL;
    }


    free(poem);
    free(buffer);
    return 0;
}

//    printBuffer(buffer, file_size);
//    printPoem(poem, lines_num);