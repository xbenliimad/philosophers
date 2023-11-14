#include "philo.h"

t_data	*init_expand(char **argv)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	data->n_philos = ft_atoi(argv[1]);
	data->ttdie = ft_atoi(argv[2]);
	data->tteat = ft_atoi(argv[3]);
	data->ttsleep = ft_atoi(argv[4]);
	data->fork = malloc ((sizeof (pthread_mutex_t)
	* data->n_philos));
	data->note = malloc(sizeof(pthread_mutex_t));
	data->meal = malloc(sizeof(pthread_mutex_t));
	data->l_eat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->l_eat, NULL);
	pthread_mutex_init(data->note, NULL);
	pthread_mutex_init(data->meal, NULL);
	if (argv[5])
		data->eat_times = ft_atoi(argv[5]);
	else
		data->eat_times = -1;
	return (data);
}

t_philo	*initialize(char **argv)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = malloc(sizeof (t_philo) * ft_atoi(argv[1]));
	data = init_expand(argv);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].meals = 0;
		philo[i].thread_id = i + 1;
		philo[i].data = data;
		philo[i].thread = malloc(sizeof(pthread_t));
		philo[i].last_eat = 0;
		pthread_mutex_init(&philo->data->fork[i], NULL);
		i++;
	}
	return (philo);
}
