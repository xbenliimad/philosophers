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
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				eat_times;
	int				must_eat;
	long			init;
	pthread_mutex_t	*meal;
	pthread_mutex_t	*l_eat;
	pthread_mutex_t	*note;
	pthread_mutex_t	*fork;
}	t_data;

typedef struct s_philo
{
	int			thread_id;
	long		meals;
	long		last_eat;
	pthread_t	*thread;
	t_data		*g_struct;
}	t_philo;

// Error management
int		print_error(char *msg);

// time management
void	sleeep(int time);
long	actual_time(long time);

// verifiers 
int		ft_isdigit(int c);
int		all_ate(t_philo *p);
int		verifier(t_philo *p);
int		verify_value(char **n);
int		verify_arg(char **argv);
int		ft_atoi(const char *str);

// program launch
void	*routine(void *p);
void	eat_start(t_philo *p);
int		philosophing(t_philo *p);
t_philo	*initialize(char **argv);
t_data	*init_expand(char **argv);
int		following_mutex(t_philo *philo);

// indicators
void	manifest_sleep(t_philo *p);
void	declare(t_philo *p, char *str, long time);

#endif