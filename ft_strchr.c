/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:44:11 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 16:44:13 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** function returns a pointer to the first occurrence
** of the character c in the string s
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (c == '\0' || *s == c)
		return ((char *)s);
	return (0);
}
