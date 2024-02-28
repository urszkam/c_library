/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:02:03 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 17:08:47 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function returns a pointer to a null-terminated byte string, 
** which is a duplicate of the string pointed to by s. The memory obtained 
** is done dynamically using malloc and hence it can be freed using free(). 
** It returns a pointer to the duplicated string s.
*/
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*dest;

	dest = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
