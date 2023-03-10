#include "libft.h"

void ft_strclr(char *s)
{
    int len = ft_strlen(s)+1;
    ft_bzero(s, len);
}