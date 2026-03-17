/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishsim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:44:28 by htavares          #+#    #+#             */
/*   Updated: 2025/11/27 18:59:53 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	freeall(t_philovars **pv, t_philosopher **p, t_fork **f)
{
	if (pv && *pv)
	{
		free(*pv);
		*pv = NULL;
	}
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
	if (f && *f)
	{
		free(*f);
		*f = NULL;
	}
}

void	destroymutex(int mutex_num, t_fork *f)
{
	int	i;

	if (!f)
		return ;
	i = 0;
	while (i < mutex_num)
	{
		pthread_mutex_destroy(&(f[i]).using);
		i++;
	}
}

void	jointhreads(int thread_num, t_philosopher **p)
{
	int	i;

	if (!p || !*p)
		return ;
	i = 0;
	while (i < thread_num)
	{
		pthread_join((*p)[i].thread, NULL);
		i++;
	}
	pthread_join((*p)->time_table->monitor_thread, NULL);
}

void	finish_routine(t_philovars **pv, t_philosopher **p, t_fork **f)
{
	int	philo_num;

	if (!pv || !*pv)
		return ;
	philo_num = (*pv)->philo_num;
	jointhreads(philo_num, p);
	if (f && *f)
		destroymutex(philo_num, *f);
	pthread_mutex_destroy(&(*p)->time_table->write_lock);
	pthread_mutex_destroy(&(*p)->time_table->simulation_lock);
	freeall(pv, p, f);
}
