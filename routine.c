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
	pthread_mutex_lock(&phil->time_table->simulation_lock);
	if (phil->state == THINKING && phil->time_table->simulation_end == 0)
		printf("%lld philosopher%d is thinking\n", time_now, phil->idx  + 1);
	else if ((phil->state == FORKINGLEFT || phil->state == FORKINGRIGHT)
			&& phil->time_table->simulation_end == 0)
		printf("%lld philosopher%d has taken a fork\n", time_now
				, phil->idx + 1);
	else if (phil->state == EATING && phil->time_table->simulation_end == 0)
		printf("%lld philosopher%d is eating\n", time_now, phil->idx  + 1);
	else if (phil->state == SLEEPING && phil->time_table->simulation_end == 0)
		printf("%lld philosopher%d is sleeping\n", time_now, phil->idx  + 1);
	else if (phil->state == DEAD)
		printf("%lld philosopher%d is dead\n", time_now, phil->idx + 1);
	pthread_mutex_unlock(&phil->time_table->simulation_lock);
}

void	sleeping(t_philosopher **philosopher)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	phil->state = SLEEPING;
	pthread_mutex_lock(&phil->time_table->write_lock);
	printstate(philosopher);
	pthread_mutex_unlock(&phil->time_table->write_lock);
	usleep(phil->time_to_sleep * 1000);
}

void	eating(t_philosopher **philosopher)
{
	t_philosopher	*phil;
	t_fork			*first_fork;
	t_fork			*second_fork;

	phil = *philosopher;
	if (phil->left_fork->forkidx < phil->right_fork->forkidx)
	{
		first_fork = phil->left_fork;
		second_fork = phil->right_fork;
	}
	else
	{
		first_fork = phil->right_fork;
		second_fork = phil->left_fork;
	}
	pthread_mutex_lock(&first_fork->using);
	phil->state = FORKINGLEFT;
	pthread_mutex_lock(&phil->time_table->write_lock);
	printstate(philosopher);
	pthread_mutex_unlock(&phil->time_table->write_lock);
	if (first_fork == second_fork)
	{
		while (check_end_lock(phil))
			usleep(500);
		pthread_mutex_unlock(&first_fork->using);
		return ;
	}
	pthread_mutex_lock(&second_fork->using);
	phil->state = FORKINGRIGHT;
	pthread_mutex_lock(&phil->time_table->write_lock);
	printstate(philosopher);
	pthread_mutex_unlock(&phil->time_table->write_lock);
	phil->state = EATING;
	pthread_mutex_lock(&phil->time_table->write_lock);
	printstate(philosopher);
	pthread_mutex_unlock(&phil->time_table->write_lock);
	pthread_mutex_lock(&phil->time_table->write_lock);
	phil->last_meal_ms = get_the_time();
	phil->meals_taken++;
	pthread_mutex_unlock(&phil->time_table->write_lock);
	usleep(phil->time_to_eat * 1000);
	pthread_mutex_unlock(&second_fork->using);
	pthread_mutex_unlock(&first_fork->using);
}

void	thinking(t_philosopher **philosopher)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	phil->state = THINKING;
	pthread_mutex_lock(&phil->time_table->write_lock);
	printstate(philosopher);
	pthread_mutex_unlock(&phil->time_table->write_lock);
	if (phil->idx % 2 == 0)
		usleep(1000);
	else
		usleep(1500);
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
