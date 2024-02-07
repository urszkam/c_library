/*
** converts the letter c to lower case, if possible
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}