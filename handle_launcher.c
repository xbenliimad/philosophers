#include "philo.h"

void	handle_eating(t_philo *p)
{
	int	current_fork;
	int	next_fork;

	current_fork = p->thread_id - 1;
	next_fork = handle_next_fork(p);
	pthread_mutex_lock(&p->data->fork[current_fork]);
	print_message(p, "%lld %d took a fork\n",
		timestamp(p->data->init));
	pthread_mutex_lock(&p->data->fork[next_fork]);
	print_message(p, "%lld %d took a fork\n",
		timestamp(p->data->init));
	print_message(p, "%lld %d is eating\n",
		timestamp(p->data->init));
	go_sleep(p->data->time_to_eat);
	pthread_mutex_lock(p->data->l_eat);
	p->last_eat = timestamp(p->data->init);
	pthread_mutex_unlock(p->data->l_eat);
	if (p->data->eat_times != -1)
		p->meals++;
	pthread_mutex_lock(p->data->meal);
	if (p->meals == p->data->eat_times)
		p->data->must_eat--;
	pthread_mutex_unlock(p->data->meal);
	pthread_mutex_unlock(&p->data->fork[current_fork]);
	pthread_mutex_unlock(&p->data->fork[next_fork]);
}

void	*routine(void *p)
{
	t_philo	*ph;

	ph = (t_philo *)p;
	while (1)
	{
		handle_eating(ph);
		handle_sleeping(ph);
		print_message(p, "%lld %d is thinking\n",
			timestamp(ph->data->init));
	}
	return (NULL);
}

int		handle_philo(t_philo *p)
{
	int	i;

	p->data->init = timestamp(0);
	i = 0;
	while (i < p->data->n_philos)
	{
		pthread_create(p[i].thread, NULL, &routine, &p[i]);
		i += 2;
	}
	go_sleep(10);
	i = 1;
	while (i < p->data->n_philos)
	{
		pthread_create(p[i].thread, NULL, &routine, &p[i]);
		i += 2;
	}
	return (0);
}