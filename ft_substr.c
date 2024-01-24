/*
** Allocates (with malloc(3)) and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	d_len;
	size_t		i;
	char	*dest;

	s_len = ft_strlen(s);
	if (s_len - start > len)
		d_len = len;
	else
		d_len = s_len - start;
	dest = (char *) malloc((d_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < d_len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
