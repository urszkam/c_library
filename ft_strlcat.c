/*
** function appends the NUL-terminated string src to the end of dst. 
** It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result
**
** returns the initial length of dst plus the length of src
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
    int	src_len;
    int	dest_len;
    int	i;

    src_len = ft_strlen(src);
    dest_len = ft_strlen(dest);
    i = -1;
    while (src[++i] && i < size - dest_len - 1)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return (src_len + dest_len);
}