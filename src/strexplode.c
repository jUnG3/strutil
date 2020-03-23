#include <string.h>
#include <strutil.h>

explode_t *strexplode(char *src, char *delimiter)
{
    explode_t *e = malloc(sizeof(explode_t *));

    if (e == NULL)
    {
        free(e);
        return NULL;
    }

    e->size = 1;
    e->result = malloc(e->size * sizeof(char *));

    char *r;
    int i = 0, length = 0, sum_length = 0;

    if (e->result == NULL)
    {
        free(e->result);
        free(e);
        return NULL;
    }

    if (!strcmp(delimiter, "\0"))
    {
        e->result[0] = strdup(src);
        return e;
    }

    if (!strcmp(src, "\0"))
    {
        e->result[0] = malloc(sizeof(char *));
        return e;
    }

    while (1)
    {
        if (i > 0)
        {
            e->result = (char **)realloc(e->result, ++e->size * sizeof(char *));
            if (e->result == NULL)
            {
                for (int j = 0; j < e->size; j++)
                {
                    free(e->result[j]);
                }
                free(e->result);
                free(e);
                return NULL;
            }
        }

        r = i == 0 ? strstr(src, delimiter) : strstr(r + 1, delimiter);

        if (r == NULL)
        {
            e->result[i] = strdup(src + sum_length + i);
            free(r);
            return e;
        }

        if (i == 0)
        {
            length = abs(src - r);
            e->result[i] = strndup(src, length);
        }
        else
        {
            length = abs(src + i + sum_length - r);
            e->result[i] = strndup(r - length, length);
        }

        sum_length += length;
        i++;
    }
}
