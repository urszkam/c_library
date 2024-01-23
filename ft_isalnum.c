/*
** checks for an alphanumeric character;
** it is equivalent to (isalpha(c) || isdigit(c))
*/

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
