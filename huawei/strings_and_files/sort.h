#ifndef STRINGS_AND_FILES_SORT_H
#define STRINGS_AND_FILES_SORT_H

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cctype>
#include "IO.h"


int LexComp(const void *first, const void *second);

int RevLexComp(const void *first, const void *second);

RETURN_CODE BubbleSort(text *poem, size_t lines_num, int (*CompFunc)(const void *first, const void *second));

RETURN_CODE QSort(text *poem, size_t begin, size_t end, int (*CompFunc)(const void *first, const void *second));

#endif //STRINGS_AND_FILES_SORT_H
