/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:42:41 by htavares          #+#    #+#             */
/*   Updated: 2025/11/26 12:48:38 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include "libft/libft.h"

typedef struct s_philovars
{
	int		philo_num;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		eat_max_num;
}	t_philovars;

typedef struct s_philosopher
{
	int			idx;		
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			eat_max_num;
	void		*fork;
	pthread_t	thread;
	
}	t_philosopher;

void	print_error_args();
void	print_encountered_error(int erroridx);

#endif