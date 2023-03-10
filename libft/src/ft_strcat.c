#include "libft.h"

char *ft_strcat(char *dst, const char *src)
{
    size_t i = 0;
    size_t n = ft_strlen(dst);

    while (src[i])
    {
        dst[n] = src[i];
        i++;
        n++;
    }

    dst[n] = '\0';

    return (dst);
}