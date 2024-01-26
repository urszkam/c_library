/*
** function scans the initial n bytes of the memory area
** pointed to by s for the first instance of c. Both c and the bytes
** are interpreted as unsigned char.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	c = (unsigned char)c;
	while (n--)
	{
		if (*(unsigned char *)s == c)
			return ((void *)s);
		s++;
	}
	return (0);
}
