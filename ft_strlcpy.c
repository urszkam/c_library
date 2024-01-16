/*
** function copies up to size - 1 characters from the NUL-terminated string src 
** to dst, NUL-terminating the result
**
** returns the total length of the string src
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
    int	src_len;
    int	i;

    src_len = ft_strlen(src);
    i = -1;
    while (src[++i] && i < size - 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return (src_len);
}