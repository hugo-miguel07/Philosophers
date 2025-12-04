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
		printf("%d philosopher%d is thinking");
	}
	else if (phil->state == EATING)
	{
		printf("%d philosopher%d is eating");
	}
	else if (phil->state == SLEEPING)
	{
		printf("%d philosopher%d is sleeping");
	}
}

void	sleeping(t_philosopher **philosopher, struct timeval *now)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	phil->state = SLEEPING;
	//libertas os forks
	//usleep do tempo de dormir
	//enviar sinal que está a dormir	
}

void	eating(t_philosopher **philosopher, struct timeval *now)
{
	t_philosopher *phil;
	
	phil = *philosopher;
	phil->state = EATING;
	//aceder aos forks
	//printar que pegou nos garfos
	//usleep do tempo de comer
	//enviar sinal que está a comer
}

void	thinking(t_philosopher **philosopher, struct timeval *now)
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
	struct timeval	*now;

	phil = (t_philosopher *)philosopher;
	if (!phil)
		return (NULL);
	//ideia depois para os prints:
	//	a struct phil pode ter mais 1 variavel
	//	que representa o estado em que se encontram.
	//	esse estado vai ser atualizado e printado quando
	//	entrarem noutra função de execução
	//	(thinking, eating, sleeping)
	times_to_eat = phil->eat_max_num;
	while (times_to_eat)
	{
		thinking(&phil, now);
		eating(&phil, now);
		if (times_to_eat > 0)
			times_to_eat--;
		if (times_to_eat == 0)
			break ;
		sleeping(&phil, now);
	}
	//flag para acabar todas as outras threads
	return (NULL);
}
