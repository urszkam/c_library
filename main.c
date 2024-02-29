#include <stdio.h>
#include "libft.h"

int main ()
{
    t_list *list = ft_lstnew(1);
    ft_lstadd_back(*lst, ft_lstnew(2));
    ft_lstadd_back(*lst, ft_lstnew(3));
    ft_lstadd_back(*lst, ft_lstnew(4));
    ft_lstadd_back(*lst, ft_lstnew(5));
    ft_lstadd_front(*lst, ft_lstnew(0));
    printf("%d", ft_lstsize(list));
    t_list *last = ft_lstlast(list);
    printf("%d", last->content);
}