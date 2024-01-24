/*
** function appends the NUL-terminated string src to the end of dst. 
** It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result
**
** returns the initial length of dst plus the length of src
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t	src_len;
    size_t	dst_len;
    size_t	i;

    src_len = ft_strlen(src);
    dst_len = ft_strlen(dst);
    i = -1;
    while (src[++i] && i < size - dst_len - 1)
        dst[dst_len + i] = src[i];
    dst[dst_len + i] = '\0';
    return (src_len + dst_len);
}