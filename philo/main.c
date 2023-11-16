/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:22:53 by ibenli            #+#    #+#             */
/*   Updated: 2023/11/16 21:22:54 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*p;

	if (argc != 5 && argc != 6)
		return (print_error("Number of args is not valid."));
	if (verify_args(argv) || verify_values(argv))
		return (print_error("Args are not valid."));
	p = handle_initialization(argv);
	handle_philo(p);
	return (check_status(p));
}
