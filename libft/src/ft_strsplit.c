#include "libft.h"

static int count_words(char const *s, char c);
static char **all_the_rest(char const *s, char **fresh, char c, size_t count);

char **ft_strsplit(char const *s, char c)
{
    int number_of_words;
    size_t word_count = 0;
    
    if (s == NULL)
        return (NULL);

    number_of_words = count_words(s,c);

    char **words = (char**)malloc(sizeof(char*) * number_of_words);
    if (words == NULL)
        return(NULL);
     
    words[word_count] = *all_the_rest(s, words, c, word_count);

    return(words);
 
}

static char **all_the_rest(char const *s, char **fresh, char c, size_t count)
    {
        size_t i = 0;
        size_t len_of_word = 0;
        size_t begin;
       
        while (s[i]) 
        {
            while (s[i] == c)
            {
                i++;
            }
            
            begin = i;

            while ((s[i] != c) && (s[i]))
            {   
                len_of_word++;
                i++;
            }       
            
            fresh[count] = ft_strnew(len_of_word);
            ft_strncpy(fresh[count], &s[begin], len_of_word);
            count++;
            len_of_word = 0;
            
        }
        return(fresh);
}

static int count_words(char const *s, char c)
{ 
    size_t i = 0;
    size_t word_count = 0;
   
    while (s[i]) 
    {
        while (s[i] == c)
            i++;

        while ((s[i] != c) && (s[i]))
        {   
            i++;
        }       
        word_count++;
            
    }
    return(word_count);   
}
   
