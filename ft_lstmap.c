#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
    t_list *lst2;
    t_list *node;

    if (!*lst)
        return (NULL);
    lst2 = ft_lstnew(f(lst->content));
    while (lst)
    {
        lst = lst->next;
        ft_lstadd_back(lst2, ft_lstnew(f(lst->content)));
    }
    return (lst2);
}