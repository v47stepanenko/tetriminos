#include "libft.h"

char *ft_itoa(int n)
{
    size_t i = 1;
    size_t len = 0;
    int sign = 0;
    int dup = n;
    char *new;
    
    if (dup < 0)
    {   
        len++;
        dup *= -1;
        n *= -1;
        sign = 1;
    }

    while(dup != 0)
    {
        dup /= 10;
        len++;
    }    
    
    new = ft_strnew(len);
    if (sign > 0)
        new[0] = '-';
    
    while (n != 0)
    {
        new[len-i]= (n %10) + '0';
        n /= 10;
        i++;
    }
    
    return(new);



}