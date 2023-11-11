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
	{
		data->eat_times = ft_atoi(argv[5]);
		data->must_eat = data->n_philos;
	}
	else
	{
		data->eat_times = -1;
    	data->must_eat = -1;
	}
	return (data);
}

t_philo	*initialize(char **argv)
{
	t_philo	*tmp;
	t_data	*tmp2;
	int		i;

	tmp = malloc(sizeof (t_philo) * ft_atoi(argv[1]));
	tmp2 = init_expand(argv);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		tmp[i].meals = 0;
		tmp[i].thread_id = i + 1;
		tmp[i].g_struct = tmp2;
		tmp[i].thread = malloc(sizeof(pthread_t));
		tmp[i].last_eat = 0;
		pthread_mutex_init(&tmp->g_struct->fork[i], NULL);
		i++;
	}
	return (tmp);
}