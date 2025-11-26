/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:31:20 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 13:55:36 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	*nptr = " 23b1";
	
	printf("original atoi: %d\n", atoi(nptr));
	printf("my atoi: %d", ft_atoi(nptr));
	return (0);
}
*/
