#include "libft.h"

void ft_memdel(void **s)
{
    if (s != NULL)
    {
        free(*s);
        *s = NULL;
    } 
}

