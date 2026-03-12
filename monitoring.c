/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:05:51 by htavares          #+#    #+#             */
/*   Updated: 2026/03/12 15:58:38 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_end_lock(t_philosopher *phil)
{
	pthread_mutex_lock(&phil->time_table->simulation_lock);
	if (phil->time_table->simulation_end)
	{
    	pthread_mutex_unlock(&phil->time_table->simulation_lock);
    	return (0);
	}
	pthread_mutex_unlock(&phil->time_table->simulation_lock);
	return (1);
}

static void	print_death(t_philosopher *phil)
{
	phil->state = DEAD;
	printstate(&phil);
	
}

void	*monitoring(void *philosophers)
{
	int				i;
	int				ate;
	t_philosopher	*phil;
	
	phil = (t_philosopher*)philosophers;
	while (check_end_lock(phil))
	{
		i = 0;
		while (i < phil->time_table->philo_num)
		{
			pthread_mutex_lock(&phil->time_table->write_lock);
			if (get_the_time() - (&phil[i])->last_meal_ms
				>= (&phil[i])->time_to_die)
			{
				pthread_mutex_lock(&phil->time_table->simulation_lock);
				phil->time_table->simulation_end = 1;
				pthread_mutex_unlock(&phil->time_table->simulation_lock);
				print_death(&(phil[i]));
				pthread_mutex_unlock(&phil->time_table->write_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&phil->time_table->write_lock);
			i++;
		}
		i = 0;
		ate = 1;
		if (phil->eat_max_num > -1)
		{
			while (i < phil->time_table->philo_num)
			{
				if ((&phil[i])->meals_taken
					< (unsigned int)(&phil[i])->eat_max_num)
				{
					ate = 0;
					break ;
				}
				i++;
			}
			if (ate)
			{
				pthread_mutex_lock(&phil->time_table->simulation_lock);
					phil->time_table->simulation_end = 1;
				pthread_mutex_unlock(&phil->time_table->simulation_lock);
				return (NULL);
			}
		}
		usleep(1000);
	}
	return (NULL);
}
