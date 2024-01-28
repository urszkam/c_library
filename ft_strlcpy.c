/*
** function copies up to size - 1 characters from the NUL-terminated string src 
** to dst, NUL-terminating the result
**
** returns the total length of the string src
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t	src_len;
    size_t	i;

    src_len = ft_strlen(src);
    if (size)
    {
        i = 0;
        while (i < size - 1 && src[i])
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (src_len);
}