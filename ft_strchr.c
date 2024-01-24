/*
** function returns a pointer to the first occurrence
** of the character c in the string s
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (c == '\0' || *s == c)
		return ((char *)s);
	return (0);
}
