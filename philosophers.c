/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:38:44 by htavares          #+#    #+#             */
/*   Updated: 2025/11/27 19:01:12 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parse_arguments(t_philovars **philovars, char **args)
{
	t_philovars *vars;
	
	vars = (t_philovars*)malloc(sizeof(t_philovars));
	if (!vars)
		return ;
	vars->philo_num = ft_atoi(args[1]);
	vars->time_to_die = ft_atol(args[2]);
	vars->time_to_eat = ft_atol(args[3]);
	vars->time_to_sleep = ft_atol(args[4]);
	vars->eat_max_num = ft_atoi(args[5]);
	*philovars = vars;
}

int	check_arguments(t_philovars *philovars, int *erroridx)
{
	if (philovars->philo_num <= 0)
		return (*erroridx = 1, 0);
	if (philovars->time_to_die <= 0)
		return (*erroridx = 2, 0);
	if (philovars->time_to_eat < 0)
		return (*erroridx = 3, 0);
	if (philovars->time_to_sleep < 0)
		return (*erroridx = 4, 0);
	if (philovars->eat_max_num <= 0)
		return (*erroridx = 5, 0);
	return (1);
}

int	innit_vars()
{
	
}

int	main(int ac, char **av)
{
	t_philovars 	*philovars;
	int				erroridx;
	t_philosopher	*philosophers;
	t_fork			*forks;
	t_table			*table;
	
	if (ac != 6 && ac != 5)
		return (print_error_args(), 1);
	philovars = NULL;
	parse_arguments(&philovars, av);
	if (!philovars)
		return (print_error(7), 1);
	if (!check_arguments(philovars, &erroridx))
	{
		print_error(erroridx);
		return (free(philovars), 1);
	}
	if (!innit_vars(forks, table, philosophers))
		return (0);
	forks = innit_forks(philovars->philo_num);
	if (!forks)
		return (free(philovars), print_error(7), 1);
	table = innit_table(forks, philovars->philo_num);
	if (!table)
		return (destroymutex(philovars->philo_num, forks), free(forks), free(philovars), print_error(7), 1);
	philosophers = innit_phils(philovars, forks, table);
	if (!philosophers)
		return (pthread_mutex_destroy(&table->write_lock), free(table), destroymutex(philovars->philo_num ,forks), free(forks), free(philovars), print_error(6), 1);
	finish_routine(&philovars, &philosophers, &forks);
	pthread_mutex_destroy(&table->write_lock);
	free(table);
	return (0);
}
