#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	if (!(res = ft_memalloc(len + 1)) || s == NULL)
		return (NULL);
	ft_strncpy(res, &s[start], len);
	res[len] = '\0';
	return (res);
}