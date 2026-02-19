/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:33:18 by htavares          #+#    #+#             */
/*   Updated: 2025/11/27 18:59:44 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printstate(t_philosopher **philosopher)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	if (phil->state == THINKING)
	{
		printf("%lld philosopher%d is thinking\n", phil->time_now, phil->idx);
	}
	if (phil->state == FORKING)
	{
		printf("%lld philosopher%d has taken a fork\n", phil->time_now, phil->idx);
	}
	else if (phil->state == EATING)
	{
		printf("%lld philosopher%d is eating\n", phil->time_now, phil->idx);
	}
	else if (phil->state == SLEEPING)
	{
		printf("%lld philosopher%d is sleeping\n", phil->time_now, phil->idx);
	}
}

void	sleeping(t_philosopher **philosopher)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	phil->state = SLEEPING;
	//libertas os forks
	//usleep do tempo de dormir
	//enviar sinal que está a dormir	
}

void	eating(t_philosopher **philosopher)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	pthread_mutex_lock(&phil->fork->using);
	phil->state = FORKING;
	printstate(philosopher);
	phil->state = EATING;
	printstate(philosopher);
	usleep(phil->time_to_eat);
	pthread_mutex_unlock(&phil->fork->using);
}

void	thinking(t_philosopher **philosopher)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	phil->state = THINKING;
	usleep(100);
}

void	*routine(void *philosopher)
{
	t_philosopher	*phil;
	int				times_to_eat;

	phil = (t_philosopher *)philosopher;
	if (!phil)
		return (NULL);
	times_to_eat = phil->eat_max_num;
	while (times_to_eat)
	{
		thinking(&phil);
		eating(&phil);
		if (times_to_eat > 0)
			times_to_eat--;
		if (times_to_eat == 0)
			break ;
		sleeping(&phil);
	}
	//flag para acabar todas as outras threads
	return (NULL);
}
