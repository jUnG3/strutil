#include <ctype.h>
#include <string.h>
#include <strutil.h>

char*
trim(char const* src)
{
    if (*src == '\0') {
        char* r = malloc(sizeof(char));
        if (r != NULL) {
            r[0] = '\0';
            return r;
        }
        return NULL;
    }

    int i = 0, j = 0, length = strlen(src);

    if (length == 0) {
        return NULL;
    }

    char const* end = src + length - 1;

    while (isspace(*(src + i))) {
        i++;
        length--;
    }

    while (isspace(*(end - j))) {
        j++;
        length--;
    }

    return strndup(src + i, length);
}
