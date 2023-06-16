#include "fillit.h"

/* char *convert_to_letters(char *tetrimino)
{
    size_t i = 0;
    size_t fig_counter = 0;
    while (tetrimino[i] != '\0')
    {
        if (tetrimino[i] == '#')
        {
            tetrimino[i] = 'A' + fig_counter;
            i++;
            fig_counter++;
        } 
        else 
        i++;
    }
    return tetrimino;
}

char *ft_strrnchr(const char *s, int c, int n)
{
    int i = n;
    
    while (i != -1)
    {
        if(s[i] == c)
        {    
            return ((char*)s + i); 
        }

        i--;
    }

    return NULL;
}

char *trim_tetrimino_square(char *tetrimino_square)
{
    int len = ft_strlen(tetrimino_square);

    // find left start
    int leftmost_hash_id = INT_MAX;
    int rightmost_hash_id = 0;

    int i = 0;
    while (i < TETRIMINO_HEIGHT)
    {
        char *line_start = tetrimino_square[i * TETRIMINO_WIDTH];

        char *left_hash = ft_strchr(line_start, '#');
        if (left_hash != NULL)
        {
            int left_hash_id = left_hash - line_start;
            if (left_hash_id < leftmost_hash_id)
            {
                leftmost_hash_id = left_hash_id;
            }
        }

        char *right_hash = ft_strrnchr(line_start, '#', TETRIMINO_WIDTH);
        if (right_hash != NULL)
        {
            int right_hash_id = right_hash - line_start;

            if (right_hash_id > rightmost_hash_id)
            {
                rightmost_hash_id = right_hash_id;
            }
        }

        i++;
    }


} */

void iterate_tetrimino_list(tetrimino_node *tetrimino_list, char*(*converter)(char*))
{
    tetrimino_node *list_iter = tetrimino_list;
    char *trimmed_figure;

    while (list_iter != NULL)
    {
        trimmed_figure = converter(list_iter->figure);
        ft_strdel(&list_iter->figure);
        list_iter->figure = trimmed_figure;

        list_iter = list_iter->next;
    }
}

#define DEBUG 1

int main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putendl("Error: No file path found. Please, provide file path as an argument.");
        return 0;
    }
    
    char *input_file = read_file(av[1]);
    if (input_file == NULL)
    {
        ft_putendl("Error: Could not read file.");
        return 0;
    }
    else if (DEBUG)
    {
        printf("\033[1;32m%s\033[0m\n", "Input file read:\n");
        printf("%s\n", input_file);
    }

    tetrimino_node *input_tetriminos = get_tetriminos(input_file);

    if (DEBUG)
    {
        printf("\033[1;32m%s\033[0m\n", "Individual tetriminos:\n");

        tetrimino_node *iter = input_tetriminos;
        while (iter != NULL)
        {
            printf("%s\n", iter->figure);

            iter = iter->next;
        }
    }


    // VALIDATION
    if (are_tetriminos_valid(input_tetriminos, check_wrong_chars) == false ||
        are_tetriminos_valid(input_tetriminos, check_hash_count) == false ||
        are_tetriminos_valid(input_tetriminos, check_hash_neighbors) == false)
    {
        ft_putendl("Error: Tetriminos are invalid.");
        return 0;
    }

    /* // if null -> error

    // CONVERT TO WORKABLE
    iterate_tetrimino_list(input_tetriminos, trim_tetrimino_square);
    iterate_tetrimino_list(input_tetriminos, convert_to_letters);        
    
    char *grid = create_grid();

    char *smallest_square = get_smallest_square(input_tetriminos, grid);
    // if null -> error

    put_smallest_square(smallest_square);

    return 0;
}

char *get_smallest_square(tetrimino_node *tetriminos, char *grid)
{

} */

   return 0;
}