#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*p;

  	if (argc == 5 || argc == 6)
  	{
		if (verify_arg(argv) || verify_value(argv))
			return (print_error("invalid args."));
		p = initialize(argv);
  		philosophing(p);
		return (verifier(p));
  	}
  	return (print_error("more or less args required."));
}
