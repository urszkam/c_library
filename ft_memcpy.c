

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *dest_ptr;
    unsigned char *src_ptr;

    if (!dest && !src)
        return (0);
    dest_ptr = (unsigned char *)dest;
    src_ptr = (unsigned char *)src;
    while (n-- > 0)
        *(dest_ptr++) = *src_ptr++;
    return (dest);
}