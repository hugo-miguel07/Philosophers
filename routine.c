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
	t_philosopher	*phil;
	long long		time_now;

	phil = *philosopher;
	time_now = get_the_time() - phil->time_table->start_time;
	if (phil->state == THINKING)
	{
		printf("%lld philosopher%d is thinking\n", time_now, phil->idx);
	}
	else if (phil->state == FORKINGLEFT || phil->state == FORKINGRIGHT)
	{
		printf("%lld philosopher%d has taken a fork\n", time_now, phil->idx);
	}
	else if (phil->state == EATING)
	{
		printf("%lld philosopher%d is eating\n", time_now, phil->idx);
	}
	else if (phil->state == SLEEPING)
	{
		printf("%lld philosopher%d is sleeping\n", time_now, phil->idx);
	}
}

void	sleeping(t_philosopher **philosopher)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	phil->state = SLEEPING;
	usleep(phil->time_to_sleep);
	printstate(philosopher);	
}

void	eating(t_philosopher **philosopher)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	pthread_mutex_lock(&phil->left_fork->using);
	phil->state = FORKINGLEFT;
	printstate(philosopher);
	pthread_mutex_lock(&phil->right_fork->using);
	phil->state = FORKINGRIGHT;
	printstate(philosopher);
	phil->state = EATING;
	printstate(philosopher);
	usleep(phil->time_to_eat);
	pthread_mutex_unlock(&phil->right_fork->using);
	pthread_mutex_unlock(&phil->left_fork->using);
	phil->last_meal_ms = get_the_time();
	phil->meals_taken++;
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
		if (!check_end_lock(phil))
			break ;
		thinking(&phil);
		if (!check_end_lock(phil))
			break ;
		eating(&phil);
		if (times_to_eat > 0)
			times_to_eat--;
		if (times_to_eat == 0)
			break ;
		if (!check_end_lock(phil))
			break ;
		sleeping(&phil);
	}
	return (NULL);
}
