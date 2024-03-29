
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
	{
		if (*s == (unsigned char)c)
		{
			*d = *s;
			return (d + 1);
		}
		*d++ = *s++;
	}
	return (NULL);
}
