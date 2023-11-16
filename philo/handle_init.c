/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:25:46 by ibenli            #+#    #+#             */
/*   Updated: 2023/11/16 22:12:59 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_expand(char **argv)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	data->n_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->fork = malloc ((sizeof (pthread_mutex_t) * data->n_philos));
	pthread_mutex_init(&data->l_eat, NULL);
	pthread_mutex_init(&data->message, NULL);
	pthread_mutex_init(&data->meal, NULL);
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

t_philo	*handle_initialization(char **argv)
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
		philo[i].last_eat = 0;
		pthread_mutex_init(&philo->data->fork[i], NULL);
		i++;
	}
	return (philo);
}
