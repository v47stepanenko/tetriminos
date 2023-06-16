#ifndef FILLIT_H
#define FILLIT_H

#define GRID_HORIZONTAL 10 //add function that expands in case no free space availbale for tetriminos 
#define GRID_VERTICAL 10
#define TETRIMINO_SIZE 21

#define TETRIMINO_WIDTH 5
#define TETRIMINO_HEIGHT 5

#include <libft.h>
#include <limits.h>


typedef struct list // rename
{
    char *figure;
    int counter; // remove OR id_in_list
    struct list *next;
}               tetrimino_node;
 
typedef struct glist
{
    char *grid_with_figures;
    //int index_of_placed_figure;
    int total_number_of_figures;
    char *current_figure;
}               gridlist;

void input(void);		 
tetrimino_node *processing(tetrimino_node *figures);
void output(tetrimino_node *checked_list);
tetrimino_node *get_tetriminos();
tetrimino_node *lstnew(char *figure, int counter);

int num_of_figures;

// REFACTORED 
  
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

#endif
