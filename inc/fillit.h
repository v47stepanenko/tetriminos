#ifndef FILLIT_H
#define FILLIT_H
#define GRID_HORIZONTAL 5
#define GRID_VERTICAL 8

#include <libft.h>

typedef struct list
{
    char *figure;
    int counter;
    struct list *next;
}               tlist;
 
typedef struct glist
{
    char *grid_with_figures;
    int index_of_placed_figure;
    int total_number_of_figures;
    char *current_figure;
}               gridlist;



void input(void);		 
tlist *processing(tlist *figures);
void output(tlist *checked_list);
tlist *get_tetriminos();
tlist *lstnew(char *figure, int counter);
tlist *add_to_list(tlist *tetris_head, tlist *node);

int num_of_figures;


#endif