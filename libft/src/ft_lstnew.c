#include "libft.h"

t_list *ft_lstnew(void const *content, size_t content_size)
{
    t_list *head = NULL;
    head = (t_list*)malloc(sizeof(t_list));
    
    if(content == NULL)
    {
        head->content = NULL;
        head->content_size = 0;
        head->next = NULL;
    }
   
    head->content = strdup((char*)content);
    head->content_size = content_size;
    head->next = NULL;

    return head;
}