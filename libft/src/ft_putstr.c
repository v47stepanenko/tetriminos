#include "libft.h"

void ft_putstr(char const *str)
{	
	int i = 0;

	if (str == NULL)
		return;

	while (str[i]) 
	{
		ft_putchar(str[i]);
		i++;
	}
}
