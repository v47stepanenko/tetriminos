#include "libft.h"

void ft_putnbr(int n)
{
    size_t i = 1;
    int length = n;
    int mult = n;
    int temp;

    if (n < -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }

     if (length < 0)
    {
        ft_putchar('-');
        n *= -1;
        mult *= -1;
    }
   
    while(mult >= 10)
    {
        mult /= 10;
        i*= 10;
    }
   
    while (n != 0)
    {
        temp = n / i;
        ft_putchar(temp + '0');
        n -= (temp * i);
        i /= 10;

    }
}