/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:15:31 by htavares          #+#    #+#             */
/*   Updated: 2026/03/12 15:59:16 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*innit_table(t_fork *forks, int philnum)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->forks = forks;
	table->philo_num = philnum;
	table->simulation_end = 0;
	table->start_time = 0;
	if (pthread_mutex_init(&table->write_lock, NULL) != 0)
		return (free(table), NULL);
	if (pthread_mutex_init(&table->simulation_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&table->write_lock);
		return (free(table), NULL);
	}
	return (table);
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

t_philosopher	*innit_phils(t_philovars *philovars, t_fork *forks, t_table *table)
{
	int 			i;
	t_philosopher	*philosophers;

	if (!philovars || !table)
		return (NULL);
	philosophers = malloc(philovars->philo_num * sizeof(t_philosopher));
	if (!philosophers)
		return (NULL);
	i = -1;
	while (++i < philovars->philo_num)
	{
		philosophers[i].idx = i;
		philosophers[i].time_to_die = philovars->time_to_die;
		philosophers[i].time_to_eat = philovars->time_to_eat;
		philosophers[i].time_to_sleep = philovars->time_to_sleep;
		philosophers[i].eat_max_num = philovars->eat_max_num;
		philosophers[i].last_meal_ms = 0;
		philosophers[i].time_table = table;
		philosophers[i].meals_taken = 0;
		philosophers[i].left_fork = &forks[i];
		philosophers[i].right_fork = &forks[(i + 1) % philovars->philo_num];
		philosophers[i].state = THINKING;
	}
	return (philosophers);
}

int	start_threads(t_philosopher *philosophers, int count, t_fork *forks, t_table *table)
{
	int	i;

	if (!philosophers || count <= 0)
		return (0);
	i = -1;
	while (++i < count)
	{
		if (pthread_create(&philosophers[i].thread, NULL, routine, (void *)&philosophers[i]))
		{
			while (--i >= 0)
				pthread_join(philosophers[i].thread, NULL);
			destroymutex(count, forks);
			return (0);
		}
	}
	if (pthread_create(&table->monitor_thread, NULL, monitoring, (void *)philosophers))
	{
		while (--i >= 0)
			pthread_join(philosophers[i].thread, NULL);
		destroymutex(count, forks);
		return (0);
	}
	return (1);
}
