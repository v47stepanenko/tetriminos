#include "libft.h"

char *ft_strncat_m(char *dst, const char *src, size_t len)
{
    size_t size = strlen(dst) + len + 1;
    size_t i = 0;
    size_t n = strlen(dst);
    char *str = ft_strnew(len);

    str = ft_strcpy(str, dst);

    while ((src[i]) && (i < len))
    {
        str[n] = src[i];
        i++;
        n++;
    
    }
    str[n] = '\0';

    return(str);
}