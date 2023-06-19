#include "fillit.h"

char *convert_to_letters(char *tetrimino) 
{
    static char letter = 'A';
    char *converted = ft_strdup(tetrimino);

    int i = 0;
    while (converted[i] != '\0')
    {
        if (converted[i] == '#') 
            converted[i] = letter;

        i++;
    }
    letter++;

    return converted;
}

char *trim_tetrimino_square(char *tetrimino_square)
{
    int width = TETRIMINO_WIDTH;
    int height = TETRIMINO_HEIGHT - 1;

    int min_col = width;
    int max_col = 0;
    int min_row = height;
    int max_row = 0;

    int row = 0;
    while (row < height) 
    {
        int col = 0;
        while (col < width) 
        {
            if (tetrimino_square[(row * width) + col] == '#') 
            {
                if (col < min_col)
                    min_col = col;
                if (col > max_col)
                    max_col = col;
                if (row < min_row)
                    min_row = row;
                if (row > max_row)
                    max_row = row;
            }
            col++;
        }
        row++;
    }

    int cropped_width = max_col - min_col + 1;
    int cropped_height = max_row - min_row + 1;
    
    char *trimmed_square = ft_strnew(cropped_width * cropped_height + cropped_height);

    int trimmed_index = 0;
    row = min_row;
    while (row <= max_row) 
    {
        int col = min_col;
        while (col <= max_col) 
        {
            trimmed_square[trimmed_index++] = tetrimino_square[(row * width) + col];
            col++;
        }

        trimmed_square[trimmed_index++] = '\n';
        row++;
    }

    return trimmed_square;
}

void iterate_convert_tetrimino_list(tetrimino_node *tetrimino_list, char*(*converter)(char*))
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