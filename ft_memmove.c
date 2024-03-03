/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:13:15 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/29 21:13:19 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copies count characters from the object pointed to by src to the object 
** pointed to by dest. Both objects are reinterpreted as arrays 
** of unsigned char. The objects may overlap: copying takes place as if 
** the characters were copied to a temporary character array 
** and then the characters were copied from the array to dest.
** If either dest or src is an invalid or null pointer, 
** the behavior is undefined, even if the count is zero.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;
	size_t			i;

	temp_d = (unsigned char *) dest;
	temp_s = (unsigned char *) src;
	i = 0;
	if (temp_d > temp_s)
	{
		while (n--)
			temp_d[n] = temp_s[n];
	}
	else
	{
		while (i < n)
		{
			temp_d[i] = temp_s[i];
			i++;
		}
	}
	return (dest);
}
