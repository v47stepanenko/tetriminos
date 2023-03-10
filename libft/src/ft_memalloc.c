#include "libft.h"

void *ft_memalloc(size_t n)
{
    void *str = (void*)malloc(n * sizeof(void));

    if (str == NULL)
        return(NULL);
    
    ft_bzero(str, n);
    
    return(str);
}