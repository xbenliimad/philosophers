#include "../includes/philo.h"

int parse_input(int argc, char *argv[])
{
    int i;
    t_info  info;

    i = 0;
    while (i < 5)
    {
        if (argv[i++] == NULL)
           return (FALSE);
    }
    info.number_of_philosophers = ft_atoi(argv[1]);
    info.time_to_die = ft_atoi(argv[2]);
    info.time_to_eat = ft_atoi(argv[3]);
    info.time_to_sleep = ft_atoi(argv[4]);
    info.number_of_times_to_eat = 0;
    if (argc == 6)
        info.number_of_times_to_eat = ft_atoi(argv[5]);
    if (!info.number_of_philosophers || !info.time_to_eat || !info.time_to_die || !info.time_to_sleep || (argc == 6 && !info.number_of_times_to_eat))
    {
        printf("Error getting the args.\n");
        return (FALSE);
    }
    printf("Success!\n");
    return (TRUE);
}