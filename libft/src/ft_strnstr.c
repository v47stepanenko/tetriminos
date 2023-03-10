#include "libft.h"

char *ft_strnstr(const char*s1, const char *s2, size_t n)
{
        size_t i = 0;
        int len = ft_strlen(s2);

        while((s1[i]) && (i < n))
        {   
            if (s1[i] == s2[0])
            {
                if(ft_strncmp((char*)s1+i, (char*)s2, len-1) == 0)
                {    
                    return((char*)s1+i);
                }
            
            }   
            ++i; 
        }
        return(NULL);
    }