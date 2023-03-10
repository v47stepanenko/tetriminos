#include "libft.h"

int		ft_atoi(const char *str)
{
	int					check;
	unsigned long int	nbr;

	check = 0;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			check = 1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		if (nbr >= 9223372036854775807 && check == 0)
			return (-1);
		else if (nbr > 9223372036854775807 && check == 1)
			return (0);
		str++;
	}
	return (check ? -nbr : nbr);
}