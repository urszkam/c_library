#include "libft.h"

void ft_lstclear(t_list **lst, void (*del) (void *))
{
    t_list *curr;

    while(*lst)
    {
        curr = *lst;
        *lst = (*lst)->next;
        ft_lstdelone(curr, del);
    }
}