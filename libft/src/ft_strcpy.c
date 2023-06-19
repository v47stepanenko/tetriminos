#include "libft.h"

char *ft_strcpy(char *dst, const char *src)
{
    size_t i = 0;
    size_t n = ft_strlen(src);

    while (i < n)
    {
        dst[i] = src[i];
        i++;
    }
    
    return(dst);
}