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

t_fork	*innit_forks(int forknum)
{
	t_fork	*forks;
	int 	i;
	
	if (forknum < 1)
		return (NULL);
	forks = malloc(forknum * sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < forknum)
	{
		forks[i].forkidx = i;
		if (pthread_mutex_init(&(forks[i].using), NULL) != 0)
			return (destroymutex(i, forks), free(forks), NULL);
		i++;
	}
	return (forks);	
}

t_philosopher	*innit_phils(t_philovars *philovars, t_fork *forks)
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
		philosophers[i].fork = &forks[i];
		if (pthread_create(&philosophers[i].thread, NULL, routine, (void *)&philosophers[i]) != 0)
			return (free(philosophers), NULL);
		i++;
	}
	return (philosophers);
}

int	main(int ac, char **av)
{
	t_philovars 	*philovars;
	int				erroridx;
	t_philosopher	*philosophers;
	t_fork			*forks;
	
	if (ac != 6)
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
	forks = innit_forks(philovars->philo_num);
	if (!forks)
		return (free(philovars), print_error(7), 1);
	philosophers = innit_phils(philovars, forks);
	if (!philosophers)
		return (destroymutex(philovars->philo_num ,forks), free(forks), free(philovars), print_error(6), 1);
	finish_routine(&philovars, &philosophers, &forks);
	return (0);
}
