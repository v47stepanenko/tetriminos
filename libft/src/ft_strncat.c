#include "libft.h"

char *ft_strncat(char *dst, const char *src, size_t len)
{
    size_t i = 0;
    size_t n = ft_strlen(dst);

    while ((src[i]) && (i < len))
    {
        dst[n] = src[i];
        i++;
        n++;
    
    }
    dst[n] = '\0';

    return(dst);
}