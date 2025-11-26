/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:38:44 by htavares          #+#    #+#             */
/*   Updated: 2025/11/26 13:04:59 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parse_arguments(t_philovars *philovars, char **args)
{
	t_philovars *vars;
	
	vars = (t_philovars*)malloc(sizeof(t_philovars));
	if (!vars)
		return ;
	vars->philo_num = ft_atoi(args[0]);
	vars->time_to_die = ft_atol(args[1]);
	vars->time_to_eat = ft_atol(args[2]);
	vars->time_to_sleep = ft_atol(args[3]);
	vars->eat_max_num = ft_atoi(args[4]);
	philovars = vars;
}

int	check_arguments(t_philovars *philovars, int *erroridx)
{
	if (philovars->philo_num <= 0)
		return (*erroridx = 1, 0);
	if (philovars->time_to_die <= 0)
		return (*erroridx = 2, 0);
	if (philovars->time_to_eat <= 0)
		return (*erroridx = 3, 0);
	if (philovars->time_to_sleep <= 0)
		return (*erroridx = 4, 0);
	if (philovars->eat_max_num <= 0)
		return (*erroridx = 5, 0);
	return (1);
}

void	*innit_phils(t_philovars *philovars)
{
	int 			phil_num;
	int 			i;
	t_philosopher	*philosophers;

	if (!philovars)
		return (NULL);
	phil_num = philovars->philo_num;
	philosophers = malloc(phil_num * sizeof(t_philosopher));
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < phil_num)
	{
		philosophers[i].idx = i;
		philosophers[i].time_to_die = philovars->time_to_die;
		philosophers[i].time_to_eat = philovars->time_to_eat;
		philosophers[i].time_to_sleep = philovars->time_to_sleep;
		philosophers[i].eat_max_num = philovars->eat_max_num;
		philosophers[i].fork = NULL;
		i++;
	}
	return (philosophers);
}

int	main(int ac, char **av)
{
	t_philovars 	*philovars;
	int				erroridx;
	t_philosopher	*philosophers;
	
	if (ac != 6)
		return (print_error_args(), 1);
	philovars = NULL;
	parse_arguments(philovars, av);
	if (!philovars)
		return (print_encountered_error(7), 1);
	if (!check_arguments(philovars, &erroridx))
	{
		print_encountered_error(erroridx);
		return (free(philovars), 1);
	}
	philosophers = innit_phils(philovars);
	if (!philosophers)
		return (free(philovars), print_encountered_error(6), 1);
	free(philosophers);
	return (0);
}
