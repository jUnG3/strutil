#include "strutil.h"

extern void
strexplode_free(explode_t* e)
{
    for (int i = 0; i < e->size; i++) {
        free(e->result[i]);
    }
    free(e);
}
