#include "philo.h"

long long	timestamp(long long time)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000) - time);
}

void	go_sleep(int time)
{
	long long	count;

	count = timestamp(0);
	while (timestamp(count) < time)
		usleep(300);
}

void	handle_sleeping(t_philo *p)
{
	print_message(p, "%lld %d is sleeping\n",
		timestamp(p->data->init));
	go_sleep(p->data->time_to_sleep);
}