/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:46:28 by htavares          #+#    #+#             */
/*   Updated: 2025/12/04 17:21:14 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_the_time(void)
{
	long tempo_ms;
	long tempo_us;
	struct timeval *now;

	gettimeofday(now, NULL);
	tempo_ms = (now->tv_sec * 1000);
	tempo_us = (now->tv_usec / 1000);

	return (tempo_ms + tempo_us);
}