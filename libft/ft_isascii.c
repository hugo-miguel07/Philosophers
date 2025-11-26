/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:30:59 by htavares          #+#    #+#             */
/*   Updated: 2025/04/17 10:24:03 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c < 128) && (c >= 0))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char c = '{';

	printf("%d", ft_isascii(c));
	return (0);
}
*/
