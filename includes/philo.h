
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct s_info
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_to_eat;
} t_info;

// main
int parse_input(int argc, char *argv[]);

// utils
int	ft_atoi(const char *str);

#endif