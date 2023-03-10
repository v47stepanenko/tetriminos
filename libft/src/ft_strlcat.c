#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t i = 0;
    size_t j = 0;
    size_t dsize = ft_strlen(dst);
    size_t ssize = ft_strlen(src); 

    if (dstsize <= dsize)
		return (ssize + dstsize);

    while (dst[i])
		i++;
		
    while ((dstsize - 1) > i && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dsize + ssize);
}