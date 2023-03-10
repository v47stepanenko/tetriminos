#include "libft.h"

int ft_tolower(int ch)
{
    return(ch  > 64 && ch < 91 ? ch + 32 : ch);
}