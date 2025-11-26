/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:42:55 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 10:24:22 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c > 31) && (c < 127))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char c = 'j';

	printf("%d", ft_isprint(c));
	return (0);
}
*/
