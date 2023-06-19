#include "fillit.h"

bool are_tetriminos_valid(tetrimino_node *input_tetriminos, bool(*validator)(char *figure))
{
    tetrimino_node *list_iter = input_tetriminos;
    while (list_iter != NULL)
    {
        if (validator(list_iter->figure) == false)
        {   
            return (false);
        }
        
        list_iter = list_iter->next;
    }

    return true;
}

bool check_wrong_chars(char *tets_under_test)
{
    int i = 0;
    int modulo = 0;
    while (tets_under_test[i] != '\0')
    {
        modulo = (i + 1) % TETRIMINO_WIDTH;

        if (modulo == 0 && tets_under_test[i] != '\n')
        {
           printf("CHECK_WRONG_CHARS\n");
           return false;
        }
        else if (tets_under_test[i] != '.' && 
                 tets_under_test[i] != '#' && tets_under_test[i] != '\n')
        {
                       printf("**%c**\n", tets_under_test[i]);
                       printf("**%s**\n", tets_under_test);
                       printf("**%d**\n", i);

            return false;
        }

        i++;
    }
    
    return true;
}

bool check_hash_count(char *tets_under_test)
{   
    int i = 0;
    int fig_counter = 0;
   
    while (tets_under_test[i] != '\0')
    {  
        if (tets_under_test[i] == '#')
            fig_counter++;

        i++;
    }

    if (fig_counter != 4)
        return false;
    
    return true;
}

// Sketchy. -N
bool check_individual_hash_neighbors(char *tets, int i, int len)
{
    if (i + 1 <= len && tets[i + 1] == '#')
    {
        return true;
    }
    if (i + 5 <= len && tets[i + 5] == '#')
    {
        return true;
    }
    if (i - 5 >= 0 && tets[i - 5] == '#')
    {
        return true;
    }
    if (i - 1 >= 0 && tets[i - 1] == '#')
    {
        return true;
    }

    return false;
}

bool check_hash_neighbors(char *tets_under_test)
{
    int i = 0;
    int tets_len = ft_strlen(tets_under_test);

    while (tets_under_test[i] != '\0')
    {
        if (tets_under_test[i] == '#' && 
            check_individual_hash_neighbors(tets_under_test, i, tets_len) == false)
        {
            return false;
        }

        i++;
    }

    return true;
}
