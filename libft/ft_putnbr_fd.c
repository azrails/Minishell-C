
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	res;
	int		min;

	min = 0;
	if (n == -2147483648)
	{
		min++;
		n++;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	res = (n % 10) + 48;
	if (min == 1)
		res = 56;
	write(fd, &res, 1);
}
