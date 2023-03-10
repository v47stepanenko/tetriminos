#include "libft.h"

char *ft_strnew(size_t n)
{
    void *str = (void*)malloc(n + 1 * sizeof(void));  
    if (str == NULL)
        return(NULL);
    ft_memset(str, '\0', n + 1);
    
    return(str);
}