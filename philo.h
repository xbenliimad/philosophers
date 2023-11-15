#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h> 
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_data {
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				must_eat;
	long long		init;
	pthread_mutex_t	*meal;
	pthread_mutex_t	*l_eat;
	pthread_mutex_t	*message;
	pthread_mutex_t	*fork;
}	t_data;

typedef struct s_philo
{
	int			thread_id;
	long long	meals;
	long long	last_eat;
	pthread_t	*thread;
	t_data		*data;
}	t_philo;

// Print Error
int		print_error(char *msg);

// time management
void	go_sleep(int time);
long long	timestamp(long long time);

// check_statuss 
int		ft_isdigit(int c);
int		handle_status(t_philo *p);
int		check_status(t_philo *p);
int		verify_values(char **n);
int		verify_args(char **argv);
int		ft_atoi(const char *str);

// program launch
void	*routine(void *p);
void	handle_eating(t_philo *p);
int		handle_philo(t_philo *p);
t_philo	*handle_initialization(char **argv);
t_data	*init_expand(char **argv);
int		handle_next_fork(t_philo *philo);

// indicators
void	handle_sleeping(t_philo *p);
void	print_message(t_philo *p, char *str, long long time);

#endif