#include "philo.h"

void	eat_start(t_philo *p)
{
	int	f_id;
	int	next_f;

	f_id = p->thread_id - 1;
	next_f = following_mutex(p);
	pthread_mutex_lock(&p->g_struct->fork[f_id]);
	declare(p, "%d msec philo %d took a fork\n",
		actual_time(p->g_struct->init));
	pthread_mutex_lock(&p->g_struct->fork[next_f]);
	declare(p, "%d msec philo %d took a fork\n",
		actual_time(p->g_struct->init));
	declare(p, "%d msec philo %d is eating\n",
		actual_time(p->g_struct->init));
	sleeep(p->g_struct->tteat);
	pthread_mutex_lock(p->g_struct->l_eat);
	p->last_eat = actual_time(p->g_struct->init);
	pthread_mutex_unlock(p->g_struct->l_eat);
	if (p->g_struct->eat_times != -1)
		p->meals++;
	pthread_mutex_lock(p->g_struct->meal);
	if (p->meals == p->g_struct->eat_times)
		p->g_struct->must_eat--;
	pthread_mutex_unlock(p->g_struct->meal);
	pthread_mutex_unlock(&p->g_struct->fork[f_id]);
	pthread_mutex_unlock(&p->g_struct->fork[next_f]);
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
			actual_time(ph->g_struct->init));
	}
	return (NULL);
}

int		philosophing(t_philo *p)
{
	int	i;

	p->g_struct->init = actual_time(0);
	i = 0;
	while (i < p->g_struct->n_philos)
	{
		pthread_create(p[i].thread, NULL, &routine, &p[i]);
		i += 2;
	}
	usleep(200);
	i = 1;
	while (i < p->g_struct->n_philos)
	{
		pthread_create(p[i].thread, NULL, &routine, &p[i]);
		i += 2;
	}
	return (0);
}