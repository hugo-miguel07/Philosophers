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

void	freeall(t_philovars **pv, t_philosopher **p)
{
	if (*pv)
		free(*pv);
	if (*p)
		free(*p);;
}

void	destroymutex(int mutex_num, t_fork *f)
{
	int	i;
	
	i = 0;
	while (i < mutex_num)
	{
		pthread_mutex_destroy(&f[i].using);
		i++;
	}
}

void	jointhreads(int thread_num, t_philosopher **p)
{
	int	i;
	
	i = 0;
	while (i < thread_num)
	{
		pthread_join((*p)[i].thread, NULL);
		i++;
	}
}

void	finish_routine(t_philovars **pv, t_philosopher **p, t_fork **f)
{
	int	philo_num;

	philo_num = (*pv)->philo_num;
	jointhreads(philo_num, p);
	destroymutex(philo_num, *f);
	freeall(pv, p);
}