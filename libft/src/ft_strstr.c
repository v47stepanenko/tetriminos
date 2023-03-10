#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;

	i = -1;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[++i])
		if (s1[i] == s2[0] &&
				(ft_strncmp(&s1[i], s2, ft_strlen(s2))) == 0)
			return (&((char*)s1)[i]);
	return (NULL);
}




