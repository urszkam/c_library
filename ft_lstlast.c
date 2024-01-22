#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list *last;

    if(!lst)
        return (lst);
    last = lst;
    while(last->next != NULL)
        last = last->next
    return (last);
}