#ifndef _MYSTL_H
#define _MYSTL_H

#include <cstdio>
#include <cstdlib>


//! TODO: Implement strcpy  // DONE
//! TODO: Implement strncpy // DONE
//! TODO: Implement strcat  // DONE
//! TODO: Implement strncat // DONE
//! TODO: Implement strdup  // DONE
//! TODO: Implement fgets   // HELP
//! TODO: Implement getline // HELP
//! TODO: Implement puts    // DONE
//! TODO: Implement strchr  // DONE
//! TODO: Implement strlen  // DONE

char *StrCpy(char *dest, const char *src);

char *StrnCpy(char *dest, const char *src, int n);

char *StrCat(char *dest, const char *src);

char *StrnCat(char *dest, const char *src, int n);

char *fGets(char *str, int n, FILE *stream);

char *StrDup(const char *src);

int StrLen(const char *str);

char *StrChr(const char *str, const char *search);

#endif //_MYSTL_H
