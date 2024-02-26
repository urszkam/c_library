/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:34:52 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 17:37:43 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of s1 with the characters
** specified in ’set’ removed from the beginning and the end of the string
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	char	*dst;

	if (!s1)
		return (0);
	if (!set)
		return ((char *) s1);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && ft_strchr(set, s1[end]) && end >= start)
		end--;
	dst = (char *)malloc(sizeof(char) * ((end - start + 1) + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, s1 + start, (end - start + 1) + 1);
	return (dst);
}
