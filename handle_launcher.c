#include "philo.h"

void	eat_start(t_philo *p)
{
	int	f_id;
	int	next_f;

	f_id = p->thread_id - 1;
	next_f = following_mutex(p);
	pthread_mutex_lock(&p->data->fork[f_id]);
	declare(p, "%d msec philo %d took a fork\n",
		actual_time(p->data->init));
	pthread_mutex_lock(&p->data->fork[next_f]);
	declare(p, "%d msec philo %d took a fork\n",
		actual_time(p->data->init));
	declare(p, "%d msec philo %d is eating\n",
		actual_time(p->data->init));
	sleeep(p->data->tteat);
	pthread_mutex_lock(p->data->l_eat);
	p->last_eat = actual_time(p->data->init);
	pthread_mutex_unlock(p->data->l_eat);
	pthread_mutex_lock(p->data->meal);
	if (p->data->eat_times != -1)
		p->meals++;
	pthread_mutex_unlock(p->data->meal);
	pthread_mutex_unlock(&p->data->fork[f_id]);
	pthread_mutex_unlock(&p->data->fork[next_f]);
}

void	*routine(void *p)
{
	t_philo	*ph;

	ph = (t_philo *)p;
	while (1)
	{
		eat_start(ph);
		manifest_sleep(ph);
		declare(p, "%d msec philo %d is thinking\n",
			actual_time(ph->data->init));
	}
	return (NULL);
}

int		philosophing(t_philo *p)
{
	int	i;

	p->data->init = actual_time(0);
	i = 0;
	while (i < p->data->n_philos)
	{
		pthread_create(p[i].thread, NULL, &routine, &p[i]);
		i += 2;
	}
	usleep(200);
	i = 1;
	while (i < p->data->n_philos)
	{
		pthread_create(p[i].thread, NULL, &routine, &p[i]);
		i += 2;
	}
	return (0);
}