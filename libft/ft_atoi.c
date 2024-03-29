
#include "libft.h"

int					ft_atoi(const char *nptr)
{
	int				s;
	unsigned long	n;

	s = 1;
	n = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v' ||
			*nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			s = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
	{
		if ((n * 10 + (*nptr - 48)) < n)
			return ((s > 0) ? -1 : 0);
		n = n * 10 + (*nptr - 48);
		nptr++;
	}
	return (s * n);
}
