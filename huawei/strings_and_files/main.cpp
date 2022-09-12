//! TODO Try to get infomation about file with text. (You should get text from file) There are several methods to do that
//! TODO Read about fread and fwrite to understand why it is better to use these functiina to read from file.
//! TODO Think of way to contain your text, while your program is working. (some special structures, avoid copying text)
//! TODO You need some functions that will work with strings to separate tokens or delete empty lines.
//! TODO Read about qsort in c language and pointers to a function.
//! TODO write your own comparator you should also sort lines backwards.
//! TODO write your own sorting algorithm.

#include "IO.h"


int main() {
    const size_t SIZE = 400000;
    char file_name[] = "../poem.txt";
    char text[SIZE] = "\0";

    if (ReadFile(file_name, text, SIZE)) {
        for (int i = 0; text[i] != '\0'; i++) {
            printf("%c", text[i]);
        }
    } else {
        printf("Error");
    }



    return 0;
}