#include "fillit.h"

char *read_file(char *file_name)
{
    int fd =  open("2.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_putendl("Cannot open file.");
        return (NULL);
    }

    char *file_contents = read_file_contents(fd);

    return file_contents;
}

char *read_file_contents(int fd)
{
    char *file_contents;
    char *buffer = ft_strnew(TETRIMINO_SIZE);

    int read_bytes = INT_MAX; 
    while (read_bytes > 0) 
    {
        ft_bzero(buffer, TETRIMINO_SIZE);
        read_bytes = read(fd, buffer, TETRIMINO_SIZE);
        if (read_bytes <= 0)
            break;

        char *new_file_contents = ft_strjoin(file_contents, buffer);
        ft_strdel(&file_contents);
        file_contents = new_file_contents;
    }

    ft_strdel(&buffer);
    
    return file_contents;
}

tetrimino_node *get_tetriminos(char *input_file)
{
    int input_file_len = ft_strlen(input_file);
    tetrimino_node *tetriminos_head;

    int i = 0;
    while (i + TETRIMINO_SIZE <= input_file_len)
    {
        char *curr_tetrimino = ft_strndup(input_file[i], TETRIMINO_SIZE);
        curr_tetrimino[TETRIMINO_SIZE - 2] = '\n';
        curr_tetrimino[TETRIMINO_SIZE - 1] = '\0';

        tetrimino_node *new_node = get_new_node(curr_tetrimino);
        lst_add(tetriminos_head, new_node);

        i += 21; 
    }
}