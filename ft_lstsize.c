/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:39:22 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 16:41:06 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*curr;

	counter = 0;
	curr = lst;
	while (curr)
	{
		curr = curr->next;
		counter++;
	}
	return (counter);
}
