#include "libft.h"

void ft_lstdelone(t_list **alst, void(*del)(void *, size_t))
{
    t_list *head = *alst;
    
    del(head->content,head->content_size);
    //head->content = NULL;
    //head->content_size = 0;
    free(head);
    head = NULL;
}