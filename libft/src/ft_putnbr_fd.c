#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    size_t i = 1;
    int length = n;
    int mult = n;
    int temp;

     if (length < 0)
    {
        ft_putchar_fd('-', fd);
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
        ft_putchar_fd(temp + '0', fd);
        n -= (temp * i);
        i /= 10;

    }
}