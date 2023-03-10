#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i = 0;
    size_t len = ft_strlen(s);
    size_t count = len < n ? len : n;
    
    while (i <= count)
    {
        if(((unsigned char*)s)[i] == (unsigned char)c)
        {    
            return (((unsigned char*)s) + i); 
        }
        i++;
    }
    
    return NULL;

}