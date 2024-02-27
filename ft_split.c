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

static char	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_elements(char *str, char *charset)
{
	int	i;
	int	string_counter;
	int	is_word_last;
	int	res;

	i = 1;
	string_counter = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) && !is_sep(str[i - 1], charset))
			string_counter++;
		i++;
	}
	is_word_last = !is_sep(str[i - 1], charset);
	res = string_counter + is_word_last;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		i;
	int		len;
	int		word_len;

	len = count_elements(str, charset);
	dest = (char **) malloc((len + 1) * sizeof(char *));
	i = 0;
	while (*str)
	{
		word_len = ft_strlen(str, charset);
		if (word_len > 1)
			dest[i++] = ft_strcpy(str, word_len);
		str += word_len;
	}
	dest[i] = 0;
	return (dest);
}