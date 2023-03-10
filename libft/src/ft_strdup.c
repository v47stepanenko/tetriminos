#include "libft.h"

char *ft_strdup(char *src)
{
    size_t i = 0;
    size_t n = ft_strlen(src) + 1;

    char* str = ft_memalloc(n);
    if (str == NULL)
        return (NULL);
    
    while (i != n)
    {
        str[i] = src[i];
        i++;
    } 
    
    return(str);
}