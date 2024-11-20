#include "run_length_encoding.h"

#include <stdlib.h>
#include <string.h>

char *encode(const char *text)
{
    if (text == NULL)
    {
        return NULL;
    }

    size_t length = strlen(text);
    if (length == 0)
    {
        return "";
    }
}