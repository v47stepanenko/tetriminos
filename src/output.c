#include "fillit.h"

char *create_grid(void);
static char *smallest_grid;
static int smallest_combination_size;
static int result_size;

void insert_figure(char *grid, char *figure, int insertion_point);
int count_vertical_options(char *grid);
int horizontal(char *grid, int current_line);

int check_result_size(char *grid);
int find_cur_point(char *grid);
char *check_measure_return_grid(char *grid, char *figure);
char *insert_first_figure(char *grid, char *figure);
bool collision(char *grid, char *figure, int insertion_point);
int count_horizontal_options(char *grid, int vertical_size);
void recursive_find_options(gridlist *curr_grid_sorted, tetrimino_node *list_with_fresh_figures, int index_curr_fig_to_insert);
gridlist *duplicate_gridlist(gridlist *curr_grid_sorted);
void is_smallest_size(gridlist *curr_gridlist);
tetrimino_node *find_current_node(tetrimino_node *list_with_figures, int index_of_figure);



void output(tetrimino_node *checked_list)
{
    char *grid = create_grid();
    smallest_grid = ft_strdup(grid);
    smallest_combination_size = INT8_MAX;

    gridlist *list_with_grid = (gridlist*)malloc(sizeof(gridlist));
        
    grid = insert_first_figure(grid, checked_list->figure);
    //list_with_grid->index_of_placed_figure = checked_list->counter; 
    checked_list = checked_list->next;      
  
    list_with_grid->grid_with_figures = ft_strdup((char*)grid);
    //printf("****\n%s****\n", list_with_grid->grid_with_figures);
    list_with_grid->total_number_of_figures = num_of_figures;
   //printf("total num of fig = %d\n", list_with_grid->total_number_of_figures);
    recursive_find_options(list_with_grid, checked_list, 1);
    printf("Tetrimino sorting successful!\n");

    printf("smallest = \n%s\n",smallest_grid);


   // printf("%s\n",grid);
    //printf("vert options%d\n", count_vertical_options(grid));

        
        
        //printf("%s \n", smallest_grid); 
       //             printf("size  - %d\n", check_result_size(smallest_grid));
}      

void recursive_find_options(gridlist *curr_grid_sorted, tetrimino_node *list_with_fresh_figures, int index_curr_fig_to_insert)
{
  //  printf("current figure counter  = %d\n",list_with_fresh_figures->counter);
    //printf("index of placed figure = %d\n",curr_grid_sorted->index_of_placed_figure);
   // printf("total num of figures = %d\n",curr_grid_sorted->total_number_of_figures);
 //   printf("default grid before anything = \n%s\n",curr_grid_sorted->grid_with_figures);
    printf("entered\n");
    index_curr_fig_to_insert++;
    if (index_curr_fig_to_insert > curr_grid_sorted->total_number_of_figures)
    {
        // TODO: For the love of god, rename this to something that describes what the fuction does ;(
        printf("true\n");
        is_smallest_size(curr_grid_sorted); 
        printf("is smallest\n");

        return;
    }
 
    // get the actual figure
    tetrimino_node *current_node = find_current_node(list_with_fresh_figures, index_curr_fig_to_insert);
    int position_index = 0;
    gridlist *curr_grid_backup = duplicate_gridlist(curr_grid_sorted); 
    printf("before counting vert oopt\n");
   
    int vertical_options;
    if (count_vertical_options(curr_grid_sorted->grid_with_figures) == GRID_VERTICAL)
        vertical_options = GRID_VERTICAL;
    else 
        vertical_options = count_vertical_options(curr_grid_sorted->grid_with_figures) + 1;
    
    int possible_places_to_insert = vertical_options * GRID_HORIZONTAL - 2;
    printf("after counting vert oopt\n");
    
   // gridlist *curr_grid_backup = duplicate_gridlist(curr_grid_sorted);   
 
    printf("__________Places to insert %d__________\n", possible_places_to_insert);
   
    while (position_index <= possible_places_to_insert) 
    {
        // IF WE COLLIDE - WE ITERATE POSITION AND CARRY ONTO THE NEXT POSITION_INDEX
        if (collision(curr_grid_sorted->grid_with_figures, current_node->figure, position_index) == true)
        {
            position_index++;
            continue;
        } 

        // IF WE DO NOT COLLIDE - WE INSERT FIGURE
       printf("no collision\n");
       // printf("backup = \n%s\n",curr_grid_backup->grid_with_figures);  

        // insert
        curr_grid_sorted = duplicate_gridlist(curr_grid_backup);   //backup restore
        insert_figure(curr_grid_sorted->grid_with_figures, current_node->figure, position_index);
    
        //curr_grid_sorted->index_of_placed_figure = current_node->counter;

       printf("nocol, index - %d\n", position_index);    

        printf("recursing\n");   
 
        // abuse = backup

        // TODO: Remove if and bool from return 
        recursive_find_options(curr_grid_sorted, list_with_fresh_figures, index_curr_fig_to_insert);

        /*
        if (recursive_find_options(curr_grid_sorted, list_with_fresh_figures, index_curr_fig_to_insert))   // RECURSION
        {
            printf("restored from backup, \n");

            curr_grid_sorted = duplicate_gridlist(curr_grid_backup);   //backup restore

            printf("backed-up = \n%s\n",curr_grid_sorted->grid_with_figures);
            printf("current figure counter  = %d\n",list_with_fresh_figures->counter);
            printf("index of placed figure = %d\n",curr_grid_sorted->index_of_placed_figure);
            printf("current index = %d / %d\n",position_index, possible_places_to_insert);
            printf("current figure = \n%s\n",curr_grid_sorted->current_figure);
        }
        */

        position_index++;
    }

    printf("false\n");

    //// 
}

tetrimino_node *find_current_node(tetrimino_node *list_with_figures, int index_of_figure)
{
    while (list_with_figures->counter != index_of_figure)
    {
        list_with_figures = list_with_figures->next;
    }
    return list_with_figures;
}




/*
bool *recursive_find_options(gridlist *curr_grid_sorted, tetrimino_node *list_with_fresh_figures)
{
    printf("current figure counter  = %d\n",list_with_fresh_figures->counter);
    printf("index of placed figure = %d\n",curr_grid_sorted->index_of_placed_figure);
    printf("total num of figures = %d\n",curr_grid_sorted->total_number_of_figures);
    printf("default grid before anything = \n%s\n",curr_grid_sorted->grid_with_figures);
    
    if (list_with_fresh_figures->counter == curr_grid_sorted->index_of_placed_figure)
    {
        printf("entered compare,final\n");
            result_size = check_result_size(curr_grid_sorted->grid_with_figures);
            if (result_size < smallest_combination_size)
            {
                smallest_combination_size = result_size;                                                                                                                                                                                                                                                                                                                            
                ft_strcpy(smallest_grid, curr_grid_sorted->grid_with_figures); 
                printf("copied smallest grid\n%s\n", smallest_grid);   
            }
        return curr_grid_sorted;
    }
    printf("entered and skipped final return\n");
    int position_index = 0;
    gridlist *curr_grid_backup = duplicate_gridlist(curr_grid_sorted);
    int possible_places_to_insert = (count_vertical_options(curr_grid_sorted->grid_with_figures) + 1) * GRID_HORIZONTAL - 1;
                        printf("__________Places to insert %d__________\n", possible_places_to_insert);
    printf("before while\n");
    while (list_with_fresh_figures->counter != curr_grid_sorted->total_number_of_figures)// HERE!!!!!
    {
        //curr_grid_backup = duplicate_gridlist(curr_grid_sorted);
        if (position_index < possible_places_to_insert)
        {    
            printf("__*__\n%s\n__*_\n",curr_grid_backup->grid_with_figures);
            printf("____\n%s\n____\n",list_with_fresh_figures->figure);
            printf("____\nplace to insert:%d\n____\n",position_index);

            //printf("before collision\n");
            if (collision(curr_grid_sorted->grid_with_figures, list_with_fresh_figures->figure , position_index) == false)
            {   
                printf("no collision\n");
                curr_grid_backup->grid_with_figures = ft_strdup(curr_grid_sorted->grid_with_figures);
                printf("before insert\n");
                insert_figure(curr_grid_backup->grid_with_figures,list_with_fresh_figures->figure, position_index);
                position_index++;
                curr_grid_backup-> index_of_placed_figure = list_with_fresh_figures->counter;//   HERE ++
                printf("index of placed / fresh counter = %d and %d\n",curr_grid_backup->index_of_placed_figure, list_with_fresh_figures->counter);
                if(list_with_fresh_figures->next != NULL)
                {
                    printf("first not null recurse\n");
                    curr_grid_backup = recursive_find_options(curr_grid_backup, list_with_fresh_figures->next);
                }    
                else 
                {
                    printf("second null recurse\n");
                    curr_grid_backup = recursive_find_options(curr_grid_backup, list_with_fresh_figures);
                }
            }   
            else 
            {
                position_index++;
            }    
        
        }
        else   
            break;

    }
    
    printf("last return\n");
    return curr_grid_backup;

}

*/
void is_smallest_size(gridlist *curr_gridlist)
{
    printf("before check result size\n");

    result_size = check_result_size(curr_gridlist->grid_with_figures);
    printf("after check result size\n");
    if (result_size < smallest_combination_size)
    {
        smallest_combination_size = result_size;                                                                                                                                                                                                                                                                                                                            
        ft_strcpy(smallest_grid, curr_gridlist->grid_with_figures); 
        printf("copied smallest grid\n%s - %d\n", smallest_grid, result_size);   
    }
}

gridlist *duplicate_gridlist(gridlist *curr_grid_sorted)
{
    gridlist *curr_grid_backup = (gridlist*)malloc(sizeof(gridlist));
    curr_grid_backup->grid_with_figures = ft_strdup((char*)curr_grid_sorted->grid_with_figures);
    //curr_grid_backup->index_of_placed_figure = curr_grid_sorted->index_of_placed_figure;
    curr_grid_backup->total_number_of_figures = curr_grid_sorted->total_number_of_figures;
    return curr_grid_backup;
}

char *create_grid(void)
{
    int i = GRID_HORIZONTAL;
    int j = GRID_VERTICAL;
    char *grid = (char*)malloc((i * j + 1) * sizeof(char));  
    if (grid == NULL)
        return(NULL);
    ft_memset(grid, '.', i * j);
    grid[i * j] = '\0';
    j = 0;
    
    while (j < GRID_VERTICAL)
    {
        grid[i-1] = '\n';
        i+=GRID_HORIZONTAL;
        j++;
    }

    return (grid);
}
int count_horizontal_options(char *grid, int vertical_size)
{
    int i = (vertical_size * GRID_HORIZONTAL) - 1;
    int max_h_size = 0;
    int current_line_size = 0;
    while (vertical_size >= 1)
    {
        while (grid[i] == '\n' || grid[i] == '.')
        {
            i--;
        }
        current_line_size = (i % GRID_HORIZONTAL) + 1;
        if (current_line_size > max_h_size)
            max_h_size = current_line_size;

        vertical_size--;
        i = (vertical_size * GRID_HORIZONTAL) - 1;
    }
    return max_h_size;
}

int count_vertical_options(char *grid)
 
{
    printf("%s\n", grid);
    int current_line = 1;
    int i = 0;
    int char_found = 0;
    int lines_not_empty = 0;
    while (grid[i] != '\0')
    {
        while (grid[i] != '\n')
        {
            if((grid[i] != '.') && i < (GRID_HORIZONTAL * current_line) - 1) 
            {
                char_found++;
                lines_not_empty++;
                i = GRID_HORIZONTAL * current_line; 
            //    printf("%d\n", i);
                current_line++;
                char_found = 0;
            }
            else
            {
                i++;   
            }

            if (i >= (int)ft_strlen(grid))
            {
                printf("pizdez\n");
                return (lines_not_empty);
            }
        }

        if (char_found == 0)
            return (lines_not_empty);    

    }
    return (lines_not_empty);

}



bool collision(char *grid, char *figure, int insertion_point)
{
    char *temp_grid = ft_strdup(grid);  
    int i_figure = 0;
    int i_grid = 0;
    int count_lines = 1;

    while (figure[i_figure] != '\0')
    {
        while (figure[i_figure] != '\n')
        {
            if (figure[i_figure] == '.')
            {
                i_grid++;
                i_figure++;
            }
            else if (i_figure + insertion_point > (int)ft_strlen(grid))
                return true;
            
            else if (((grid[i_grid + insertion_point] >= 'A' && grid[i_grid + insertion_point] <='Z') && 
                      (figure[i_figure] >= 'A' && figure[i_figure] <= 'Z')) || 
                      (grid[i_grid + insertion_point] == '\n'))
            {
                //printf("collision\n");
                return true;
            }
            else
            {
                temp_grid[i_grid + insertion_point] = figure[i_figure];
                i_grid++;
                i_figure++;
            }
        }
        i_grid = GRID_HORIZONTAL * count_lines;
        count_lines++;
        i_figure++;
    }
    ft_strdel(&temp_grid);
    return false;    



}

char *insert_first_figure(char *grid, char *figure)
{
    int i_figure = 0;
    int i_grid = 0;
    int count_lines = 1;

    while (figure[i_figure] != '\0')
        {
            while (figure[i_figure] != '\n')
            {
                grid[i_grid] = figure[i_figure];
                i_grid++;
                i_figure++;
            }
            i_grid = GRID_HORIZONTAL * count_lines;
            count_lines++;
            i_figure++;
           
        }
    return grid;        
}

void insert_figure(char *grid, char *figure, int insertion_point) 
{
    int i_figure = 0;
    int i_grid = 0;
    int count_lines = 1;
    //int line_end = GRID_HORIZONTAL * count_lines - 1;
    
    while (figure[i_figure] != '\0')
    {
        while (figure[i_figure] != '\n')
        {
            if (figure[i_figure] == '.')
            {
                i_grid++;
                i_figure++;
            }
            else
            {
                grid[i_grid + insertion_point] = figure[i_figure];
                i_grid++;
                i_figure++;
            }
        }
        i_grid = GRID_HORIZONTAL * count_lines;
        count_lines++;
        i_figure++;
        
    } 
}

int check_result_size(char *grid)
{
    int vertical_size = count_vertical_options(grid);
   // printf("kurwa\n");
    int horizontal_size = count_horizontal_options(grid, vertical_size);
    return vertical_size * horizontal_size;
}




