/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:43:38 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/26 18:08:48 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** function returns a pointer to the last occurrence 
** of the character c in the string s
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occ;

	last_occ = 0;
	while (*s)
	{
		if (*s == c)
			last_occ = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last_occ);
}
