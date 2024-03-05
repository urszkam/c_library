/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:33:46 by ukaminsk          #+#    #+#             */
/*   Updated: 2024/02/28 12:34:16 by ukaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ilen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	handle_special_cases(char *str, int *n, int *len)
{
	if (*n == -2147483648)
	{
		str[(*len)--] = '8';
		*n /= 10;
	}
	else if (!*n)
		str[0] = '0';
	if (*n < 0)
	{
		str[0] = '-';
		*n *= -1;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ilen(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len--] = '\0';
	handle_special_cases(str, &n, &len);
	while (n)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
