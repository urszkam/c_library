/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:09:00 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 18:09:43 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function ’f’ to each character of the string ’s’, 
** and passing its index as first argument to create a new string 
** (with malloc(3)) resulting from successive applications of ’f’.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*dest;
	int		i;

	dest = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = -1;
	while (s[++i])
		dest[i] = f(i, s[i]);
	dest[i] = '\0';
	return (dest);
}
