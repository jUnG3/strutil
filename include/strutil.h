#ifndef _strutil_h
#define _strutil_h

#include <stdlib.h>

typedef struct explode_t
{
    size_t size;
    char **result;
} explode_t;

/*
 * Splits the given __src by the __delimeter into multiple strings. Does not manipulate the __src.
 * The memory for the result is dynamically allocated with malloc() and realloc().
 * The caller should free the allocated memory.
 */
extern explode_t *strexplode(char *__restrict__ __src, char *__restrict__ __delimeter);

extern char *trim(char *_src);

#endif