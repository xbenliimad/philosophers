#include "philo.h"

int	all_ate(t_philo *p)
{
	pthread_mutex_lock(p->g_struct->l_eat);
	if ((actual_time(p->g_struct->init) - p->last_eat) >= p->g_struct->ttdie)
	{
		pthread_mutex_lock(p->g_struct->note);
		printf("%ld msec philo %d is dead\n",
			actual_time(p->g_struct->init), p->thread_id);
		return (1);
	}
	pthread_mutex_unlock(p->g_struct->l_eat);
  	pthread_mutex_lock(p->g_struct->meal);
	if (p->g_struct->eat_times != -1
		&& p->g_struct->must_eat == 0)
	{
		pthread_mutex_lock(p->g_struct->note);
		return (2);
	}
	pthread_mutex_unlock(p->g_struct->meal);
	return (0);
}

int	verifier(t_philo *p)
{
	int	i;
	int	value;

	i = 0;
	while (1)
	{
		while (i < p->g_struct->n_philos)
		{
			value = all_ate(&p[i]);
			if (value != 0)
				return (value);
			i++;
		}
		i = 0;
	}
	printf("Error\n");
}
