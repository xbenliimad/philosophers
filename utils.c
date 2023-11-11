#include "philo.h"

void	declare(t_philo *p, char *str, long time)
{
	pthread_mutex_lock (p->g_struct->note);
	printf (str, (int)time, p->thread_id);
	pthread_mutex_unlock (p->g_struct->note);
}

int	following_mutex(t_philo *p)
{
	if (p->thread_id == p->g_struct->n_philos)
		return (0);
	else
		return (p->thread_id);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		result = (result * 10) + (str[i++] - 48);
		if (result > LONG_MAX && sign > 0)
			return (-1);
		if (result < LONG_MIN && sign < 0)
			return (0);
	}
	return (result * sign);
}