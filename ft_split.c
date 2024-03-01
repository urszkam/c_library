/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:39:46 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/27 20:41:42 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of strings obtained 
** by splitting ’s’ using the character ’c’ as a delimiter.
** The array must end with a NULL pointer.
*/

#include "libft.h"

static int	count_elements(char const *str, char c)
{
	int	i;
	int	string_counter;
	int	is_word_last;
	int	res;

	i = 1;
	string_counter = 0;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c))
			string_counter++;
		i++;
	}
	is_word_last = str[i - 1] != c;
	res = string_counter + is_word_last;
	return (res);
}

static int	calc_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		len;
	int		word_len;

	len = count_elements(s, c);
	dest = (char **) malloc((len + 1) * sizeof(char *));
	i = 0;
	while (*s)
	{
		word_len = calc_len(s, c);
		if (word_len > 1)
		{
			dest[i++] = ft_strdup(s, word_len);
		}
		s += word_len;
	}
	dest[i] = 0;
	return (dest);
}
