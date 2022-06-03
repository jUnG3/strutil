#include "strutil.h"
#include <string.h>

explode_t*
strexplode(char* src, char* delimiter)
{
    explode_t* e = malloc(sizeof(explode_t));

    if (e == NULL) {
        strexplode_free(e);
        return NULL;
    }

    e->size = 0;
    e->result = malloc(sizeof(char*));

    char* r;
    int i = 0;
    long length = 0, sum_length = 0;

    if (e->result == NULL) {
        strexplode_free(e);
        return NULL;
    }
    e->size = 1;

    if (!strcmp(delimiter, "\0") || !strcmp(src, "\0")) {
        e->result[0] = strdup(src);
        return e;
    }

    while (1) {
        if (i > 0) {
            char** new_ptr = realloc(e->result, ++e->size * sizeof(char*));
            if (new_ptr == NULL) {
                free(new_ptr);
                return NULL;
            }
            e->result = new_ptr;
        }

        r = i == 0 ? strstr(src, delimiter) : strstr(r + 1, delimiter);

        if (r == NULL) {
            e->result[i] = strdup(src + sum_length + i);
            free(r);
            return e;
        }

        if (i == 0) {
            length = labs(src - r);
            e->result[i] = strndup(src, length);
        } else {
            length = labs(src + i + sum_length - r);
            e->result[i] = strndup(r - length, length);
        }

        sum_length += length;
        i++;
    }
}
