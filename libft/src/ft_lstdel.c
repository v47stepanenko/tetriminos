#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    t_list *head = *alst;
    t_list *temp = NULL;

    while (head != NULL)
    {    
        temp = head->next;
        del(head->content,head->content_size);
        free(head);
        head = temp; 
    }
    
    head = NULL;
}