/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:54:19 by htavares          #+#    #+#             */
/*   Updated: 2026/03/17 12:54:51 by htavares         ###   ########.fr       */
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
		printf("%lld philosopher%d is thinking\n", time_now, phil->idx + 1);
	else if ((phil->state == FORKINGLEFT || phil->state == FORKINGRIGHT)
		&& phil->time_table->simulation_end == 0)
		printf("%lld philosopher%d has taken a fork\n", time_now,
			phil->idx + 1);
	else if (phil->state == EATING && phil->time_table->simulation_end == 0)
		printf("%lld philosopher%d is eating\n", time_now, phil->idx + 1);
	else if (phil->state == SLEEPING && phil->time_table->simulation_end == 0)
		printf("%lld philosopher%d is sleeping\n", time_now, phil->idx + 1);
	else if (phil->state == DEAD)
		printf("%lld philosopher%d is dead\n", time_now, phil->idx + 1);
	pthread_mutex_unlock(&phil->time_table->simulation_lock);
}
