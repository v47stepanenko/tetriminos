#include "libft.h"

static Stack *new_stack(void) 
{
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  stack->head = NULL;
  return stack;
}

static void del_node(Stack *stack, const int fd)
{
    Node *tmp = stack->head;
    Node *head_p = NULL;
    Node *tmp_next = NULL;

    if (tmp->fdnum == fd)
    {
        head_p = tmp->next;
        free(tmp);
        stack->head = head_p;
        return;
    } 
    
    while (tmp != NULL)
    {
        if (tmp->next->fdnum == fd)
        {
            tmp_next = tmp->next->next;
            head_p = tmp;
            tmp = tmp->next;
            free(tmp);
            head_p->next = tmp_next;
        }
        tmp = tmp->next;
    }
}

 static Node *getnode(Stack *stack, const int fd)  
    {
        Node *tmp = stack->head;
        while (tmp != NULL)                                         // try to find FD in list
        {
            if (tmp->fdnum == fd)                                   // if it's there - return it
                return tmp;
            tmp = tmp->next;
        }     
        
        Node *new_node = (Node*)malloc(sizeof(Node));               // if it's not - create it
        new_node->fdnum = fd;
        new_node->line = NULL;
        new_node->next = stack->head;                               // add it to list       
        stack->head = new_node;
        return(new_node);                                           // return it
    }
              
int get_next_line(const int fd, char **line)
{ 
    static Stack *list = NULL;
    char *buff = ft_strnew(BUFF_SIZE);
    char *n_point;
    int rv;

    if (list == NULL)
        list = new_stack();
    
    Node *curr = getnode(list, fd);

    while ((rv = read(fd, buff, BUFF_SIZE)) >= 0)
	{
        if (curr->line == NULL)
        {   
            curr->line = ft_strdup(buff);
                                                                    // printf("$DUP$\n%s#", curr->line);
        }
        
        else    
        {
            curr->line = ft_strjoin(curr->line, buff);  
                                                                    //printf("&JOIN&\n%s#", curr->line);
        }
        n_point = ft_strchr(curr->line, '\n');
                                                                    //printf("$point$\n%s#", n_point);
        if (n_point != NULL) 
        {
            int i = n_point + 1 - curr->line;
            *line = ft_strndup(curr->line, i);
            curr->line = ft_strsub(curr->line, i, ft_strlen(n_point));
            return ft_strlen(*line);
        }

        if (rv < BUFF_SIZE)
        {
            *line = ft_strdup(curr->line);                           //write line 
            del_node(list, fd);
            return ft_strlen(*line);
        }
        ft_bzero(buff, ft_strlen(buff));
    }
    return 0;
}
