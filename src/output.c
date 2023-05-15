#include "fillit.h"

char *create_grid(void);
static char *smallest_grid;
static int smallest_combination_size;
static int result_size;

char *insert_figure(char *grid, char *figure, int insertion_point);
int count_vertical_options(char *grid);
int horizontal(char *grid, int current_line);

int check_result_size(char *grid);
int find_cur_point(char *grid);
char *check_measure_return_grid(char *grid, char *figure);
char *insert_first_figure(char *grid, char *figure);
bool collision(char *grid, char *figure, int insertion_point);
int count_horizontal_options(char *grid, int vertical_size);
bool recursive_find_options(gridlist *curr_grid_sorted, tlist *list_with_fresh_figures, int index_curr_fig_to_insert);
gridlist *duplicate_gridlist(gridlist *curr_grid_sorted);
void is_smallest_size(gridlist *curr_gridlist);
tlist *find_current_node(tlist *list_with_figures, int index_of_figure);
//bool untried_places(char *grid, int possbile_options_counter, int counter);
//bool smth_figure(char *grid, tlist *list_with_fresh_figures, int position_index);
//tlist *copy_tlist (tlist *original_list);



void output(tlist *checked_list)
{
    char *grid = create_grid();
    smallest_grid = ft_strdup(grid);
    smallest_combination_size = INT8_MAX;

    gridlist *list_with_grid = (gridlist*)malloc(sizeof(gridlist));
        
            grid = insert_first_figure(grid, checked_list->figure);
            list_with_grid->index_of_placed_figure = checked_list->counter;
            checked_list = checked_list->next;      
 
    list_with_grid->grid_with_figures = ft_strdup((char*)grid);
    //printf("****\n%s****\n", list_with_grid->grid_with_figures);
    list_with_grid->total_number_of_figures = num_of_figures;
   //printf("total num of fig = %d\n", list_with_grid->total_number_of_figures);
    if (!recursive_find_options(list_with_grid, checked_list, 2))
    printf("Tetrimino sorting successful!\n");

    printf("smallest = \n%s\n",smallest_grid);


   // printf("%s\n",grid);
    //printf("vert options%d\n", count_vertical_options(grid));

        
        
        //printf("%s \n", smallest_grid); 
                    printf("size  - %d\n", check_result_size(smallest_grid));
  }      

bool recursive_find_options(gridlist *curr_grid_sorted, tlist *list_with_fresh_figures, int index_curr_fig_to_insert)
{
    printf("current figure counter  = %d\n",list_with_fresh_figures->counter);
    printf("index of placed figure = %d\n",curr_grid_sorted->index_of_placed_figure);
    printf("total num of figures = %d\n",curr_grid_sorted->total_number_of_figures);
    printf("default grid before anything = \n%s\n",curr_grid_sorted->grid_with_figures);

    if (curr_grid_sorted->index_of_placed_figure == curr_grid_sorted->total_number_of_figures)
    {
        is_smallest_size(curr_grid_sorted); 

        printf("true\n");

        ////
        return true;
    }

    // get the actual figure
    tlist *current_node = find_current_node(list_with_fresh_figures, index_curr_fig_to_insert);
    int position_index = 0;
    gridlist *curr_grid_backup;
    
    int possible_places_to_insert = (count_vertical_options(curr_grid_sorted->grid_with_figures) + 1) * GRID_HORIZONTAL - 2;
    
   // gridlist *curr_grid_backup = duplicate_gridlist(curr_grid_sorted);

    printf("__________Places to insert %d__________\n", possible_places_to_insert);

    while (position_index <= possible_places_to_insert)
    {
        // if can insert
        if (collision(curr_grid_sorted->grid_with_figures, current_node->figure, position_index) == false)
        {
            printf("no collision\n");

            // backup
            curr_grid_backup = duplicate_gridlist(curr_grid_sorted); 

            printf("backup = \n%s\n",curr_grid_backup->grid_with_figures);  

            // insert
            insert_figure(curr_grid_sorted->grid_with_figures, current_node->figure, position_index);
        
            curr_grid_sorted->index_of_placed_figure = current_node->counter;

            printf("nocol, index - %d\n", position_index);

            position_index++;

            if (index_curr_fig_to_insert + 1 <= curr_grid_sorted->total_number_of_figures)
            {
                printf("first, last not null, recurse\n");

                index_curr_fig_to_insert++;
            }

            printf("recursing\n");   

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
        }
        else
        {
            printf("collision, index - %d\n", position_index);
            position_index++;
        }
    }

    printf("false\n");

    ////
    return false;
}

tlist *find_current_node(tlist *list_with_figures, int index_of_figure)
{
    while (list_with_figures->counter != index_of_figure)
    {
        list_with_figures = list_with_figures->next;
    }
    return list_with_figures;
}




/*
bool *recursive_find_options(gridlist *curr_grid_sorted, tlist *list_with_fresh_figures)
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
            result_size = check_result_size(curr_gridlist->grid_with_figures);
            if (result_size < smallest_combination_size)
            {
                smallest_combination_size = result_size;                                                                                                                                                                                                                                                                                                                            
                ft_strcpy(smallest_grid, curr_gridlist->grid_with_figures); 
                printf("copied smallest grid\n%s\n", smallest_grid);   
            }
}

gridlist *duplicate_gridlist(gridlist *curr_grid_sorted)
{
    gridlist *curr_grid_backup = (gridlist*)malloc(sizeof(gridlist));
    curr_grid_backup->grid_with_figures = ft_strdup((char*)curr_grid_sorted->grid_with_figures);
    curr_grid_backup->index_of_placed_figure = curr_grid_sorted->index_of_placed_figure;
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
                current_line++;
                char_found = 0;
                continue;
            }
            i++;   
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
                else if (((grid[i_grid + insertion_point] >= 'A' && grid[i_grid + insertion_point] <='Z') && (figure[i_figure] >= 'A' && figure[i_figure] <= 'Z')) || (grid[i_grid + insertion_point] == '\n'))
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

char *insert_figure(char *grid, char *figure, int insertion_point) 
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
    return grid;    
    
    

}

int check_result_size(char *grid)
{
    int vertical_size = count_vertical_options(grid);
    int horizontal_size = count_horizontal_options(grid, vertical_size);
    return vertical_size * horizontal_size;
}




/* while (line_end != GRID_HORIZONTAL * count_lines - GRID_HORIZONTAL)
    {
        if (grid[line_end] == '.' || grid[line_end] == '\n')
        {
            line_end--;
            printf("line end%d\n", line_end);
        } 
        else
        {
            point_to_insert = line_end;
            continue;
        }
    
    }
    grid[point_to_insert + 1] = figure[i_figure];
}
    printf("point is %d\n", point_to_insert);
    return grid;
 */   



/*tlist *copy_tlist (tlist *original_list)
{
    tlist *copy = (tlist *)malloc(sizeof(tlist));

    if (original_list->next == NULL)
    {
        copy->counter = original_list->counter;
        copy->figure = ft_strdup(original_list->figure);
        copy->next = NULL;
        return copy;
    }
    original_list = original_list->next;
    while (original_list->next != NULL)
    {
        copy->counter = original_list->counter;
        copy->figure = ft_strdup(original_list->figure);
        copy->next = original_list->next;
        original_list = original_list->next;
    }
    return copy;
}
*/

/*bool smth_figure(char *grid, tlist *list_with_fresh_figures, int position_index)
{
    char *backup_grid = ft_strdup(grid);
    char *figure_to_insert = ft_strdup(list_with_fresh_figures->figure);
    ft_strcpy(test_grid, backup_grid);
    int possible_places_to_insert = (count_vertical_options(test_grid) + 1) * GRID_HORIZONTAL - 1;
                        printf("__________Places to insert %d__________\n", possible_places_to_insert);


    while (position_index < possible_places_to_insert)
    {
        if (collision(test_grid, figure_to_insert, position_index) == false)
        {
            insert_figure(test_grid,figure_to_insert, position_index);
            printf("%s\n", test_grid);
            position_index++;
            printf("place %dfor \n%s\n",position_index, list_with_fresh_figures->figure);
            
            if (list_with_fresh_figures->next == NULL)
            {
                printf("entered compare\n");
                result_size = check_result_size(test_grid);
                if (result_size < smallest_combination_size)
                {
                    smallest_combination_size = result_size;                                                                                                                                                                                                                                                                                                                            
                    ft_strcpy(smallest_grid, test_grid); 
                    printf("copied smallest\n");
                    printf("%s\n", smallest_grid);   
                }
            }
            else
            {
                list_with_fresh_figures = list_with_fresh_figures->next;
                printf("entered recursive\n");
                while (smth_figure(test_grid, list_with_fresh_figures,0) == false)
                {
                }
            }
        }
        else
        {    
            position_index++;
        }

        ft_strcpy(test_grid, backup_grid);
        printf("ignored\n");
        printf("place %dfor \n%s\n",position_index, list_with_fresh_figures->figure);

    }
    
    ft_strdel(&backup_grid);
    ft_strdel(&figure_to_insert); // MOVE IT TO THE END BEFORE RETURN TRUE 
    printf("place %dfor \n%s\n",position_index, list_with_fresh_figures->figure);
    return true; 
}

*/



/*int horizontal(char *grid, int current_line)// !fix , here 
{
    int k = 0;
    if (current_line == 0)
    {
        k = GRID_HORIZONTAL - 1;

        while (grid[k] == '\n' || grid[k] == '.')
        {
            k--;
        }
       // printf("for 0 address is %d\n", k + 1);
        return k + 1;
    }
    else
         k = ((current_line + 1) * GRID_HORIZONTAL) - 1;
  //         printf("for %d line is %d\n", current_line, k);  
    
    while (k != GRID_HORIZONTAL * current_line)
    {
        while (grid[k] == '\n' || grid[k] == '.')
        {
            if (k == GRID_HORIZONTAL * current_line)
            {
                //printf("address is %d\n", k);
                return k;
            }
            k--;
        }
            
        //printf("last address is %d\n", k + 1);
        return (k + 1);   
    }    
   // printf("last address2 is %d\n", k + 1);
    return (k + 1);

}
*/

/*char *insert_figure(char *grid, char *figure, int current_point) 
{
    //char *if_collision = ft_strdup(grid); 
    int i = 0;
    int k = 0;
    int v_counter = 1;

    while (figure[i] != '\0')
    {
        while (figure[i] != '\n')
        {
            
            if ((grid[current_point + k] == '.' && figure[i] == '.'))
            {   i++;
                //k++;
                printf("case 2 + cp%d + k%d + %c\n", current_point, k, grid[current_point + k]);
            }
            
            else
            {
                printf("case 3 + cp%d + k%d + %c\n", current_point, k, grid[current_point + k]);        
                if ((grid[current_point + k] >= 'A' && grid[current_point + k] <='Z') && (figure[i] >= 'A' && figure[i] <= 'Z')) 
                {    
                    printf("collision\n");
                    printf("%d\n",current_point + k); 
                    printf("%c\n",grid[current_point + k]);
                    printf("%d\n",i);
                    printf("%s\n",figure);
                    printf("\n%s\n\n\n", grid);
                    //ft_strdel(&grid);
                    return(NULL);
                }
                grid[current_point + k] = figure[i];
                //printf("%c");
                i++;
                k++;
            }
        }
         
        current_point += GRID_HORIZONTAL;
        v_counter++;     
        i++;
        k = 0;
    } 
   // ft_strdel(&if_collision);
    return grid;
}

*/
/*int check_result_size(char *grid) //not working after , to .
{
    int h = 0;
    int h_temp = 0;
    int v = 0;
    int v_temp = 0;
    int i = 0;
    int k = 0;
    int this_line = 0;
    while (grid[i] != '\0')
    {
        while (grid[i] != '\n')
        {
            if (grid[i] != '.')
            {
                this_line++;
            }
            i++;   
        }
            if (this_line > 0)
                v++;
            
            this_line = 0;
            i++;
    }
    
    k = (v * GRID_HORIZONTAL) - 1;   // 39  
    //printf("k value in horizontal - %d\n", k);
    v_temp = v;    
    //printf("v value in horizontal - %d\n", v);
    
    while (grid[k] != 0)
    {
        while (grid[k] == '.' || grid[k] == '\n')
        {
            k--;
        }
            //printf("k value in while - %d\n", k);
            if (k < GRID_HORIZONTAL)
                h_temp = k;
            else if (k%GRID_HORIZONTAL == 0)    
                h_temp = 1;
            else
                h_temp = (k%GRID_HORIZONTAL) + 1;
                    
            v_temp--;
            //printf("h_temp value in while - %d\n", h_temp);

            if (h_temp > h)
                h = h_temp;
            
            if (v_temp == 0)
                break;
            
            k = (v_temp * GRID_HORIZONTAL) - 1;
    }    
    
    return (v * h);
}
*/
/*bool is_first_figure_placed(char *grid)
{
    int count_lines = 1;
    int line_end = GRID_HORIZONTAL * count_lines - 1;

    while (line_end >= 0) //check if there is a 1st figure 
    {
        if (grid[line_end] == '.' || grid[line_end] == '\n')
            line_end--;
        
        else
        {
            printf("1st fig placed\n");
            return true;
        }
    }
    
    return false;
}
*/
/*char *check_measure_return_grid(char *grid, char *figure)   //1st fig case ready
{
    if (grid[0] == '.') 
    {
        grid = insert_figure(grid, figure);
        printf("first figure added\n");
        printf("----------------------------\n"); 
        return grid;
    }    

    char *temp_grid = ft_strdup(grid);
    char *smallest_grid;
    //char *nul_backup_figure;

    int smallest_size = 100;
    int cur_square_size;
    int i = 0;
    int line_counter = count_vertical_options(grid);
    printf("lines horizontal will check - %d\n", line_counter);
    
    while (i <= line_counter)
    {
        current_point = horizontal(grid, i);  
        printf("***current address for line %d is %d\n", i, current_point);
        //nul_backup_figure = ft_strdup(grid);
        temp_grid = insert_figure(temp_grid, figure, current_point); 
       
                                                                                while (temp_grid == NULL)
                                                                                    {
                                                                                        printf ("entered null loop");
                                                                                        //temp_grid = ft_strdup(nul_backup_figure);
                                                                                        temp_grid = ft_strdup(grid);  
                                                                                        current_point += 1;
                                                                                        temp_grid = insert_figure(temp_grid, figure, current_point);///// REMOVE + 2 TO FIX COLLISION s 
                                                                                    } // grid to work with
                                                                                
        cur_square_size = check_result_size(temp_grid);  
        printf("current figure size is %d\n", cur_square_size);             // smallest size found

    if (smallest_size > cur_square_size)                            //anyhting < than 1000
    {                                                   
        smallest_size = cur_square_size;  
        printf("current smallest size is %d\n", smallest_size);                           // smallest    
        smallest_grid = ft_strdup(temp_grid);  
        free(temp_grid);
        temp_grid = ft_strdup(grid);                        //smallest grid is now assigned 
        i++;
    }  
    else
        {
        free(temp_grid);
        temp_grid = ft_strdup(grid);  
            i++;
            
        }
    }
    //ft_strdel(&temp_grid);

     printf("----------------------------\n");  
    return smallest_grid; 
}


*/


/*bool untried_places(char *grid, int possbile_options_counter, int counter)
{
    if (counter == possbile_options_counter)
        return false;

    else   
        return true;
}
*/
/*void place_figure(t_list *checked_list)
{
    char *backup = ft_strdup(grid);                 //grid or any other temp ? 
    test_grid = ft_strcpy(test_grid, backup);                   //??
    int i = 0;
    int vertical_size = (count_vertical_options(backup)) + 1;
    int horizontal_size = count_horizontal_options(backup, vertical_size) + 1;
    int possible_options = vertical_size * GRID_VERTICAL + horizontal_size + 1;
    smallest_combination_size = INT64_MAX;

    while (untried_places(test_grid, possible_options, i) == true)
        {
            if (i == possible_options)
                break;

            else if (collision(backup, figure, i) == true) 
            {
                i++;
                continue;
            }
            
        try_figure_combinaton(i, checked_list->content);
        if(checked_list->next != NULL);
            try_figure_combination(i + 1, checked_list->next->figure);
        


    while (i <= possible_options)
    {
        

        test_grid = insert_figure(test_grid, figure, i);
        if (checked_list->next == NULL)
        {
            if (smallest_combination_size < check_result_size(test_grid))
            {
                smallest_combination_size = check_result_size(test_grid);
                smallest_grid = ft_strcpy(smallest_grid, test_grid);
            }

            else
                //call function checked_list->next 

        }

        
            test_grid = insert_figure(test_grid, figure, i);                  
                    return true;
        }

    }
    
}

*/
