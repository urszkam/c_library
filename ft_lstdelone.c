/*
** Takes as a parameter a node and frees the memory of
** the node’s content using the function ’del’ given
** as a parameter and free the node. The memory of
** ’next’ must not be freed.
*/

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del) (void *))
{
    if (!*lst)
        return ;
    del(lst->content);
    free(lst);
    lst = NULL;
}