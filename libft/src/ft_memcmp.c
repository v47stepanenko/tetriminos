#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    i = 0;

    while(i < n && ((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
    {   
        i++;
    }

    return (i == n ? 0 : ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}