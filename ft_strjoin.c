/*
** Allocates (with malloc(3)) and returns a new string, 
** which is the result of the concatenation of ’s1’ and ’s2’.
*/

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    int     i;
    int     j;
    char    *dest;

    dest = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!dest)
        return (0);
    i = 0;
    while(s1[i])
        dest[i] = s1[i++];
    j = 0;
    while(s2[j])
        dest[i + j] = s2[j++];
    dest[i + j] = '\0';
    return (dest);
}