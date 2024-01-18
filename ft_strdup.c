#include "libft.h"

char *ft_strdup(const char *s)
{
    size_t  i;
    char *dest;

    dest = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!dest)
        return (0);
    i = 0;
    while (i < len)
        dest[i] = s[i++];
    dest[i] = '\0';
    return (dest);
}