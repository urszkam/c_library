#include "libft.h"

char *ft_strdup(const char *s)
{
    size_t  i;
    size_t  len;
    char *dest;

    dest = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!dest)
        return (0);
    i = 0;
    len = ft_strlen(s);
    while (i < len)
    {
        dest[i] = s[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}