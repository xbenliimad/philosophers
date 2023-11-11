#include "philo.h"

int	verify_value(char **n)
{
	int	i;

	i = 1;
	while (n[i])
	{
		if (ft_atoi(n[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}

int	verify_arg(char **argv)
{
	int	i;
	int	v;

	i = 1;
	while (argv[i])
	{
		v = 0;
		while (argv[i][v])
		{
			if (argv[i][v] >= '0' && argv[i][v] <= '9')
				v++;
			else
				return (1);
		}
				i++;
	}
	return (0);
}