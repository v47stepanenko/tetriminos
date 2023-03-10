#include <limits.h>
#include "fillit.h"

//int main(int ac, char **av)
int main (void)
{
    tlist *tetris = NULL; 
    static tlist *checked_figures = NULL;
    tetris = get_tetriminos();//(av[0]);
    //printf("main\n");
    //printf("%s", tetris->figure);
    if (tetris == NULL)
    {
        printf("no tetris \n");
        return 1;
    }
 
    
    checked_figures = processing(tetris);
    output(checked_figures);
    
   // system("leaks fillit");
    return 0;
}
