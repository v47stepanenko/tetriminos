#include "libft.h"

int ft_toupper(int ch)
{
    return (((ch  > 96) && (ch < 123)) ? ch-32 : ch); 
}