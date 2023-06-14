#include "fillit.h"

char *convert_to_letters(char *tetrinimo)
{
    
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


}

void iterate_tetrimino_list(tetrimino_node *tetrimino_list, char*(*converter)(char*))
{
    tetrimino_node *list_iter = tetrimino_list;
    while (list_iter != NULL)
    {
        list_iter->figure = converter(list_iter->figure);

        list_iter = list_iter->next;
    }
}

int main(int ac, char **av)
{
    // if av != 2 -> error
    // if av == 2 -> av[1] is our filename

    char *input_file = read_file(av[1]);
    // if null -> error

    tetrimino_node *input_tetriminos = get_tetriminos(input_file);
    // if null -> error

    // VALIDATION
    if (are_tetriminos_valid(input_tetriminos, check_wrong_chars) == false ||
        are_tetriminos_valid(input_tetriminos, check_hash_count) == false ||
        are_tetriminos_valid(input_tetriminos, check_hash_neighbors) == false)
    {
        // pizdez
    }

    // CONVERT TO WORKABLE
    iterate_tetrimino_list(input_tetriminos, trim_tetrimino_square);
    iterate_tetrimino_list(input_tetriminos, convert_to_letters);

    char *smallest_square = get_smallest_square(input_tetriminos);
    // if null -> error

    put_smallest_square(smallest_square);

    return 0;
}
