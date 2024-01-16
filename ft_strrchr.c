/*
** function returns a pointer to the last occurrence 
** of the character c in the string s
*/

char	*ft_strrchr(const char *s, int c)
{
    char	*last_occ;

    last_occ = 0;
    while (*s)
    {
        if (*s == c)
            last_occ = (char *)s;
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (last_occ);
}