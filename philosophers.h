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
# define FORKINGLEFT 4
# define FORKINGRIGHT 5
# define DEAD 6

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

typedef struct s_table
{
	long long		start_time;
	int				philo_num;
	t_fork			*forks;
	pthread_mutex_t	write_lock;
	int				simulation_end;
	pthread_t		monitor_thread;
	pthread_mutex_t	simulation_lock;
}	t_table;

typedef struct s_philosopher
{
	int				idx;		
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				eat_max_num;
	int				state;
	unsigned int	meals_taken;
	long long		last_meal_ms;
	t_table 		*time_table;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread;
	
}	t_philosopher;

t_table			*innit_table(t_fork *forks, int philnum);
t_fork			*innit_forks(int forknum);
t_philosopher	*innit_phils(t_philovars *philovars, t_fork *forks, t_table *table);
int				start_threads(t_philosopher *philosophers, int count, t_fork *forks, t_table *table);
void			print_error_args();
void			print_error(int erroridx);
long			ft_atol(const char *nptr);
int				ft_atoi(const char *nptr);
int				is_number(const char *nptr);
int				check_end_lock(t_philosopher *phil);
void			*routine(void *philosopher);
void			*monitoring(void *philosophers);
void			finish_routine(t_philovars **pv, t_philosopher **p, t_fork **f);
void			destroymutex(int mutex_num, t_fork *f);
void			printstate(t_philosopher **philosopher);
long long		get_the_time(void);

#endif