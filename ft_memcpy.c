/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:45:17 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 16:47:23 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memcpy() function copies n bytes from memory area src to
** memory area dest. The memory areas must not overlap.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (!dest && !src)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while (n--)
		*(dest_ptr++) = *(src_ptr++);
	return (dest);
}
