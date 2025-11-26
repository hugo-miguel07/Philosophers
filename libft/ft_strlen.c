/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htavares <htavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:53:02 by htavares          #+#    #+#             */
/*   Updated: 2025/04/14 12:49:42 by htavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	return (size);
}
/*
#include <stdio.h>
int	main(void)
{
	char *c = "Quarenta";

	printf("%d", ft_strlen(c));
	return (0);
}
*/
