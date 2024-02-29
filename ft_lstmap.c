/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:47:40 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 17:00:52 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Iterates the list ’lst’ and applies the function ’f’ on the content of
 * each node. Creates a new list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to delete the content
 * of a node if needed.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*lst2;
	t_list	*node;

	if (!lst)
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, node);
		lst = lst->next;
	}
	return (lst2);
}
