#include "libft.h"

void ft_lstadd(t_list **alst, t_list *newnode)
{
    newnode->next = *alst;
    *alst = newnode;
}