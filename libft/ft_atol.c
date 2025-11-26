/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:59 by htavares          #+#    #+#             */
/*   Updated: 2025/11/25 12:43:58 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int main(void)
{
	char *x = "4000000000aa";
	long l = ft_atol(x);
	printf("%lu", l);
	return (0);
}*/