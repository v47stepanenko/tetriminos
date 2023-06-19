#include "fillit.h"

#define DEBUG 0

void db_print_tetriminos(tetrimino_node *tetrimino_list)
{
    tetrimino_node *iter = tetrimino_list;
    while (iter != NULL)
    {
        printf("\n\"");
        printf("%s", iter->figure);
        printf("\""); 

        iter = iter->next; 
    } 
}
 
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
        db_print_tetriminos(input_tetriminos);
    }


    // VALIDATION
    if (are_tetriminos_valid(input_tetriminos, check_wrong_chars) == false ||
        are_tetriminos_valid(input_tetriminos, check_hash_count) == false ||
        are_tetriminos_valid(input_tetriminos, check_hash_neighbors) == false)
    {
        ft_putendl("Error: Tetriminos are invalid.");
        return 0;
    }


    // CONVERT TO WORKABLE
    iterate_convert_tetrimino_list(input_tetriminos, trim_tetrimino_square);
    iterate_convert_tetrimino_list(input_tetriminos, convert_to_letters);        

    if (DEBUG)
    {
        printf("\033[1;32m%s\033[0m\n", "Converted tetriminos:\n");
        db_print_tetriminos(input_tetriminos);
    }
 
    char *grid = create_grid();
    char *smallest_square = create_grid();

    
    recursive_get_smallest_square(input_tetriminos, grid, smallest_square);
    ft_putendl(smallest_square);
    
   //system("leaks ex");
   return 0;
}