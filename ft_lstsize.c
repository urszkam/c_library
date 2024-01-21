#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int counter;
    t_list *curr;

    counter = 0;
    curr = lst;
    while(curr =! NULL)
    {
        curr = curr->next;
        counter++;
    }
}