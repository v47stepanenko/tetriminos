#include "libft.h"

char *ft_strndup(char *src, size_t len)
{
    size_t i = 0;

    char* str = ft_memalloc(len);
    if (str == NULL)
        return (NULL);
    
    while (i != len)
    {
        str[i] = src[i];
        i++;
    } 
    
    return(str);
}