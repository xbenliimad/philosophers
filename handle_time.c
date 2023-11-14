#include "philo.h"

long long	actual_time(long long time)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000) - time);
}

void	sleeep(int time)
{
	long long	count;

	count = actual_time(0);
	while (actual_time(count) < time)
		usleep(300);
}

void	manifest_sleep(t_philo *p)
{
	declare(p, "%lld msec philo %d is sleeping\n",
		actual_time(p->data->init));
	sleeep(p->data->ttsleep);
}