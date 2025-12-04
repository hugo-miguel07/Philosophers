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

void	sleeping()
{
	//libertas os forks
	//usleep do tempo de dormir
	//enviar sinal que está a dormir	
}

void	eating()
{
	//aceder aos forks
	//usleep do tempo de comer
	//enviar sinal que está a comer
}

void	thinking()
{
	//enviar sinal que está a pensar
	usleep(100);
}

void	*routine(void *philosopher)
{
	t_philosopher	*phil;
	int				times_to_eat;

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
		thinking();
		eating();
		if (times_to_eat > 0)
			times_to_eat--;
		if (times_to_eat == 0)
			break ;
		sleeping();
	}
	//flag para acabar todas as outras threads
	return (NULL);
}
