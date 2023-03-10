#include "libft.h"

static void to_end(t_list *list, t_list *new_elem)
{
    if (list == NULL)
    {
        list = new_elem;
        return;
    }

    t_list *start = list;
    while(start->next != NULL)
    {
        start = start->next;
    }

    start->next = new_elem;
}

t_list * ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
    t_list *lst_i = lst;

    t_list *new = NULL;
    
    while(lst_i != NULL)
    {
        t_list *tmp = f(lst_i);


        to_end(new, tmp);

        tmp = NULL;
        lst_i = lst_i->next;
    }
    
    return(new);
}

