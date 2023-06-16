/* #include "fillit.h"
//#define FILENAME = "av[1]"

tetrimino_node *open_read_file();
int check_wrong_chars(char *tets_under_test);
int check_lengh(char *tets_under_test);
int check_figures(char *tets_under_test);
int hash_counter(char *tets_under_test);
int neighbors(char *tets, int i, int len);
int tetrifilter(char *tets_under_test);

tetrimino_node *get_tetriminos()
{
    tetrimino_node *head = open_read_file();
    if (head == NULL)
        printf("null here\n");
    return (head);
                                                            //  printf("%sopenread\n", tets);
}

tetrimino_node *open_read_file()
{   
    int fd;
    int figure_counter = 0;
    char *value = ft_strnew(TETRIMINO_SIZE);
    char *t_value = ft_strnew(TETRIMINO_SIZE); 
    tetrimino_node *list_head = NULL;
    if ((fd = open("tetriminos/valid_tetriminos.txt", O_RDONLY)) == -1) 
    {
        printf("Cannot open file.\n");
        return (NULL);
    }

    while (read(fd, value, TETRIMINO_SIZE) > 0) 
    {
        ft_bzero(t_value, sizeof(t_value));
        int len = ft_strlen(value);
                                                                                //printf("%d\n", len);

        if (len < 19)
        {
            printf("last chars:%zu\n", ft_strlen(value));
            printf("last one is garbage\n");
            return (NULL);
        }

        if (len == 19)
        {
                                                                                //printf("!%zu!", ft_strlen(t_value));
            t_value = ft_strndup(value, 21);
            
            t_value[20] = '\0';
            t_value[19] = '\n';
                                                                                    //printf("***%zu***", ft_strlen(t_value));
        } 
        
        if (len == 21)
        {
            t_value = ft_strndup(value, 21);
            t_value[20] = '\0';
                                                                                        // printf("reg\n%s", t_value);
        }
            
        if (tetrifilter(t_value) == 0)
        {
            printf("test not passed\n");
            return (NULL);
        }
       
                                                                                    //printf("tet %d passed all checks\n", figure_counter);

        tetrimino_node *node = lstnew(t_value, figure_counter);
        list_head = add_to_list(list_head, node);
        figure_counter++;
 
        if (figure_counter > 25) 
        {    
            printf("too many tetriminos\n");
            return (0);
        }
        
        ft_bzero(value, TETRIMINO_SIZE);
        ft_bzero(t_value, TETRIMINO_SIZE);
        num_of_figures = figure_counter;
    }
    
    close(fd);
    
    if (list_head == NULL)
        printf("null");
                                                                     // printf("***%s**openclose\n", tetriline);
    return (list_head);
}

int tetrifilter(char *tets_under_test)
{
                                                        //printf("%stetrifilter\n", tets_under_test);
    if (check_wrong_chars(tets_under_test) == 0)
    {   
        printf("odd chars found\n");
        return (0);
    }

    if (check_lengh(tets_under_test) == 0)
    {   
        printf("wrong figure lengh\n");
        return (0);
    }

    if (check_figures(tets_under_test) == 0)
    {   
        printf("wrong figure shape\n");
        return (0);
    }

    return (1);    
}

bool check_wrong_chars(char *tets_under_test)
{
    int i = 0;
    int modulo = 0;
    while (tets_under_test[i] != '\0')
    {
        modulo = (i + 1) % TETRIMINO_WIDTH;

        if (modulo == 0 && tets_under_test[i] != '\n')
        {
            // gilka
        }
        else if (tets_under_test[i] != '.' || 
                 tets_under_test[i] != '#')
        {
            // gilka
        }

        i++;
    }
    
    return (true);
} */

/* int check_lengh(char *tets_under_test)  
{
    int i = 4;
    int row = 0;
    
    if (tets_under_test[i] != '\n')
        return 0;

    while (i != 19)
    {
        while (row < 3) 
        {
            if (tets_under_test[i + 5] != '\n')
            {
                return 0;
            }

            i += 5;
            row++;              
        }

        if (tets_under_test[i] != '\n' || tets_under_test[i + 1] != '\0')
        {
            return 0;
        }
    }
    
    return (1);
} */
/*
int hash_counter(char *tets_under_test)
{   int i = 0;
    int fig_counter = 0;
   
    while (tets_under_test[i] != '\0')
    {  
        if (tets_under_test[i] == '#')
        fig_counter++;
        i++;
    }
    
    return (fig_counter);
}

int neighbors(char *tets, int i, int len)
{
    if (i - 5 >= 0 && tets[i - 5] == '#')
    {
        return (1);
    }

    if (i - 1 >= 0 && tets[i - 1] == '#')
    {
        return (1);
    }

    if (i + 1 <= len && tets[i + 1] == '#')
    {
        return (1);
    }

    if (i + 5 <= len && tets[i + 5] == '#')
    {
        return (1);
    }
    
    return (0);
}
int check_figures(char *tets_under_test)
{
    int i = 0;
    char *p = ft_strchr(tets_under_test, '#'); 
    int p_len = ft_strlen(p);

    if(neighbors(p, i, p_len) == 0)
    {
        return 0;  
    }

    i++;
      
    while (p[i] != '\0')
    {
        if (p[i] == '#')
        {
            if (neighbors(p, i, p_len) == 0)
            {
              return 0;
            }
            
        }
            i++;
    }
    
  
                                                            //printf(" figure shape good\n"); 
    return 0;
}*/

/* // DIFFERENT FILE!! FOR LIST
tetrimino_node *get_new_node(char *figure)//, int counter)
{
    tetrimino_node *node = (tetrimino_node*)malloc(sizeof(tetrimino_node));

    node->figure = ft_strdup((char*)figure);
    //printf("****\n%s****\n",node->figure);
    //node->counter= counter + 1; 
    node->next = NULL;

    return (node);
}

// DIFFERENT FILE!! FOR LIST
tetrimino_node *add_to_list(tetrimino_node *list_head, tetrimino_node *new_node)
{
    tetrimino_node *tmp = list_head;

    if (tmp == NULL)
    {
        list_head = new_node;
        return list_head;
    }

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = new_node;

    return (list_head);
} */