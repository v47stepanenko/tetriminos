#include "fillit.h"

static int smallest_combination_size = INT8_MAX;

void recursive_get_smallest_square(tetrimino_node *current_node, char *grid, char *smallest_square)
{
    if (current_node == NULL)
    {
        int result_size = check_result_size(grid);
        if (result_size < smallest_combination_size)
        {
            smallest_combination_size = result_size;
            ft_strcpy(smallest_square, grid);
        } 

        return;
    }
   
    int vertical_options = count_vertical_options(grid);
    if (vertical_options != GRID_VERTICAL)
        vertical_options += 1;
    
    int possible_places_to_insert = vertical_options * GRID_HORIZONTAL - 2;
    
    int position_index = 0;
    while (position_index <= possible_places_to_insert) 
    {
        if (collision(grid, current_node->figure, position_index) == false)
        {
            char *new_grid = ft_strdup(grid);
            insert_figure(new_grid, current_node->figure, position_index);

            recursive_get_smallest_square(current_node->next, new_grid, smallest_square);

            ft_strdel(&new_grid);
        }
        position_index++;
    }
}

char *create_grid(void)
{
    int grid_size = GRID_HORIZONTAL * GRID_VERTICAL;
    char *grid = ft_strnew(grid_size);
    ft_memset(grid, '.', grid_size);
    int j = 1;
    
    while (j <= GRID_VERTICAL)
    {
        grid[j * GRID_HORIZONTAL - 1] = '\n';
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
            }
            else
            {
                i++;   
            }

            if (i >= (int)ft_strlen(grid))
            {
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
    size_t grid_size = ft_strlen(grid);
    size_t figure_size = ft_strlen(figure);
    char *temp_grid = ft_strdup(grid);

    size_t i_figure = 0;
    size_t i_grid = 0;
    size_t count_lines = 1;

    while (i_figure < figure_size)
    {
        while (figure[i_figure] != '\n')
        {
            if (figure[i_figure] == '.')
            {
                i_grid++;
                i_figure++;
            }
            else if (i_figure + insertion_point >= grid_size)
            {
                free(temp_grid);
                return true;
            }
            else if (i_grid + insertion_point >= grid_size)
            {
                free(temp_grid);
                return true;
            }
            else if ((isupper(grid[i_grid + insertion_point]) && isupper(figure[i_figure])) ||
                     grid[i_grid + insertion_point] == '\n')
            {
                free(temp_grid);
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

    free(temp_grid);
    return false;
}

void insert_figure(char *grid, char *figure, int insertion_point) 
{
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
    int horizontal_size = count_horizontal_options(grid, vertical_size);
    return vertical_size * horizontal_size;
}