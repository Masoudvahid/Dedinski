#include "sort.h"

int LexComp(const void *first, const void *second) {
    assert(first);
    assert(second);

    char *f_str = (char *) first;
    char *s_str = (char *) second;

    printf ("<%s> vs <%s>...\n", f_str, s_str);

    size_t i = 0;
    while (f_str[i] == s_str[i] || (isalpha(f_str[i]) || isalpha(s_str[i]))) {
        if (f_str[i] == '\0' && s_str[i] == '\0') {
            break;
        }
        i++;
    }

    return f_str[i] - s_str[i];
}

int RevLexComp(const void *first, const void *second) {
    assert(first);
    assert(second);

    char *f_str = (char *) first;
    char *s_str = (char *) second;

    size_t i = strlen(f_str);
    while (f_str[i] == s_str[i]) {
        if (f_str[i] == *f_str && s_str[i] == *s_str) {
            break;
        }
        i--;
    }

    return f_str[i] - s_str[i];
}

RETURN_CODE SwapTexts(text *first, text *second) {
    if (first == nullptr || second == nullptr) {
        return SWAP_FAIL;
    }

    text temp = *first;
    *first = *second;
    *second = temp;

    return SUCCESS;
}

RETURN_CODE BubbleSort(text *poem, size_t lines_num, int (*CompFunc)(const void *first, const void *second)) {

    if (poem == nullptr) {
        return EMPTY_TEXT;
    }

    for (int steps = 0; steps < lines_num - 1; steps++)
        for (int i = 0; i < lines_num - steps - 1; i++)
            if (CompFunc(poem[i].str, poem[i + 1].str) >= 0)
                if (SwapTexts(&poem[i], &poem[i + 1]) == SWAP_FAIL)
                    return BUBBLE_FAIL;


    return SUCCESS;
}

size_t Partition(text *poem, size_t begin, size_t end, int (*CompFunc)(const void *first, const void *second)) {
    /// HOW TO CHECK FOR EMPTINESS
    text pivot = poem[end];
    size_t i = begin - 1;
    for (size_t j = begin; j < end; j++) {
        if (CompFunc(poem[j].str, pivot.str) <= 0) {
            i++;
            SwapTexts(&poem[i], &poem[j]);
        }
    }
    SwapTexts(&poem[i + 1], &poem[end]);

    return i + 1;
}

RETURN_CODE QSort(text *poem, size_t begin, size_t end, int (*CompFunc)(const void *first, const void *second)) {
    if (poem == nullptr) {
        return EMPTY_TEXT;
    }

    if (begin < end) {
        size_t pIndex = Partition(poem, begin, end, CompFunc);
        QSort(poem, begin, pIndex - 1, CompFunc);
        QSort(poem, pIndex + 1, end, CompFunc);
    }

    return SUCCESS;
}