#include "philo.h"

int	handle_status(t_philo *p)
{
	pthread_mutex_lock(p->data->l_eat);
	if ((timestamp(p->data->init) - p->last_eat) >= p->data->time_to_die)
	{
		pthread_mutex_lock(p->data->message);
		printf("%lld %d is dead\n",
			timestamp(p->data->init), p->thread_id);
		return (1);
	}
	pthread_mutex_unlock(p->data->l_eat);
  	pthread_mutex_lock(p->data->meal);
	if (p->data->eat_times != -1
		&& p->data->must_eat == 0)
	{
		pthread_mutex_lock(p->data->message);
		return (2);
	}
	pthread_mutex_unlock(p->data->meal);
	return (0);
}

int	check_status(t_philo *p)
{
	int	i;
	int	value;

	i = 0;
	while (1)
	{
		while (i < p->data->n_philos)
		{
			value = handle_status(&p[i]);
			if (value != 0)
				return (value);
			i++;
		}
		i = 0;
	}
	printf("Error\n");
}
