#include "../../include/minishell.h"

int		compare_str(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_echo(char **argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (argv[1])
	{
		flag = compare_str(argv[1], "-n");
		if (flag == 0)
			i = 1;
		while (argv[i])
		{
			i++;
			ft_putstr_fd(argv[i], 1);
			ft_putstr_fd(" ", 1);
		}
	}
	else
		write(1, "\n", 1);
	if (flag)
		write(1, "\n", 1);
	return (errno);
}
