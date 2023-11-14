#include "philo.h"

int	all_ate(t_philo *p)
{
	pthread_mutex_lock(p->data->l_eat);
	if ((actual_time(p->data->init) - p->last_eat) >= p->data->ttdie)
	{
		pthread_mutex_lock(p->data->note);
		printf("%lld msec philo %d is dead\n",
			actual_time(p->data->init), p->thread_id);
		return (1);
	}
	pthread_mutex_unlock(p->data->l_eat);
  	pthread_mutex_lock(p->data->meal);
	if (p->data->eat_times != -1
		&& p->data->must_eat == 0)
	{
		pthread_mutex_lock(p->data->note);
		return (2);
	}
	pthread_mutex_unlock(p->data->meal);
	return (0);
}

int	verifier(t_philo *p)
{
	int	i;
	int	value;

	i = 0;
	while (1)
	{
		while (i < p->data->n_philos)
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
