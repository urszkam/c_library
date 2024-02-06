#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char *) s1);
	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (i + j < len && s1[i + j] == s2[j] && s2[j])
		{
			if (s2[j + 1] == '\0')
				return ((char *) s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}