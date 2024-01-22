/*
** Outputs the string ’s’ to the given file descriptor
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}