/*
** checks for a digit (0 through 9)
*/

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
