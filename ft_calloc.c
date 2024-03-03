/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:27:56 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 16:28:04 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The calloc() function allocates memory for an array of nmemb elements
** of size bytes each and returns a pointer to the allocated memory.
** The memory is set to zero. If nmemb or size is 0,
** then calloc() returns either NULL,
** or a unique pointer value that can later be successfully passed to free().
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	dest = (void *)malloc(nmemb * size);
	if (!dest)
		return (0);
	ft_bzero(dest, nmemb * size);
	return (dest);
}
