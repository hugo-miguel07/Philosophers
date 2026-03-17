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

void	parse_arguments(t_philovars **philovars, char **args, int ac)
{
	t_philovars	*vars;

	vars = (t_philovars *)malloc(sizeof(t_philovars));
	if (!vars)
		return ;
	vars->philo_num = ft_atoi(args[1]);
	vars->time_to_die = ft_atol(args[2]);
	vars->time_to_eat = ft_atol(args[3]);
	vars->time_to_sleep = ft_atol(args[4]);
	if (ac == 6)
		vars->eat_max_num = ft_atoi(args[5]);
	else
		vars->eat_max_num = -1;
	*philovars = vars;
}

int	check_arguments(t_philovars *philovars, int *erroridx, char **args, int ac)
{
	if (!is_number(args[1]))
		return (*erroridx = 1, 0);
	if (!is_number(args[2]))
		return (*erroridx = 2, 0);
	if (!is_number(args[3]))
		return (*erroridx = 3, 0);
	if (!is_number(args[4]))
		return (*erroridx = 4, 0);
	if (ac == 6 && !is_number(args[5]))
		return (*erroridx = 5, 0);
	if (philovars->philo_num <= 0)
		return (*erroridx = 1, 0);
	if (philovars->time_to_die <= 0)
		return (*erroridx = 2, 0);
	if (philovars->time_to_eat <= 0)
		return (*erroridx = 3, 0);
	if (philovars->time_to_sleep <= 0)
		return (*erroridx = 4, 0);
	if (ac == 6)
	{
		if (philovars->eat_max_num <= 0)
			return (*erroridx = 5, 0);
	}
	return (1);
}

int	innit_vars(t_philovars *pv, t_fork **f, t_table **t, t_philosopher **p)
{
	*f = innit_forks(pv->philo_num);
	if (!*f)
		return (free(pv), print_error(7), 0);
	*t = innit_table(*f, pv->philo_num);
	if (!*t)
	{
		destroymutex(pv->philo_num, *f);
		print_error(7);
		return (free(*f), free(pv), 0);
	}
	*p = innit_phils(pv, *f, *t);
	if (!*p)
	{
		pthread_mutex_destroy(&(*t)->write_lock);
		pthread_mutex_destroy(&(*t)->simulation_lock);
		free(*t);
		destroymutex(pv->philo_num, *f);
		print_error(6);
		return (free(*f), free(pv), 0);
	}
	return (1);
}

int	set_times(t_table **table, t_philosopher **philosophers, t_philovars *vars)
{
	int	philidx;

	(*table)->start_time = get_the_time();
	philidx = 0;
	while (philidx < vars->philo_num)
	{
		(*philosophers)[philidx].time_table = *table;
		(*philosophers)[philidx].last_meal_ms = (*table)->start_time;
		philidx++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philovars		*philovars;
	int				erroridx;
	t_philosopher	*phils;
	t_fork			*forks;
	t_table			*table;

	if (ac != 6 && ac != 5)
		return (print_error_args(), 1);
	philovars = NULL;
	parse_arguments(&philovars, av, ac);
	if (!philovars)
		return (print_error(7), 1);
	if (!check_arguments(philovars, &erroridx, av, ac))
		return (print_error(erroridx), free(philovars), 1);
	if (!innit_vars(philovars, &forks, &table, &phils)
		|| !set_times(&table, &phils, philovars))
		return (1);
	if (!start_threads(phils, philovars->philo_num, forks, table))
	{
		print_error(6);
		pthread_mutex_destroy(&table->write_lock);
		pthread_mutex_destroy(&table->simulation_lock);
		return (free(philovars), free(table), free(phils), free(forks), 1);
	}
	return (finish_routine(&philovars, &phils, &forks), free(table), 0);
}
