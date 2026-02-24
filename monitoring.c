/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:05:51 by htavares          #+#    #+#             */
/*   Updated: 2026/02/24 13:39:28 by htavares         ###   ########.fr       */
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

void	*monitoring(void *philosophers)
{
	(void)philosophers;
	//loop infinito que verifica continuamente
	//calcula para cada se passou o tempo para morrer
	//    agora - last_meal_ms >= time_to_die
	//verifica se todos terminaram as refeicoes (se necessario)
	//se alguem morrer setar simulation_end a 1 e lockar
	//mini usleep(1000) no final para nao comer recursos do CPU
	//ATENCAO
	//simulation_end tem mm de usar o simulation_lock para evitar racing cond.
	return (NULL);
}