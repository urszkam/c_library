/*
** The strlen() function calculates the length of the string s,
** excluding the terminating null byte
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
    int	len;

    len = 0;
    while (s[len])
        len++;
    return(len);
}