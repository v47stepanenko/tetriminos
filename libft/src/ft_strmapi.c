#include "libft.h"

char *ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
    size_t i = 0;
    char* new = ft_strnew(ft_strlen(s)+1);
    while (s[i])
    {
       new[i] = f(i,s[i]);
        i++;
    }   
    
    return(new);
}