#include "libft.h"

char *ft_strdup(char *src)
{
    size_t i = 0;
    size_t n = ft_strlen(src);
    char *str = ft_strnew(n);
    
    while (i != n)
    {
        str[i] = src[i];
        i++;
    } 
    
    return(str);
}