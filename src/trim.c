#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strutil.h>

char *trim(char *src)
{
    if (*src == '\0')
    {
        return src;
    }

    int i = 0, j = 0, length = strlen(src);

    if (length == 0)
    {
        return NULL;
    }

    char *end = src + length - 1;

    while (isspace(*(src + i)))
    {
        i++;
        length--;
    }

    while (isspace(*(end - j)))
    {
        j++;
        length--;
    }

    return strndup(src + i, length);
}
