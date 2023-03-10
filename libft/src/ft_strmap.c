#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
    size_t i = 0;
    size_t len = ft_strlen(s)+1;
    char* new = ft_strnew(len);
    while (i < (len - 1))
    {
       new[i] = (*f)(s[i]);
        i++;
    }   
    new[i] = '\0';
    return(new);
}