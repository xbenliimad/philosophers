#include "../includes/philo.h"

int main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of args.\n");
		return (0);
	}
	if (!parse_input(argc, argv))
		return (0);
	return (0);
}