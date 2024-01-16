/*
** function fills the first n bytes of the memory area pointed to by s 
** with the constant byte c
*/

#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *ptr;

    ptr = s;
    while (n-- > 0)
        *(ptr++) = (unsigned char)c;
    return (s);
}