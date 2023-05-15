#include "fillit.h"
//#define FILENAME = "av[1]"
#define READSIZE 21

tlist *open_read_file();
int check_wrong_chars(char *tets_under_test);
int check_lengh(char *tets_under_test);
int check_figures(char *tets_under_test);
int hash_counter(char *tets_under_test);
int neighbors(char *tets, int i, int len);
int tetrifilter(char *tets_under_test);

tlist *get_tetriminos()
{
    tlist *head = open_read_file();
    if (head == NULL)
        printf("null here\n");
    return (head);
                                                            //  printf("%sopenread\n", tets);
}

tlist *open_read_file()
{   
    int fd;
    int figure_counter = 0;
    char *value = ft_strnew(READSIZE);
    char *t_value = ft_strnew(READSIZE); 
    tlist *tetris_head = NULL;
    if ((fd = open("2.txt", O_RDONLY)) == -1) 
    {
        printf("Cannot open file.\n");
        return (NULL);
    }

    while (read(fd, value, READSIZE) > 0) 
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

        tlist *node = lstnew(t_value, figure_counter);
        tetris_head = add_to_list(tetris_head, node);
        figure_counter++;
 
        if (figure_counter > 25) 
        {    
            printf("too many tetriminos\n");
            return (0);
        }
        
        ft_bzero(value, READSIZE);
        ft_bzero(t_value, READSIZE);
        num_of_figures = figure_counter;
    }
    
    close(fd);
    
    if (tetris_head == NULL)
        printf("null");
                                                                     // printf("***%s**openclose\n", tetriline);
    return (tetris_head);
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

int check_wrong_chars(char *tets_under_test)
{
                                                            //printf("%scheck_wrong\n", tets_under_test);
    int i = 0;
    int modulo = 0;
    while (tets_under_test[i] != '\0')                   // if not # or . or \n
    {
        modulo = (i + 1) % 5;
        if  (modulo != 0 && (tets_under_test[i] == '.' || tets_under_test[i] == '#'))
        {
                                                        //printf("first case\n");
                                                         //   printf("m: %d, i: %d, char: %c\n", modulo, i, tets_under_test[i]);
            i++;
            continue;
        }
        else if (modulo == 0 && tets_under_test[i] == '\n')
        {    
                                                         //printf("second case\n");
                                                         //   printf("m: %d, i: %d, char: %c\n", modulo, i, tets_under_test[i]);
            i++;
            continue;
        }
      
        else
        {
            printf("error chars\n");                                            //    printf("w m: %d, i: %d, char: %c\n", modulo, i, tets_under_test[i]);
            return (0);
        }
        
    }                                                        //printf("%s", tets_under_test);
                                                            //printf("all chars ok\n");
    return(1);
}

int check_lengh(char *tets_under_test)  
{
                                                                //printf("%scheck_lengh\n", tets_under_test);
    int i = 4;
    int row = 0;
    if (tets_under_test[i] != '\n')
        return 0;

    while (i != 19)                  // if line is longer than 4 chars 
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
                                                            //printf("lengh ok\n");
    }
    
    return (1);
}

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
    if (hash_counter(tets_under_test) != 4)
    {
        return 0;
    }

    int i = 0;
    int count = 0;
    char *p;

    p = ft_strchr(tets_under_test, '#'); 
    int p_len = ft_strlen(p);

    if(neighbors(p, i, p_len) == 0)
    {
        return 0;  
    }
      count++;
      i++;
      
    while (p[i] != '\0')
    {
        if (p[i] == '#')
        {
            if(neighbors(p, i, p_len) == 0)
            {
              return 0;
            }
            else
            {
                count++;
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    
    if (count != 4)
    {     
        return 0;
    }   

    if (count == 4)
        return (1);
                                                            //printf(" figure shape good\n"); 
    return 0;
}

tlist *lstnew(char *figure, int counter)
{
    tlist *node = (tlist*)malloc(sizeof(tlist));

    node->figure = ft_strdup((char*)figure);
    //printf("****\n%s****\n",node->figure);
    node->counter= counter + 1; 
    node->next = NULL;

    return (node);
}

tlist *add_to_list(tlist *tetris_head, tlist *node)
{
    tlist *tmp = tetris_head;

    if (tmp == NULL)
    {
        tetris_head = node;
        return tetris_head;
    }

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = node;

    return (tetris_head);
}