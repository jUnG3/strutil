#ifndef _strutil_h
#define _strutil_h

#include <stdlib.h>

__BEGIN_DECLS

typedef struct explode_t
{
    size_t size;
    char** result;
} explode_t;

/*
 * Splits the given __src by the __delimeter into multiple strings. Does not
 * manipulate the __src. The memory for the result is dynamically allocated with
 * malloc() and realloc(). The caller should free the allocated memory.
 */
extern explode_t*
strexplode(char const* __restrict__ __src,
           char const* __restrict__ __delimeter);

/*
 * Removes the beggining and trailing whitespaces and returns a pointer to a new
 * string. Does not manipulate the __src.
 */
extern char*
trim(char const* _src);

/*
 * Frees the allocated memory for the explode_t.
 */
extern void
strexplode_free(explode_t* __explode);

__END_DECLS

#endif