/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:02:47 by htavares          #+#    #+#             */
/*   Updated: 2025/11/27 18:00:07 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error(int erroridx)
{
	if (erroridx == 1)
		write(1, "invalid number of philosophers", 30);
	if (erroridx == 2)
		write(1, "invalid lifetime", 16);
	if (erroridx == 3)
		write(1, "invalid time to eat", 19);
	if (erroridx == 4)
		write(1, "invalid time to sleep", 21);
	if (erroridx == 5)
		write(1, "invalid number of eat times", 27);
	if (erroridx == 6)
		write(1, "program failed to initialize phils", 34);
	if (erroridx == 6)
		write(1, "program failed to initialize philvars", 37);
}

void	print_error_args()
{
	write (1, "Error, it's needed 5 Arguments\n", 31);
	write (1, "Args to pass: ", 14);
	write (1, "<phil.num> <time2die> <time2eat> ", 33);
	write (1, "<time2sleep> <num.times.eat>\n", 29);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 45)
	{
		sign *= -1;
		nptr++;
	}
	if (*nptr == 43 && sign > 0)
		nptr++;
	while (*nptr > 47 && *nptr < 58)
	{
		result *= 10;
		result += *nptr - 48;
		nptr++;
	}
	return (result * sign);
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 45)
	{
		sign *= -1;
		nptr++;
	}
	if (*nptr == 43 && sign > 0)
		nptr++;
	while (*nptr > 47 && *nptr < 58)
	{
		result *= 10;
		result += *nptr - 48;
		nptr++;
	}
	return (result * sign);
}
