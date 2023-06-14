#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res = ft_strnew(len);
	ft_strncpy(res, &s[start], len);	
	return (res);
}