/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:42:41 by htavares          #+#    #+#             */
/*   Updated: 2025/11/27 18:52:12 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define SLEEPING 1
# define EATING 2
# define THINKING 3
# define FORKING 4
# define DEAD 5

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philovars
{
	int		philo_num;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		eat_max_num;
}	t_philovars;

typedef struct s_fork
{
	int				forkidx;
	pthread_mutex_t	using;
}	t_fork;

typedef struct s_philosopher
{
	int			idx;		
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			eat_max_num;
	int			state;
	t_table 	*time_table;
	t_fork		*fork;
	pthread_t	thread;
	
}	t_philosopher;

typedef struct s_table
{
	long long		*start_time;
	int				*philo_num;
	t_fork			*forks;
	pthread_mutex_t	*write_lock;
	int				simulation_end;
}	t_table;

void		print_error_args();
void		print_error(int erroridx);
long		ft_atol(const char *nptr);
int			ft_atoi(const char *nptr);
void		*routine(void *philosopher);
void		finish_routine(t_philovars **pv, t_philosopher **p, t_fork **f);
void		destroymutex(int mutex_num, t_fork *f);
long long	get_the_time(void);

#endif