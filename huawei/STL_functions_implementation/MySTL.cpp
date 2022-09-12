#include "MySTL.h"

char *StrCpy(char *dest, const char *src) {
    if (dest == nullptr) {
        return nullptr;
    }
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';

    return dest;
}

char *StrnCpy(char *dest, const char *src, int n) {
    if (dest == nullptr && src == nullptr) {
        return nullptr;
    }
    while (*src != '\0' && n--) {
        *dest++ = *src++;
    }
    *dest = '\0';

    return dest;
}


char *StrCat(char *dest, const char *src) {
    if (dest == nullptr && src == nullptr) {
        return nullptr;
    }
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';

    return dest;
}

char *StrnCat(char *dest, const char *src, int n) {
    if (dest == nullptr && src == nullptr) {
        return nullptr;
    }
    while (*dest++ != '\0') {
        dest++;
    }
    while (*src != '\0' && n--) {
        *dest++ = *src++;
    }
    *dest = '\0';

    return dest;
}

char *fGets(char *str, int n, FILE *stream) {


}


char *StrDup(const char *src) {
    if (src == nullptr) {
        return nullptr;
    }
    char *dest = (char *) malloc(sizeof(src));
    StrCpy(dest, src);

    return dest;
}

int StrLen(const char *str) {
    if (str == nullptr) {
        return 0;
    }
    int len = 0;
    while (*str != '\0') {
        len++;
        *str++;
    }
    return len;
}

char *StrChr(const char *str, const char *search) {
    if (str == nullptr && search == nullptr) {
        return nullptr;
    }
    int str_size = StrLen(str);
    char *res = (char *) malloc(str_size);
    while (*str != *search && *str != '\0') {
        *str++;
    }
    StrCpy(res, str);

    return res;
}

int Puts(const char *str) {
    int i = 0;
    while (str[i]) {
        if (putchar(str[i]) == EOF) {
            return EOF;
        }
        i++;
    }
    if (putchar('\n') == EOF) {
        return EOF;
    }
    return 1;
}
