#include "philo.h"

long	actual_time(long time)
{
	struct timeval now;

	if (gettimeofday(&now, NULL) == -1)
		return (0);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000) - time);
}

void	sleeep(int time)
{
	long	count;

	count = actual_time(0);
	while (actual_time(count) < time)
		usleep(200);
}

void	manifest_sleep(t_philo *p)
{
	declare(p, "%d msec philo %d is sleeping\n",
		actual_time(p->data->init));
	sleeep(p->data->ttsleep);
}