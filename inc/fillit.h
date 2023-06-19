#ifndef FILLIT_H
#define FILLIT_H

#define GRID_HORIZONTAL 7
#define GRID_VERTICAL 6
#define TETRIMINO_SIZE 21

#define TETRIMINO_WIDTH 5 
#define TETRIMINO_HEIGHT 5

#include <libft.h>
#include <limits.h>
#include <ctype.h>
 
typedef struct list // rename
{
    char *figure;
    struct list *next;
}               tetrimino_node;
  
//read_file
char *read_file(char *file_name);
char *read_file_contents(int fd);
tetrimino_node *get_tetriminos(char *input_file);

//validate_figures
bool are_tetriminos_valid(tetrimino_node *input_tetriminos, bool(*validator)(char *figure));
bool check_wrong_chars(char *tets_under_test);
bool check_hash_count(char *tets_under_test);
bool check_individual_hash_neighbors(char *tets, int i, int len);
bool check_hash_neighbors(char *tets_under_test);

//list functions
tetrimino_node *get_new_node(char *figure);//, int counter)
void add_to_list(tetrimino_node **list_head, tetrimino_node *new_node);

//convert
char *convert_to_letters(char *tetrimino) ;
char *trim_tetrimino_square(char *tetrimino_square);
void iterate_convert_tetrimino_list(tetrimino_node *tetrimino_list, char*(*converter)(char*));

//output

char *create_grid(void);
void recursive_get_smallest_square(tetrimino_node *tetriminos, char *grid, char *smallest_square);
void insert_figure(char *grid, char *figure, int insertion_point);
int count_vertical_options(char *grid);
int check_result_size(char *grid);
bool collision(char *grid, char *figure, int insertion_point);
int count_horizontal_options(char *grid, int vertical_size);

#endif
