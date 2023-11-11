#include "philo.h"

long	actual_time(long time)
{
	struct timeval	now;

	gettimeofday (&now, NULL);
	return (((now.tv_sec * 1000) + (now.tv_usec / 1000)) - time);
}

void	sleeep(int time)
{
	long	count;

	count = actual_time(0);
	while (actual_time(count) < time)
		usleep(300);
}

void	manifest_sleep(t_philo *p)
{
	declare(p, "%d msec philo %d is sleeping\n",
		actual_time(p->g_struct->init));
	sleeep(p->g_struct->ttsleep);
}