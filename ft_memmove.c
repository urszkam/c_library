/*
** Copies count characters from the object pointed to by src to the object 
** pointed to by dest. Both objects are reinterpreted as arrays 
** of unsigned char. The objects may overlap: copying takes place as if 
** the characters were copied to a temporary character array 
** and then the characters were copied from the array to dest.
** If either dest or src is an invalid or null pointer, 
** the behavior is undefined, even if the count is zero.
*/
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *temp;
    size_t i;

    temp = (unsigned char*) src;
}
